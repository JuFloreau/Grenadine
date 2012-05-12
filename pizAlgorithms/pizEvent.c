/*
 * \file	pizEvent.c
 * \author	Jean Sapristi
 * \date	May 12, 2012.
 */
 
/*
 *  Copyright (c) 2012, Jean Sapristi & Tom Javel, 
 *  "nicolas.danet@free.fr".
 *
 *	This software is governed by the CeCILL-C license under French law and
 *	abiding by the rules of distribution of free software. You can use, 
 *	modify and/or redistribute the software under the terms of the CeCILL-C
 *	license as circulated by CEA, CNRS and INRIA at the following URL
 *	"http://www.cecill.info". 
 *
 *	As a counterpart to the access to the source code and rights to copy,
 *	modify and redistribute granted by the license, users are provided only
 *	with a limited warranty  and the software's author, the holder of the
 *	economic rights, and the successive licensors have only limited
 *	liability. 
 *
 *	In this respect, the user's attention is drawn to the risks associated
 *	with loading, using, modifying and/or developing or reproducing the
 *	software by the user in light of its specific status of free software,
 *	that may mean that it is complicated to manipulate, and that also
 *	therefore means that it is reserved for developers and experienced
 *	professionals having in-depth computer knowledge. Users are therefore
 *	encouraged to load and test the software's suitability as regards their
 *	requirements in conditions enabling the security of their systems and/or 
 *	data to be ensured and, more generally, to use and operate it in the 
 *	same conditions as regards security. 
 *	
 *	The fact that you are presently reading this means that you have had
 *	knowledge of the CeCILL-C license and that you accept its terms.
 */

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#include "pizEvent.h"
#include "pizAgentMethod.h"
#include "pizSequenceTransform.h"
#include "pizSequenceAttribute.h"

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

static const long pizEventTypes[ ]
= { PIZ_EVENT_RUN,                  // PIZ_EVENT_INIT
    PIZ_EVENT_RUN,                  // PIZ_EVENT_PLAY
    PIZ_EVENT_RUN,                  // PIZ_EVENT_STOP
    PIZ_EVENT_RUN,                  // PIZ_EVENT_LOOP
    PIZ_EVENT_RUN,                  // PIZ_EVENT_UNLOOP
    PIZ_EVENT_RUN,                  // PIZ_EVENT_BPM
    PIZ_EVENT_ATTRIBUTE,            // PIZ_EVENT_CHANCE
    PIZ_EVENT_ATTRIBUTE,            // PIZ_EVENT_VELOCITY
    PIZ_EVENT_ATTRIBUTE,            // PIZ_EVENT_CHANNEL
    PIZ_EVENT_ATTRIBUTE,            // PIZ_EVENT_CELL
    PIZ_EVENT_ATTRIBUTE,            // PIZ_EVENT_NOTE_VALUE
    PIZ_EVENT_ATTRIBUTE,            // PIZ_EVENT_SCALE
    PIZ_EVENT_ATTRIBUTE,            // PIZ_EVENT_PATTERN
    PIZ_EVENT_TRANSFORM,            // PIZ_EVENT_NOTE
    PIZ_EVENT_TRANSFORM,            // PIZ_EVENT_CLEAR
    PIZ_EVENT_TRANSFORM,            // PIZ_EVENT_TRANSPOSE
    PIZ_EVENT_TRANSFORM,            // PIZ_EVENT_CLEAN
    PIZ_EVENT_TRANSFORM,            // PIZ_EVENT_ZOULOU
    PIZ_EVENT_TRANSFORM,            // PIZ_EVENT_ROMEO
    PIZ_EVENT_TRANSFORM,            // PIZ_EVENT_NOVEMBER
    PIZ_EVENT_TRANSFORM,            // PIZ_EVENT_JULIET
    PIZ_EVENT_TRANSFORM,            // PIZ_EVENT_ROTATE
    PIZ_EVENT_TRANSFORM,            // PIZ_EVENT_SCRAMBLE
    PIZ_EVENT_TRANSFORM,            // PIZ_EVENT_SORT
    PIZ_EVENT_TRANSFORM,            // PIZ_EVENT_CHANGE
    PIZ_EVENT_TRANSFORM,            // PIZ_EVENT_FILL
    PIZ_EVENT_TRANSFORM,            // PIZ_EVENT_RANDOM
    PIZ_EVENT_TRANSFORM,            // PIZ_EVENT_KILL
    PIZ_EVENT_TRANSFORM,            // PIZ_EVENT_CYCLE        
    PIZ_EVENT_GRAPHIC,              // PIZ_EVENT_LEARN
    PIZ_EVENT_NOTIFICATION,         // PIZ_EVENT_CHANGED_BPM
    PIZ_EVENT_NOTIFICATION,         // PIZ_EVENT_CHANGED_CHANCE
    PIZ_EVENT_NOTIFICATION,         // PIZ_EVENT_CHANGED_VELOCITY
    PIZ_EVENT_NOTIFICATION,         // PIZ_EVENT_CHANGED_CHANNEL
    PIZ_EVENT_NOTIFICATION,         // PIZ_EVENT_CHANGED_CELL
    PIZ_EVENT_NOTIFICATION,         // PIZ_EVENT_CHANGED_NOTE_VALUE
    PIZ_EVENT_NOTIFICATION,         // PIZ_EVENT_CHANGED_SCALE
    PIZ_EVENT_NOTIFICATION,         // PIZ_EVENT_CHANGED_PATTERN
    PIZ_EVENT_NOTIFICATION,         // PIZ_EVENT_CHANGED_ZONE
    PIZ_EVENT_NOTIFICATION,         // PIZ_EVENT_NOTE_ADDED
    PIZ_EVENT_NOTIFICATION,         // PIZ_EVENT_NOTE_CHANGED
    PIZ_EVENT_NOTIFICATION,         // PIZ_EVENT_NOTE_REMOVED
    PIZ_EVENT_NOTIFICATION,         // PIZ_EVENT_NOTE_PLAYED
    PIZ_EVENT_NOTIFICATION,         // PIZ_EVENT_END
    PIZ_EVENT_NOTIFICATION };       // PIZ_EVENT_WILL_END

