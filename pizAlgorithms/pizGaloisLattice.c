/*
 * \file    pizGaloisLattice.c
 * \author  Jean Sapristi
 * \date    31 janvier 2012
 */
 
/*
 *  Copyright (c) 2011, Jean Sapristi & Tom Javel, 
 *  "nicolas.danet@free.fr".
 *
 *  This software is governed by the CeCILL-C license under French law and
 *  abiding by the rules of distribution of free software. You can use, 
 *  modify and/or redistribute the software under the terms of the CeCILL-C
 *  license as circulated by CEA, CNRS and INRIA at the following URL
 *  "http://www.cecill.info". 
 *
 *  As a counterpart to the access to the source code and rights to copy,
 *  modify and redistribute granted by the license, users are provided only
 *  with a limited warranty  and the software's author, the holder of the
 *  economic rights, and the successive licensors have only limited
 *  liability. 
 *
 *  In this respect, the user's attention is drawn to the risks associated
 *  with loading, using, modifying and/or developing or reproducing the
 *  software by the user in light of its specific status of free software,
 *  that may mean that it is complicated to manipulate, and that also
 *  therefore means that it is reserved for developers and experienced
 *  professionals having in-depth computer knowledge. Users are therefore
 *  encouraged to load and test the software's suitability as regards their
 *  requirements in conditions enabling the security of their systems and/or 
 *  data to be ensured and, more generally, to use and operate it in the 
 *  same conditions as regards security. 
 *  
 *  The fact that you are presently reading this means that you have had
 *  knowledge of the CeCILL-C license and that you accept its terms.
 */

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#include "pizGaloisLattice.h"

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#include <stdlib.h>
#include <math.h>   
#include <time.h>

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#define PIZ_TICKET_MACHINE_SIZE                     126
#define PIZ_GROWING_ARRAY_INIT_SIZE                 4

#define PIZ_MAXIMUM_THRESHOLD_TO_KILL_CONCEPTS      100
#define PIZ_DEFAULT_THRESHOLD_TO_KILL_CONCEPTS      50

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

PIZGaloisLattice *pizGaloisLatticeNew (long argc, long *argv)
{
    PIZGaloisLattice *x = NULL;

    if (x = (PIZGaloisLattice *)calloc (1, sizeof(PIZGaloisLattice)))
        {
            long err = PIZ_GOOD;
            
            if (x->stock = (PIZGaloisLatticeConcept *)calloc (PIZ_ITEMSET128_SIZE, 
                sizeof(PIZGaloisLatticeConcept)))
                {
                    long i;
                    
                    x->thresholdToKillConcepts  = PIZ_DEFAULT_THRESHOLD_TO_KILL_CONCEPTS;
                    x->targetedConcept          = -1;
                    x->shuttle                  = -1;
                    x->previousShuttle          = -1;
                    
                    srand ((unsigned int)time(NULL));
                        
                    if (argc && ((argv[0] > 0)  && (argv[0] <= PIZ_MAXIMUM_THRESHOLD_TO_KILL_CONCEPTS))) {
                            x->thresholdToKillConcepts = argv[0];
                        }
                    
                    for (i = 0; i < PIZ_ITEMSET128_SIZE; i++) {
                            pizItemset128SetAtIndex (&(x->stock[1].itemset), i);
                        }
                    
                    x->stock[0].cardinal = 0;
                    x->stock[1].cardinal = PIZ_ITEMSET128_SIZE;
                    
                    pizItemset128SetAtIndex (&(x->stock[0].childs), 1);
                    pizItemset128SetAtIndex (&(x->stock[1].parents), 0);
                    
                    if (x->ticketMachine = pizBoundedStackNew (PIZ_TICKET_MACHINE_SIZE)) {
                            for (i = (PIZ_ITEMSET128_SIZE - 1); i > 1; i--) {
                                    pizBoundedStackPush (x->ticketMachine, i);
                                }
                        }
                    else
                        {
                            err = PIZ_MEMORY;
                        }
                        
                    if (x->mapByCardinal = (PIZGrowingArray **)malloc ((PIZ_ITEMSET128_SIZE + 1) 
                        * sizeof(PIZGrowingArray *))) {
                            for (i = 0; i < (PIZ_ITEMSET128_SIZE + 1); i++) {
                                if (!(x->mapByCardinal[i] = pizGrowingArrayNew (PIZ_GROWING_ARRAY_INIT_SIZE))) {
                                        err = PIZ_MEMORY;
                                    }
                                }
                        }
                    else
                        {
                            err = PIZ_MEMORY;
                        }
                    
                    if (x->tempMapByCardinal = (PIZGrowingArray **)malloc ((PIZ_ITEMSET128_SIZE + 1) 
                        * sizeof(PIZGrowingArray *))) {
                            for (i = 0; i < (PIZ_ITEMSET128_SIZE + 1); i++) {
                                if (!(x->tempMapByCardinal[i] 
                                    = pizGrowingArrayNew (PIZ_GROWING_ARRAY_INIT_SIZE))) {
                                        err = PIZ_MEMORY;
                                    }
                                }
                        }
                    else
                        {
                            err = PIZ_MEMORY;
                        }
                    
                    if (!err) {
                            err |= pizGrowingArrayAppend (x->mapByCardinal[0], 0);
                            err |= pizGrowingArrayAppend (x->mapByCardinal[PIZ_ITEMSET128_SIZE], 1);
                        }
                    
                    if (err) {
                            pizGaloisLatticeFree (x);
                            x = NULL;
                        }
                }
            else
                {
                    free (x);
                    x = NULL;
                }
        }
    
    return x;
}

