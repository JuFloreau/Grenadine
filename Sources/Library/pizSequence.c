 
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

#include "pizEvent.h"
#include "pizSequence.h"
#include "pizSequenceRun.h"
#include "pizSequenceMethods.h"

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

#define PIZ_DEFAULT_START       0
#define PIZ_DEFAULT_END         96
#define PIZ_DEFAULT_DOWN        60
#define PIZ_DEFAULT_UP          71
#define PIZ_DEFAULT_CHANCE      100
#define PIZ_DEFAULT_CHANNEL     1
#define PIZ_DEFAULT_VELOCITY    90

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -
#pragma mark ---
#pragma mark -

PIZSequence *pizSequenceNew(struct _PIZAgent *agent)
{
    PIZSequence *x = NULL;
    
    if (x = (PIZSequence *)malloc(sizeof(PIZSequence))) {
    //
    long argv[ ] = { 0, PIZ_SEQUENCE_MAXIMUM_NOTES };
    
    x->agent        = agent;
    x->map          = pizArrayNew(PIZ_SEQUENCE_MAXIMUM_NOTES);
    x->scale        = pizArrayNew(PIZ_MAGIC_SCALE);
    x->temp.values  = (long *)malloc(sizeof(long) * PIZ_SEQUENCE_SIZE_TEMPORARY);
    x->temp.notes1  = (PIZNote **)malloc(sizeof(PIZNote *) * PIZ_SEQUENCE_SIZE_TEMPORARY);
    x->temp.notes2  = (PIZNote **)malloc(sizeof(PIZNote *) * PIZ_SEQUENCE_SIZE_TEMPORARY);
    x->lookup       = (PIZNote **)calloc(PIZ_SEQUENCE_MAXIMUM_NOTES, sizeof(PIZNote *));
    x->temp.hash    = pizHashTableNew(2, argv);
    
    if (x->map          && 
        x->scale        &&
        x->temp.values  &&
        x->temp.notes1  &&
        x->temp.notes2  &&
        x->lookup       &&
        x->temp.hash    &&
        x->agent        &&
        (x->timeline = (PIZLinklist **)calloc(PIZ_SEQUENCE_SIZE_TIMELINE, sizeof(PIZLinklist **)))) {

        x->flags = PIZ_SEQUENCE_FLAG_NONE;
        
        pizItemsetClear(&x->removed);
        pizItemsetClear(&x->changed);
        pizItemsetClear(&x->addedLow);
        pizItemsetClear(&x->addedHigh);
             
        x->bpm       = PIZ_SEQUENCE_DEFAULT_BPM;
        x->chance    = PIZ_DEFAULT_CHANCE;
        x->velocity  = 0;
        x->channel   = PIZ_DEFAULT_CHANNEL;
        x->chord     = 0;
        x->cell      = PIZ_EIGHTH_NOTE;
        x->value     = PIZ_EIGHTH_NOTE;
        x->key       = PIZ_KEY_C;
        x->type      = PIZ_MODE_NONE;
        x->mute      = 0;
        x->start     = PIZ_DEFAULT_START;
        x->end       = PIZ_DEFAULT_END;
        x->down      = PIZ_DEFAULT_DOWN;
        x->up        = PIZ_DEFAULT_UP;
        x->count     = 0;
        x->index     = 0;
        x->dirty     = 0;
        
        x->seed = PIZ_SEED;
            
    } else {
        pizSequenceFree(x);
        x = NULL;
    }
    //
    }
    
    return x;
}

void pizSequenceFree(PIZSequence *x)
{
    if (x) {
    //
    if (x->timeline) {
    //
    long i;
    
    for (i = 0; i < PIZ_SEQUENCE_SIZE_TIMELINE; i++) {
        pizLinklistFree(x->timeline[i]);
    }
        
    free(x->timeline);
    x->timeline = NULL;
    //
    }
    
    pizArrayFree(x->scale);
    pizArrayFree(x->map);
    
    pizHashTableFree(x->temp.hash);
    
    if (x->lookup) {
        free(x->lookup);
    }
    if (x->temp.values) {
        free(x->temp.values);
    }
    if (x->temp.notes1) {
        free(x->temp.notes1);
    }
    if (x->temp.notes2) {
        free(x->temp.notes2);
    }
    
    free(x);
    //
    }
}

// -------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------:x