static const PIZMethodError pizEventMethods[ ] 
= { pizAgentInit,                   // PIZ_EVENT_INIT
    pizAgentPlay,                   // PIZ_EVENT_PLAY
    pizAgentStop,                   // PIZ_EVENT_STOP
    pizAgentLoop,                   // PIZ_EVENT_LOOP
    pizAgentUnloop,                 // PIZ_EVENT_UNLOOP
    pizAgentBPM,                    // PIZ_EVENT_BPM
    pizSequenceSetChance,           // PIZ_EVENT_CHANCE
    pizSequenceSetVelocity,         // PIZ_EVENT_VELOCITY
    pizSequenceSetChannel,          // PIZ_EVENT_CHANNEL
    pizSequenceSetCell,             // PIZ_EVENT_CELL
    pizSequenceSetNoteValue,        // PIZ_EVENT_NOTE_VALUE
    pizSequenceSetScale,            // PIZ_EVENT_SCALE
    pizSequenceSetPattern,          // PIZ_EVENT_PATTERN
    pizSequenceNote,                // PIZ_EVENT_NOTE
    pizSequenceClear,               // PIZ_EVENT_CLEAR
    pizSequenceTranspose,           // PIZ_EVENT_TRANSPOSE
    pizSequenceClean,               // PIZ_EVENT_CLEAN
    NULL,                           // PIZ_EVENT_ZOULOU
    NULL,                           // PIZ_EVENT_ROMEO
    NULL,                           // PIZ_EVENT_NOVEMBER
    NULL,                           // PIZ_EVENT_JULIET
    NULL,                           // PIZ_EVENT_ROTATE
    NULL,                           // PIZ_EVENT_SCRAMBLE
    NULL,                           // PIZ_EVENT_SORT
    NULL,                           // PIZ_EVENT_CHANGE
    NULL,                           // PIZ_EVENT_FILL
    NULL,                           // PIZ_EVENT_RANDOM
    NULL,                           // PIZ_EVENT_KILL
    NULL,                           // PIZ_EVENT_CYCLE        
    NULL,                           // PIZ_EVENT_LEARN
    NULL,                           // PIZ_EVENT_CHANGED_BPM
    NULL,                           // PIZ_EVENT_CHANGED_CHANCE
    NULL,                           // PIZ_EVENT_CHANGED_VELOCITY
    NULL,                           // PIZ_EVENT_CHANGED_CHANNEL
    NULL,                           // PIZ_EVENT_CHANGED_CELL
    NULL,                           // PIZ_EVENT_CHANGED_NOTE_VALUE
    NULL,                           // PIZ_EVENT_CHANGED_SCALE
    NULL,                           // PIZ_EVENT_CHANGED_PATTERN
    NULL,                           // PIZ_EVENT_CHANGED_ZONE
    NULL,                           // PIZ_EVENT_NOTE_ADDED
    NULL,                           // PIZ_EVENT_NOTE_CHANGED
    NULL,                           // PIZ_EVENT_NOTE_REMOVED
    NULL,                           // PIZ_EVENT_NOTE_PLAYED
    NULL,                           // PIZ_EVENT_END
    NULL };                         // PIZ_EVENT_WILL_END
                                                