void pizGaloisLatticeFree (PIZGaloisLattice *x)
{
    if (x)
        {
            if (x->mapByCardinal)
                {
                    long i;

                    for (i = 0; i < (PIZ_ITEMSET128_SIZE + 1); i++) {
                            pizGrowingArrayFree (x->mapByCardinal[i]);
                            x->mapByCardinal[i] = NULL;
                        }
                    
                    free (x->mapByCardinal);
                    x->mapByCardinal = NULL;
                }
            
            if (x->tempMapByCardinal)
                {
                    long i;

                    for (i = 0; i < (PIZ_ITEMSET128_SIZE + 1); i++) {
                            pizGrowingArrayFree (x->tempMapByCardinal[i]);
                            x->tempMapByCardinal[i] = NULL;
                        }
                    
                    free (x->tempMapByCardinal);
                    x->tempMapByCardinal = NULL;
                }

            pizBoundedStackFree (x->ticketMachine);
            x->ticketMachine = NULL;
            
            free (x->stock);
            x->stock = NULL;
            
            free (x);
        }
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

PIZError pizGaloisLatticeAdd (PIZGaloisLattice *x, long argc, long *argv)
{
    long i;
    long err = PIZ_ERROR;
    
    pizItemset128Clear (&(x->itemsetToBeAdded));
    
    if (argv && (argc > 0))
        {
            long j;
    
            for (j = 0; j < argc; j++)
                {
                    if ((argv[j] >= 0) && (argv[j] < PIZ_ITEMSET128_SIZE)) {
                            pizItemset128SetAtIndex (&(x->itemsetToBeAdded), argv[j]);
                        }
                }
            
            err = PIZ_GOOD;
        }

    pizGrowingArrayClear (x->tempMapByCardinal[0]);
    pizGrowingArrayClear (x->tempMapByCardinal[PIZ_ITEMSET128_SIZE]);
    
    for (i = 1; i <= x->tempMapByCardinalPeak; i++) {
            pizGrowingArrayClear (x->tempMapByCardinal[i]);
        }
    
    x->tempMapByCardinalPeak = 0;
    
    for (i = 0; i < (PIZ_ITEMSET128_SIZE + 1); i++)
        {
            long j;
            
            for (j = 0; j < pizGrowingArrayCount (x->mapByCardinal[i]); j++)
                {   
                    long g = pizGrowingArrayValueAtIndex (x->mapByCardinal[i], j);
                    
                    if (pizItemset128IsEqual (&(x->stock[g].itemset), 
                        &(x->itemsetToBeAdded)))
                        {
                            goto end;
                        }
                    else if (pizItemset128IsIncluded (&(x->stock[g].itemset), 
                        &(x->itemsetToBeAdded)))
                        {
                            if (pizGrowingArrayAppend (x->tempMapByCardinal[i], g))
                                {
                                    err = PIZ_MEMORY;
                                }
                            else
                                {
                                    if (i > x->tempMapByCardinalPeak) {
                                            x->tempMapByCardinalPeak = i;
                                        }
                                }
                        }
                    else
                        {
                            long generator = false;
                            
                            pizItemset128Intersection (&(x->stock[g].itemset), &(x->itemsetToBeAdded),
                                &(x->itemsetIntersection));
                                
                            if (x->itemsetIntersectionCardinal = pizItemset128Count (&(x->itemsetIntersection)))
                                {
                                    long t;
                                    
                                    generator = true;
                                    
                                    for (t = 0; t < pizGrowingArrayCount (x->tempMapByCardinal
                                        [x->itemsetIntersectionCardinal]); t++)
                                        {
                                            long p;
                                            
                                            p = pizGrowingArrayValueAtIndex (x->tempMapByCardinal
                                                [x->itemsetIntersectionCardinal], t);
                                            
                                            if (pizItemset128IsEqual (&(x->stock[p].itemset),
                                                &(x->itemsetIntersection))) {
                                                    generator = false;
                                                }
                                        }
                                }
                            
                            if (generator)
                                {
                                    if (!pizBoundedStackPop (x->ticketMachine))
                                        {
                                            long n = pizBoundedStackPoppedValue (x->ticketMachine);
                                            
                                            if (pizGrowingArrayAppend (x->tempMapByCardinal
                                                [x->itemsetIntersectionCardinal], n))
                                                {
                                                    pizBoundedStackPush (x->ticketMachine, n);
                                                    err = PIZ_MEMORY;
                                                }
                                            else
                                                {
                                                    x->stock[n].cardinal = x->itemsetIntersectionCardinal;
                                                    x->stock[n].itemset = x->itemsetIntersection;
                                            
                                                    x->count ++;
                                                    x->needToMakeMap = true;
                                            
                                                    if (x->itemsetIntersectionCardinal > 
                                                        x->tempMapByCardinalPeak) 
                                                        {
                                                            x->tempMapByCardinalPeak = 
                                                                x->itemsetIntersectionCardinal;
                                                        }
                                                    
                                                    pizItemset128SetAtIndex (&(x->stock[n].childs), g);
                                                    pizItemset128SetAtIndex (&(x->stock[g].parents), n);
                                                    
                                                    pizGaloisLatticeReconnect (x, g, n);
                                                    
                                                    if (pizItemset128IsEqual (&(x->itemsetIntersection),
                                                        &(x->itemsetToBeAdded)))
                                                        {
                                                            goto end;
                                                        }
                                                }
                                        }
                                }
                        }
                }
        }
        
end:
    
    if (x->needToMakeMap)
        {
            err |= pizGaloisLatticeMakeMap (x);
            
            while (x->count > x->thresholdToKillConcepts) {
                    pizGaloisLatticeKillConcept (x, x->targetedConcept);
                    pizGaloisLatticeMakeMap (x);
                }
        
            if (!x->count) {
                    pizItemset128SetAtIndex (&(x->stock[0].childs), 1);
                    pizItemset128SetAtIndex (&(x->stock[1].parents), 0);
                }
            
            x->needToMakeMap = false;
        }

    return err;
}

void pizGaloisLatticeClear (PIZGaloisLattice *x)
{
    long i;
    
    for (i = 1; i <= x->mapByCardinalPeak; i++) {
            pizGrowingArrayClear (x->mapByCardinal[i]);
        }
        
    x->mapByCardinalPeak = 0;
    
    pizItemset128Clear (&(x->stock[0].childs));
    pizItemset128Clear (&(x->stock[1].parents));
    
    pizItemset128SetAtIndex (&(x->stock[0].childs), 1);
    pizItemset128SetAtIndex (&(x->stock[1].parents), 0);
                    
    for (i = 2; i < PIZ_ITEMSET128_SIZE; i++)
        {
            if (x->stock[i].cardinal) {
                    x->stock[i].cardinal = 0;
                    pizItemset128Clear (&(x->stock[i].itemset));
                    pizItemset128Clear (&(x->stock[i].childs));
                    pizItemset128Clear (&(x->stock[i].parents));
                }
        }
    
    pizBoundedStackClear (x->ticketMachine);
                                
    for (i = (PIZ_ITEMSET128_SIZE - 1); i > 1; i--) {
            pizBoundedStackPush (x->ticketMachine, i);
        }
        
    x->count            = 0;
    x->shuttle          = -1;
    x->previousShuttle  = -1;
}

PIZError pizGaloisLatticeProceed (PIZGaloisLattice *x, long argc, long *argv)
{
    long err = PIZ_ERROR;
    
    if ((argc > 0 && argv) && (x->count > 0))
        {
            long k = 0;
            
            if (x->shuttle == -1) {
                    x->shuttle          = x->targetedConcept;
                    x->previousShuttle  = x->targetedConcept;
                }
            
            while (argc)
                {
                    long i;
                    long indexConnections = 0;
                    long connections[PIZ_ITEMSET128_SIZE];
                    
                    if (x->shuttle > 1)
                        {
                            long j;
                            long t = (long)(PIZ_ITEMSET128_SIZE * (rand ( ) / (RAND_MAX + 1.0)));
                                                        
                            for (j = 0; j < PIZ_ITEMSET128_SIZE; j++)
                                {
                                    if (pizItemset128IsSetAtIndex (&(x->stock[x->shuttle].itemset),
                                        (t + j) % PIZ_ITEMSET128_SIZE))
                                        {
                                            if (argc) {
                                                    argv[k] = (t + j) % PIZ_ITEMSET128_SIZE;
                                                    
                                                    argc --;
                                                    k ++;
                                                }
                                        }
                                }
                        }
                    
                    for (i = 0; i < PIZ_ITEMSET128_SIZE; i++)
                        {
                            if (pizItemset128IsSetAtIndex (&(x->stock[x->shuttle].childs), i) || 
                                pizItemset128IsSetAtIndex (&(x->stock[x->shuttle].parents), i))
                                {
                                    connections[indexConnections] = i;
                                    indexConnections ++;
                                }
                        }
                    
                    if (x->shuttle < 2)
                        {
                            x->previousShuttle = x->shuttle;
                            x->shuttle = connections[(long)(indexConnections * (rand ( ) / (RAND_MAX + 1.0)))];
                        }
                    else
                        {
                            long n;
                            
                            do {        
                            n = connections[(long)(indexConnections * (rand ( ) / (RAND_MAX + 1.0)))];
                            } while (n == x->previousShuttle);
                            
                            x->previousShuttle = x->shuttle;
                            x->shuttle = n;
                        }
                }
                
            err = PIZ_GOOD;
        }
    
    return err;
}

long pizGaloisLatticeCount (const PIZGaloisLattice *x)
{
    return (x->count);
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

PIZ_INLINE void pizGaloisLatticeReconnect (PIZGaloisLattice *x, long g, long n)
{
    long i;
    
    for (i = 0; i < x->itemsetIntersectionCardinal; i++)
        {
            long j;
            
            for (j = 0; j < pizGrowingArrayCount (x->tempMapByCardinal[i]); j++)
                {
                    long p = pizGrowingArrayValueAtIndex (x->tempMapByCardinal[i], j);
                    
                    if (pizItemset128IsIncluded (&(x->stock[p].itemset), &(x->itemsetIntersection)))
                        {
                            long t;
                            long isParentOfGenerator = true;
                            
                            for (t = 0; t < PIZ_ITEMSET128_SIZE; t++)
                                {
                                    if (pizItemset128IsSetAtIndex (&(x->stock[p].childs), t))
                                        {
                                            if (pizItemset128IsIncluded (&(x->stock[t].itemset),
                                                &(x->itemsetIntersection)))
                                                {
                                                    isParentOfGenerator = false;
                                                    break;
                                                }
                                        }
                                }
                            
                            if (isParentOfGenerator) {
                                    pizItemset128UnsetAtIndex   (&(x->stock[g].parents),    p);
                                    pizItemset128UnsetAtIndex   (&(x->stock[p].childs),     g);
                                    pizItemset128SetAtIndex     (&(x->stock[n].parents),    p);
                                    pizItemset128SetAtIndex     (&(x->stock[p].childs),     n);
                                }
                        }
                }
        }
}

PIZError pizGaloisLatticeMakeMap (PIZGaloisLattice *x)
{
    long i;
    long j = 0;
    long err = PIZ_GOOD;
    long k = -1;
    
    x->targetedConcept = -1;
    
    if (x->count) {
            k = (long)(x->count * (rand ( ) / (RAND_MAX + 1.0)));
        }
    
    for (i = 1; i <= x->mapByCardinalPeak; i++) {
            pizGrowingArrayClear (x->mapByCardinal[i]);
        }
    
    x->mapByCardinalPeak = 0;
        
    for (i = 2; i < PIZ_ITEMSET128_SIZE; i++)
        {
            if (x->stock[i].cardinal)
                {
                    if (x->stock[i].cardinal > x->mapByCardinalPeak) {
                            x->mapByCardinalPeak = x->stock[i].cardinal;
                        }
                    
                    err |= pizGrowingArrayAppend (x->mapByCardinal[x->stock[i].cardinal], i);
                    
                    if (k == j) {
                            x->targetedConcept = i;
                        }
                        
                    j ++;
                }
        }
    
    return err;
}

void pizGaloisLatticeKillConcept (PIZGaloisLattice *x, long n)
{
    if (n > 1)
        {
            long i;
                
            for (i = 0; i < PIZ_ITEMSET128_SIZE; i++)
                {
                    if (pizItemset128IsSetAtIndex (&(x->stock[n].parents), i))
                        {
                            pizItemset128UnsetAtIndex (&(x->stock[i].childs), n);
                            pizItemset128UnsetAtIndex (&(x->stock[n].parents), i);
                            
                            if (pizItemset128Count (&(x->stock[i].childs)) == 0) {
                                    pizGaloisLatticeKillConcept (x, i);
                                }
                        }
                    
                    if (pizItemset128IsSetAtIndex (&(x->stock[n].childs), i))
                        {
                            pizItemset128UnsetAtIndex (&(x->stock[i].parents), n);
                            pizItemset128UnsetAtIndex (&(x->stock[n].childs), i);
                            
                            if (pizItemset128Count (&(x->stock[i].parents)) == 0) {
                                    pizGaloisLatticeKillConcept (x, i);
                                }
                        }
                }
            
            x->stock[n].cardinal = 0;
            pizItemset128Clear (&(x->stock[n].itemset));
                    
            x->count --;
            pizBoundedStackPush (x->ticketMachine, n);
            
            if (x->shuttle == n) {
                    x->shuttle          = -1;
                    x->previousShuttle  = -1;
                }
        }
}

// -------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------:x