
/*
 *  Copyright (c) 2011, Nicolas Danet, 
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
#pragma mark -

#define PIZ_MAXIMUM_THRESHOLD   100
#define PIZ_INIT_SIZE_ARRAY     4
#define PIZ_DEFAULT_THRESHOLD   50

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

PIZ_INLINE void     pizGaloisLatticeReconnect       (PIZGaloisLattice *x, long g, long n);
PIZ_STATIC PIZError pizGaloisLatticeMakeMap         (PIZGaloisLattice *x);
PIZ_STATIC void     pizGaloisLatticeKillConcept     (PIZGaloisLattice *x, long n);

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -
#pragma mark ---
#pragma mark -

PIZGaloisLattice *pizGaloisLatticeNew(long argc, long *argv)
{
    PIZGaloisLattice *x = NULL;

    if (x = (PIZGaloisLattice *)calloc(1, sizeof(PIZGaloisLattice))) {
    //
    PIZError err = PIZ_GOOD;
    
    if (x->stock = (PIZGaloisLatticeConcept *)calloc(PIZ_ITEMSET_SIZE, sizeof(PIZGaloisLatticeConcept))) {
    //
    long i;
    
    x->threshold       = PIZ_DEFAULT_THRESHOLD;
    x->targetedConcept = -1;
    x->shuttle         = -1;
    x->previousShuttle = -1;
    
    x->seed = PIZ_SEED;
        
    if (argc && ((argv[0] > 0)  && (argv[0] <= PIZ_MAXIMUM_THRESHOLD))) {
        x->threshold = argv[0];
    }
    
    for (i = 0; i < PIZ_ITEMSET_SIZE; i++) {
        pizItemsetSetAtIndex(&(x->stock[1].itemset), i);
    }
    
    x->stock[0].cardinal = 0;
    x->stock[1].cardinal = PIZ_ITEMSET_SIZE;
    
    pizItemsetSetAtIndex(&(x->stock[0].childs), 1);
    pizItemsetSetAtIndex(&(x->stock[1].parents), 0);
    
    if (x->ticketMachine = pizStackNew((PIZ_ITEMSET_SIZE - 2))) {
        for (i = (PIZ_ITEMSET_SIZE - 1); i > 1; i--) {
            pizStackPush(x->ticketMachine, i);
        }
    } else {
        err = PIZ_MEMORY;
    }
        
    if (x->map = (PIZArray **)malloc((PIZ_ITEMSET_SIZE + 1) * sizeof(PIZArray *))) {
        for (i = 0; i < (PIZ_ITEMSET_SIZE + 1); i++) {
            if (!(x->map[i] = pizArrayNew(PIZ_INIT_SIZE_ARRAY))) {
                err = PIZ_MEMORY;
            }
        }
    } else {
        err = PIZ_MEMORY;
    }
    
    if (x->tempMap = (PIZArray **)malloc((PIZ_ITEMSET_SIZE + 1) * sizeof(PIZArray *))) {
        for (i = 0; i < (PIZ_ITEMSET_SIZE + 1); i++) {
            if (!(x->tempMap[i] = pizArrayNew(PIZ_INIT_SIZE_ARRAY))) {
                err = PIZ_MEMORY;
            }
        }
    } else {
        err = PIZ_MEMORY;
    }
    
    if (!err) {
        err |= pizArrayAppend(x->map[0], 0);
        err |= pizArrayAppend(x->map[PIZ_ITEMSET_SIZE], 1);
    }
    
    if (err) {
        pizGaloisLatticeFree(x);
        x = NULL;
    }
    //            
    } else {
        free(x);
        x = NULL;
    }
    //    
    }
    
    return x;
}

void pizGaloisLatticeFree(PIZGaloisLattice *x)
{
    if (x) {
    //
    long i;
    
    if (x->map) {
        for (i = 0; i < (PIZ_ITEMSET_SIZE + 1); i++) {
            pizArrayFree(x->map[i]);
            x->map[i] = NULL;
        }
        
        free(x->map);
        x->map = NULL;
    }
    
    if (x->tempMap) {
        for (i = 0; i < (PIZ_ITEMSET_SIZE + 1); i++) {
            pizArrayFree(x->tempMap[i]);
            x->tempMap[i] = NULL;
        }
        
        free(x->tempMap);
        x->tempMap = NULL;
    }

    pizStackFree(x->ticketMachine);
    x->ticketMachine = NULL;
    
    free(x->stock);
    x->stock = NULL;
    
    free(x);
    //
    }
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

PIZError pizGaloisLatticeAdd(PIZGaloisLattice *x, long argc, long *argv)
{
    long i;
    PIZError err = PIZ_ERROR;
    
    pizItemsetClear(&(x->toBeAdded));
    
    if (argv && (argc > 0)) {
        long j;
        for (j = 0; j < argc; j++) {
            if ((argv[j] >= 0) && (argv[j] < PIZ_ITEMSET_SIZE)) {
                pizItemsetSetAtIndex(&(x->toBeAdded), argv[j]);
            }
        }
        
        err = PIZ_GOOD;
    }

    pizArrayClear(x->tempMap[0]);
    pizArrayClear(x->tempMap[PIZ_ITEMSET_SIZE]);
    
    for (i = 1; i <= x->tempMapPeak; i++) {
        pizArrayClear(x->tempMap[i]);
    }
    
    x->tempMapPeak = 0;
    
    for (i = 0; i < (PIZ_ITEMSET_SIZE + 1); i++) {
    //
    long j;
    for (j = 0; j < pizArrayCount(x->map[i]); j++) {   
        long g = pizArrayAtIndex(x->map[i], j);
        
        if (pizItemsetIsEqual(&(x->stock[g].itemset), &(x->toBeAdded))) {
            goto end;
            
        } else if (pizItemsetIsIncluded(&(x->stock[g].itemset), &(x->toBeAdded))) {
            if (pizArrayAppend(x->tempMap[i], g)) {
                err = PIZ_MEMORY;
            } else {
                if (i > x->tempMapPeak) {
                    x->tempMapPeak = i;
                }
            }
            
        } else {
            long generator = false;
            
            pizItemsetIntersection(&(x->stock[g].itemset), &(x->toBeAdded), &(x->intersection));
                
            if (x->intersectionCardinal = pizItemsetCount(&(x->intersection))) {
                long t;
                
                generator = true;
                
                for (t = 0; t < pizArrayCount(x->tempMap [x->intersectionCardinal]); t++) {
                    long p = pizArrayAtIndex(x->tempMap[x->intersectionCardinal], t);
                    
                    if (pizItemsetIsEqual(&(x->stock[p].itemset), &(x->intersection))) {
                        generator = false;
                    }
                }
            }
            
            if (generator) {
                if (!(pizStackPop(x->ticketMachine))) {
                    long n = pizStackPoppedValue(x->ticketMachine);
                    
                    if (pizArrayAppend(x->tempMap [x->intersectionCardinal], n)) {
                        pizStackPush(x->ticketMachine, n);
                        err = PIZ_MEMORY;
                        
                    } else {
                        x->stock[n].cardinal = x->intersectionCardinal;
                        x->stock[n].itemset = x->intersection;
                
                        x->count ++;
                        x->needToMakeMap = true;
                
                        if (x->intersectionCardinal > x->tempMapPeak) {
                            x->tempMapPeak = x->intersectionCardinal;
                        }
                        
                        pizItemsetSetAtIndex(&(x->stock[n].childs), g);
                        pizItemsetSetAtIndex(&(x->stock[g].parents), n);
                        
                        pizGaloisLatticeReconnect(x, g, n);
                        
                        if (pizItemsetIsEqual(&(x->intersection), &(x->toBeAdded))) {
                            goto end;
                        }
                    }
                }
            }
        }
    }
    //    
    }
        
end:
    
    if (x->needToMakeMap) {
        err |= pizGaloisLatticeMakeMap(x);
        
        while (x->count > x->threshold) {
            pizGaloisLatticeKillConcept(x, x->targetedConcept);
            pizGaloisLatticeMakeMap(x);
        }
    
        if (!x->count) {
            pizItemsetSetAtIndex(&(x->stock[0].childs), 1);
            pizItemsetSetAtIndex(&(x->stock[1].parents), 0);
        }
        
        x->needToMakeMap = false;
    }

    return err;
}

PIZError pizGaloisLatticeClear(PIZGaloisLattice *x)
{
    long i;
    
    for (i = 1; i <= x->mapPeak; i++) {
        pizArrayClear(x->map[i]);
    }
        
    x->mapPeak = 0;
    
    pizItemsetClear(&(x->stock[0].childs));
    pizItemsetClear(&(x->stock[1].parents));
    
    pizItemsetSetAtIndex(&(x->stock[0].childs), 1);
    pizItemsetSetAtIndex(&(x->stock[1].parents), 0);
                    
    for (i = 2; i < PIZ_ITEMSET_SIZE; i++) {
        if (x->stock[i].cardinal) {
            x->stock[i].cardinal = 0;
            pizItemsetClear(&(x->stock[i].itemset));
            pizItemsetClear(&(x->stock[i].childs));
            pizItemsetClear(&(x->stock[i].parents));
        }
    }
    
    pizStackClear(x->ticketMachine);
                                
    for (i = (PIZ_ITEMSET_SIZE - 1); i > 1; i--) {
        pizStackPush(x->ticketMachine, i);
    }
        
    x->count           = 0;
    x->shuttle         = -1;
    x->previousShuttle = -1;
    
    return PIZ_GOOD;
}

PIZError pizGaloisLatticeProceed(PIZGaloisLattice *x, long argc, long *argv)
{
    PIZError err = PIZ_ERROR;
    
    if ((argc > 0 && argv) && (x->count > 0)) {
    //
    long k = 0;
    
    if (x->shuttle == -1) {
        x->shuttle          = x->targetedConcept;
        x->previousShuttle  = x->targetedConcept;
    }
    
    while (argc) {
    //
    long i, indexConnections = 0;
    long connections[PIZ_ITEMSET_SIZE];
    
    if (x->shuttle > 1) {
        long j, t = (long)(PIZ_ITEMSET_SIZE * (rand_r(&x->seed) / (RAND_MAX + 1.0)));
                                    
        for (j = 0; j < PIZ_ITEMSET_SIZE; j++) {
            if (pizItemsetIsSetAtIndex(&(x->stock[x->shuttle].itemset), (t + j) % PIZ_ITEMSET_SIZE)) {
                if (argc) {
                    argv[k] = (t + j) % PIZ_ITEMSET_SIZE;
                    argc --;
                    k ++;
                }
            }
        }
    }
    
    for (i = 0; i < PIZ_ITEMSET_SIZE; i++) {
        if (pizItemsetIsSetAtIndex(&(x->stock[x->shuttle].childs), i) || 
            pizItemsetIsSetAtIndex(&(x->stock[x->shuttle].parents), i)) {
            connections[indexConnections] = i;
            indexConnections ++;
        }
    }
    
    if (x->shuttle < 2) {
        x->previousShuttle = x->shuttle;
        x->shuttle = connections[(long)(indexConnections * (rand_r(&x->seed) / (RAND_MAX + 1.0)))];
    } else {
        long n;
        
        do {        
        n = connections[(long)(indexConnections * (rand_r(&x->seed) / (RAND_MAX + 1.0)))];
        } while (n == x->previousShuttle);
        
        x->previousShuttle = x->shuttle;
        x->shuttle = n;
    }
    //    
    }
        
    err = PIZ_GOOD;
    //    
    }
    
    return err;
}

long pizGaloisLatticeCount(const PIZGaloisLattice *x)
{
    return x->count;
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -
#pragma mark ---
#pragma mark -

PIZ_INLINE void pizGaloisLatticeReconnect(PIZGaloisLattice *x, long g, long n)
{
    long i;
    
    for (i = 0; i < x->intersectionCardinal; i++) {
        long j;
        for (j = 0; j < pizArrayCount(x->tempMap[i]); j++) {
            long p = pizArrayAtIndex(x->tempMap[i], j);
            
            if (pizItemsetIsIncluded(&(x->stock[p].itemset), &(x->intersection))) {
                long t, isParentOfGenerator = true;
                
                for (t = 0; t < PIZ_ITEMSET_SIZE; t++) {
                    if (pizItemsetIsSetAtIndex(&(x->stock[p].childs), t)) {
                        if (pizItemsetIsIncluded(&(x->stock[t].itemset), &(x->intersection))) {
                            isParentOfGenerator = false;
                            break;
                        }
                    }
                }
                
                if (isParentOfGenerator) {
                    pizItemsetUnsetAtIndex(&(x->stock[g].parents), p);
                    pizItemsetUnsetAtIndex(&(x->stock[p].childs),  g);
                    pizItemsetSetAtIndex(&(x->stock[n].parents), p);
                    pizItemsetSetAtIndex(&(x->stock[p].childs),  n);
                }
            }
        }
    }
}

PIZError pizGaloisLatticeMakeMap(PIZGaloisLattice *x)
{
    long k = -1;
    long i, j = 0;
    PIZError err = PIZ_GOOD;
    
    x->targetedConcept = -1;
    
    if (x->count) {
        k = (long)(x->count * (rand_r(&x->seed) / (RAND_MAX + 1.0)));
    }
    
    for (i = 1; i <= x->mapPeak; i++) {
        pizArrayClear(x->map[i]);
    }
    
    x->mapPeak = 0;
        
    for (i = 2; i < PIZ_ITEMSET_SIZE; i++) {
        if (x->stock[i].cardinal) {
            if (x->stock[i].cardinal > x->mapPeak) {
                x->mapPeak = x->stock[i].cardinal;
            }
            
            err |= pizArrayAppend(x->map[x->stock[i].cardinal], i);
            
            if (k == j) {
                x->targetedConcept = i;
            }
                
            j ++;
        }
    }
    
    return err;
}

void pizGaloisLatticeKillConcept(PIZGaloisLattice *x, long n)
{
    if (n > 1) {
    //
    long i;
        
    for (i = 0; i < PIZ_ITEMSET_SIZE; i++) {
        if (pizItemsetIsSetAtIndex(&(x->stock[n].parents), i)) {
            pizItemsetUnsetAtIndex(&(x->stock[i].childs), n);
            pizItemsetUnsetAtIndex(&(x->stock[n].parents), i);
            
            if (pizItemsetCount(&(x->stock[i].childs)) == 0) {
                pizGaloisLatticeKillConcept(x, i);
            }
        }
        
        if (pizItemsetIsSetAtIndex(&(x->stock[n].childs), i)) {
            pizItemsetUnsetAtIndex(&(x->stock[i].parents), n);
            pizItemsetUnsetAtIndex(&(x->stock[n].childs), i);
            
            if (pizItemsetCount(&(x->stock[i].parents)) == 0) {
                pizGaloisLatticeKillConcept(x, i);
            }
        }
    }
    
    x->stock[n].cardinal = 0;
    pizItemsetClear(&(x->stock[n].itemset));
            
    x->count --;
    pizStackPush(x->ticketMachine, n);
    
    if (x->shuttle == n) {
        x->shuttle         = -1;
        x->previousShuttle = -1;
    }
    //    
    }
}

// -------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------:x