static const char *pizEventNames[ ]  
= { "Init",
    "Play",
    "Stop",
    "Loop",
    "Unloop",
    "Bpm",
    //
    "Chance",
    "Velocity",
    "Channel",
    "Cell",
    "Note Value",
    "Scale",
    "Pattern",
    // 
    "Note",
    "Clear",
    "Transpose",
    "Clean",
    "Zoulou",
    "Romeo",
    "November",
    "Juliet",
    "Rotate",
    "Scramble",
    "Sort",
    "Change",
    "Fill",
    "Random",
    "Kill",
    "Cycle",
    //
    "Learn",
    //
    "Changed Bpm",
    "Changed Chance",
    "Changed Velocity ",
    "Changed Channel",
    "Changed Cell",
    "Changed Note Value",
    "Changed Scale",
    "Changed Pattern",
    "Changed Zone",
    "Note Added",
    "Note Changed",
    "Note Removed",
    "Note Played",
    "End",
    "Will End" };
    
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

PIZEvent *pizEventNew (PIZEventName name, long tag, long argc, const long *argv)
{
    PIZEvent *x = NULL;
    
    if (x = (PIZEvent *)calloc (1, sizeof(PIZEvent))) {
        x->name = name;
        x->type = pizEventTypes[name];
        x->tag  = tag; 
            
        if (argc && argv) {
            long i;
            x->size = MIN (argc, PIZ_EVENT_DATA_SIZE);
            for (i = 0; i < x->size; i++) {
                x->data[i] = argv[i];
            }
        }
        
        x->method = pizEventMethods[name];
    }
    
    return x;
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

void pizEventFree (PIZEvent *x)
{
    free (x);
}

void pizEventName (const PIZEvent *x, PIZEventName *name)
{
    (*name) = x->name;
}

void pizEventType (const PIZEvent *x, PIZEventType *type)
{
    (*type) = x->type;
}

void pizEventMethod (const PIZEvent *x, PIZMethodError *f)
{
    (*f) = x->method;
}

PIZError pizEventValue (const PIZEvent *x, long *value)
{
    PIZError err = PIZ_ERROR;
    
    if (x->size) {
        err = PIZ_GOOD;
        (*value) = x->data[0];
    } 
    
    return err;
}

PIZError pizEventPtr (const PIZEvent *x, long *argc, long **argv)
{
    PIZError err = PIZ_ERROR;
    
    if ((*argc) = x->size) {
        err = PIZ_GOOD;
        (*argv) = (long *)x->data;
    }
    
    return err;
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

void pizEventNameAsString (const PIZEvent *x, const char **name)
{
    (*name) = pizEventNames[x->name];
}

// -------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------:x