/*
 * \file    pizItemset1024.c
 * \author  Jean Sapristi
 * \date    26 janvier 2012
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

#include "pizItemset1024.h"

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

void pizItemset1024SetAtIndex (PIZItemset1024 *itemset, long index)
{
    long i, p, m;
    
    i = index / PIZ_ITEMSET1024_SIZE_OF_ULONG;
    p = index % PIZ_ITEMSET1024_SIZE_OF_ULONG;
    
    m = 1 << p;
    
    itemset->items[i] |= m;
}

void pizItemset1024UnsetAtIndex (PIZItemset1024 *itemset, long index) 
{
    long i, p, m;
    
    i = index / PIZ_ITEMSET1024_SIZE_OF_ULONG;
    p = index % PIZ_ITEMSET1024_SIZE_OF_ULONG;
    
    m = 1 << p;
    
    itemset->items[i] &= ~m;
}
    
void pizItemset1024Clear (PIZItemset1024 *itemset)  
{
    long i;
    
    for (i = 0; i < PIZ_ITEMSET1024_SIZE_IN_WORD; i++) {
            itemset->items[i] = 0;
        }
}
    
long pizItemset1024Count (const PIZItemset1024 *itemset)
{
    long i;
    long k = 0;
    
    for (i = 0; i < PIZ_ITEMSET1024_SIZE_IN_WORD; i++)
        {
            unsigned long n = itemset->items[i];
            
            while (n != 0) {
                    k  += (n & 1);
                    n >>= 1;
                }
        }
    
    return k;
}

bool pizItemset1024IsSetAtIndex (const PIZItemset1024 *itemset, long index) 
{
    unsigned long k = 0;

    long i, p;

    i = index / PIZ_ITEMSET1024_SIZE_OF_ULONG;
    p = index % PIZ_ITEMSET1024_SIZE_OF_ULONG;
    
    k = itemset->items[i];

    k >>= p;
    k  &= 1;
    
    return (k != 0);
}

void pizItemset1024Union (const PIZItemset1024 *a, const PIZItemset1024 *b, PIZItemset1024 *r) 
{
    long i;
    
    for (i = 0; i < PIZ_ITEMSET1024_SIZE_IN_WORD; i++) {
            r->items[i] = a->items[i] | b->items[i];
        }
}

void pizItemset1024Intersection (const PIZItemset1024 *a, const PIZItemset1024 *b, PIZItemset1024 *r) 
{
    long i;
    
    for (i = 0; i < PIZ_ITEMSET1024_SIZE_IN_WORD; i++) {
            r->items[i] = a->items[i] & b->items[i];
        }
}

bool pizItemset1024IsIncluded (const PIZItemset1024 *a, const PIZItemset1024 *b)
{
    long i;
    bool k = true;
            
    for (i = 0; i < PIZ_ITEMSET1024_SIZE_IN_WORD; i++)
        {
            if (b->items[i] != (b->items[i] | a->items[i])) {
                    k = false;
                }
        }
        
    return k;
}

bool pizItemset1024IsEqual (const PIZItemset1024 *a, const PIZItemset1024 *b)
{
    long i;
    long k = true;
            
    for (i = 0; i < PIZ_ITEMSET1024_SIZE_IN_WORD; i++)
        {
            if (a->items[i] != b->items[i]) {
                    k = false;
                }
        }
        
    return k;
}

// -------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------:x