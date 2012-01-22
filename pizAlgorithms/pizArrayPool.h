/**
 * \file    pizArrayPool.h
 * \author  Jean Sapristi
 * \date    15 janvier 2012
 */
 
/*
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

#ifndef PIZ_ARRAY_POOL_H
#define PIZ_ARRAY_POOL_H

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#include "pizTypes.h"
#include "pizLinklist.h"
#include "pizGrowingArray.h"

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#include <pthread.h>

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

typedef struct _PIZArrayPool {
    pthread_mutex_t     lock;
    long                retain;
    long                initArraySize;
    PIZGrowingArray     *cache;
    PIZLinklist         *pool;
    } PIZArrayPool;

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

PIZ_START_C_LINKAGE

PIZArrayPool        *pizArrayPoolNew            (long argc, long *argv);
void                pizArrayPoolFree            (PIZArrayPool *pool);

PIZGrowingArray     *pizArrayPoolGetArray       (PIZArrayPool *pool);
void                pizArrayPoolReleaseArray    (PIZArrayPool *pool, PIZGrowingArray *array);

PIZ_END_C_LINKAGE

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#endif // PIZ_ARRAY_POOL_H