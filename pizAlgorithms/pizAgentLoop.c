/*
 * \file	pizAgentLoop.c
 * \author	Jean Sapristi
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

#include "pizAgentLoop.h"
#include "pizAgentMethods.h"
#include "pizSequenceRun.h"
#include "pizSequenceMethods.h"
#include "pizSequenceAttribute.h"

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#include <errno.h>

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

static const PIZMethodError pizEventMethods[ ]  = { pizAgentInit,                   // PIZ_EVENT_INIT
                                                    pizAgentPlay,                   // PIZ_EVENT_PLAY
                                                    pizAgentStop,                   // PIZ_EVENT_STOP
                                                    pizAgentLoop,                   // PIZ_EVENT_LOOP
                                                    pizAgentUnloop,                 // PIZ_EVENT_UNLOOP
                                                    pizAgentBPM,                    // PIZ_EVENT_BPM
                                                    pizAgentLearn,                  // PIZ_EVENT_LEARN
                                                    pizAgentForget,                 // PIZ_EVENT_FORGET
                                                    //
                                                    pizSequenceSetChance,           // PIZ_EVENT_CHANCE
                                                    pizSequenceSetVelocity,         // PIZ_EVENT_VELOCITY
                                                    pizSequenceSetChannel,          // PIZ_EVENT_CHANNEL
                                                    pizSequenceSetChord,            // PIZ_EVENT_CHORD
                                                    pizSequenceSetCell,             // PIZ_EVENT_CELL
                                                    pizSequenceSetNoteValue,        // PIZ_EVENT_NOTE_VALUE
                                                    pizSequenceSetScale,            // PIZ_EVENT_SCALE
                                                    pizSequenceSetPattern,          // PIZ_EVENT_PATTERN
                                                    pizSequenceNote,                // PIZ_EVENT_NOTE
                                                    NULL,                           // PIZ_EVENT_ZONE
                                                    pizSequenceClear,               // PIZ_EVENT_CLEAR
                                                    pizSequenceClean,               // PIZ_EVENT_CLEAN
                                                    pizSequenceTranspose,           // PIZ_EVENT_TRANSPOSE
                                                    pizSequenceRotate,              // PIZ_EVENT_ROTATE
                                                    pizSequenceScramble,            // PIZ_EVENT_SCRAMBLE
                                                    pizSequenceSort,                // PIZ_EVENT_SORT
                                                    pizSequenceChange,              // PIZ_EVENT_CHANGE
                                                    pizSequenceFill,                // PIZ_EVENT_FILL
                                                    pizSequenceKill,                // PIZ_EVENT_KILL
                                                    pizSequenceCycle,               // PIZ_EVENT_CYCLE 
                                                    pizSequenceAlgorithm,           // PIZ_EVENT_ZOULOU
                                                    pizSequenceAlgorithm,           // PIZ_EVENT_ROMEO
                                                    pizSequenceJuliet,              // PIZ_EVENT_JULIET
                                                    };             
                                                    
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

#define PIZ_EXIT (x->flags & PIZ_AGENT_FLAG_EXIT)

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

PIZ_LOCAL PIZError  pizAgentEventLoopDoEvent        (PIZAgent *x, PIZLinklist *q);
PIZ_LOCAL void      pizAgentEventLoopDoStep         (PIZAgent *x, bool blank);
PIZ_LOCAL void      pizAgentEventLoopDoRefresh      (PIZAgent *x);

PIZ_LOCAL void      pizAgentEventLoopInit           (PIZAgent *x);
PIZ_LOCAL void      pizAgentEventLoopSleep          (PIZAgent *x);
PIZ_LOCAL bool      pizAgentEventLoopIsCondition    (PIZAgent *x);
PIZ_LOCAL bool      pizAgentEventLoopIsWorkTime     (PIZAgent *x);

PIZ_LOCAL void      pizAgentNotificationLoopNotify  (PIZAgent *x);

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -
#pragma mark ---
#pragma mark -

void *pizAgentEventLoop (void *agent) 
{
    PIZAgent *x = (PIZAgent *)agent;  
    
    while (!PIZ_EXIT) { 
    //
    
    PIZ_AGENT_LOCK_EVENT
    
    while (!(pizAgentEventLoopIsCondition (x))) {
        pthread_cond_wait (&x->eventCondition, &x->eventLock);
        x->flags |= PIZ_AGENT_FLAG_INIT;
        if (PIZ_EXIT) { 
            break; 
        } 
    }
    
    PIZ_AGENT_UNLOCK_EVENT
        
    if (!PIZ_EXIT) {
    //
    
    pizAgentEventLoopInit (x);
     
    while (pizAgentEventLoopIsWorkTime (x)) {
        if (pizAgentEventLoopDoEvent (x, x->run)) {
            break;
        } 
    }
    
    while (pizAgentEventLoopIsWorkTime (x)) {
        if (pizAgentEventLoopDoEvent (x, x->high)) {
            break;
        } 
    }
    
    if (x->flags & PIZ_AGENT_FLAG_RUNNING) {
        if (pizAgentEventLoopIsWorkTime (x)) {
            pizAgentEventLoopDoStep (x, 0);
        } else {
            pizAgentEventLoopDoStep (x, 1);
        }
    }
    
    while (pizAgentEventLoopIsWorkTime (x)) {
        if (pizAgentEventLoopDoEvent (x, x->low)) {
            pizAgentEventLoopDoRefresh (x);
            break;
        } 
    }
    
    pizAgentEventLoopSleep (x); 
    //    
    }
    //
    }

    pthread_exit (NULL);
}

void *pizAgentNotificationLoop (void *agent)
{
    PIZAgent *x = (PIZAgent *)agent;  
    
    while (!PIZ_EXIT) { 
    //
    
    PIZ_AGENT_LOCK_NOTIFICATION
    
    while (!(pizLinklistCount (x->notification))) {
        pthread_cond_wait (&x->notificationCondition, &x->notificationLock);
        if (PIZ_EXIT) {
            break;
        } 
    }
    
    PIZ_AGENT_UNLOCK_NOTIFICATION
        
    if (!PIZ_EXIT) {
        pizAgentNotificationLoopNotify (x);
    }
    //    
    }
    
    pthread_exit (NULL);
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

void pizAgentAddNotification (PIZAgent *x, PIZEventCode n, long ac, long *av)
{
    PIZEvent *notification = NULL;

    if (notification = pizEventNew (n, -1, ac, av)) {
    
        PIZ_AGENT_LOCK_NOTIFICATION
        PIZ_AGENT_QUEUE (x->notification, notification)
        PIZ_AGENT_UNLOCK_NOTIFICATION
        pthread_cond_signal (&x->notificationCondition);
        
    } else {
        PIZ_AGENT_MEMORY
    }
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -
#pragma mark ---
#pragma mark -

PIZError pizAgentEventLoopDoEvent (PIZAgent *x, PIZLinklist *q) 
{
    PIZError        err = PIZ_GOOD;
    PIZEventCode    code;
    PIZMethodError  f = NULL;
    PIZEvent        *event = NULL;
    void            *o = NULL;
            
    PIZ_AGENT_LOCK_EVENT
    
    if (!(pizLinklistPtrAtIndex (q, 0, (void **)&event))) {
        pizLinklistChuckByPtr (q, event);
    }
    
    if (!(pizLinklistCount (q))) {
        err = PIZ_ERROR;
    }
    
    PIZ_AGENT_UNLOCK_EVENT
    
    DEBUGEVENT
    
    if (event) {
    //
    pizEventCode (event, &code);
        
    if (code < PIZ_EVENT_CHANCE) {
        o = x;
    } else {
        o = x->sequence;
    }
    
    if (o && (f = pizEventMethods[code]) && ((*f)(o, event) == PIZ_MEMORY)) {
        PIZ_AGENT_MEMORY
    }
    
    pizEventFree (event);
    //
    }
    
    return err;
}

void pizAgentEventLoopDoStep (PIZAgent *x, bool blank)
{   
    long     count;
    bool     k = false;
    PIZError err = PIZ_GOOD; 
    
    do {
    //
    
    if (!blank) {
        
        PIZ_AGENT_LOCK_NOTIFICATION
        
        count = pizLinklistCount (x->notification);
        err   = pizSequenceStep (x->sequence);
        count -= pizLinklistCount (x->notification);
        
        if (count) { 
            PIZ_AGENT_UNLOCK_NOTIFICATION
            pthread_cond_signal (&x->notificationCondition);
        } else {
            PIZ_AGENT_UNLOCK_NOTIFICATION
        }

    } else {
        err = pizSequenceStepBlank (x->sequence); 
    }
    
    if (err == PIZ_GOOD) {
        if (pizSequenceIsAtEnd (x->sequence)) {
            pizAgentAddNotification (x, PIZ_EVENT_WILL_END, 0, NULL);
        }
        k = false;  
        
    } else if (err == PIZ_ERROR) {
        if (x->flags & (PIZ_AGENT_FLAG_LOOPED | PIZ_AGENT_FLAG_REPLAY)) {
            k = true;
            x->flags &= ~PIZ_AGENT_FLAG_REPLAY;
        } else {
            k = false;
            x->flags &= ~PIZ_AGENT_FLAG_RUNNING;
        }
        
        pizSequenceGoToStart (x->sequence);
        pizAgentAddNotification (x, PIZ_EVENT_END, 0, NULL);
  
    } else if (err == PIZ_MEMORY) { 
        PIZ_AGENT_MEMORY 
    }

    //
    } while (k);
}

void pizAgentEventLoopDoRefresh (PIZAgent *x)
{
    long     count;
    PIZError err = PIZ_ERROR;
    
    PIZ_AGENT_LOCK_NOTIFICATION
    
    count = pizLinklistCount (x->notification);
    err   = pizSequenceRefresh (x->sequence);
    count -= pizLinklistCount (x->notification);
     
    if (!err && count) {
        PIZ_AGENT_UNLOCK_NOTIFICATION
        pthread_cond_signal (&x->notificationCondition);
    } else {
        PIZ_AGENT_UNLOCK_NOTIFICATION
    }
        
    if (err == PIZ_MEMORY) {
        PIZ_AGENT_MEMORY
    }
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

void pizAgentEventLoopInit (PIZAgent *x)
{   
    if (x->flags & PIZ_AGENT_FLAG_INIT) {
        pizTimeSet (&x->grainStart);
        x->flags &= ~PIZ_AGENT_FLAG_INIT;
    } else {
        pizTimeCopy (&x->grainStart, &x->grainEnd);
    }
    
    pizNanoSet     (&x->grainSize, PIZ_AGENT_CONSTANT_BPM_NS / x->bpm);
    pizTimeCopy    (&x->grainEnd, &x->grainStart);
    pizTimeAddNano (&x->grainEnd, &x->grainSize);
}

void pizAgentEventLoopSleep (PIZAgent *x)
{
    PIZTime now;
    pizTimeSet (&now);
    
    if (x->flags & PIZ_AGENT_FLAG_RUNNING) {
    //
    PIZNano          ns;
    struct timespec  t0, t1;
    struct timespec* ptrA = &t0;
    struct timespec* ptrB = &t1;
    struct timespec* temp = NULL;
    
    PIZError err = PIZ_GOOD;
    
    err = pizTimeElapsedNano (&now, &x->grainEnd, &ns);
    
    while (err) {
        pizTimeAddNano (&x->grainStart, &x->grainSize);
        pizTimeAddNano (&x->grainEnd, &x->grainSize); 
        
        pizAgentEventLoopDoStep (x, 1);
        
        err = pizTimeElapsedNano (&now, &x->grainEnd, &ns);
    }
    
    pizTimespecWithNano (ptrA, &ns);
    
    while ((nanosleep (ptrA, ptrB) == -1) && (errno == EINTR)) {
        temp = ptrA;
        ptrA = ptrB;
        ptrB = temp;
    }
    //
    } else {
        x->flags |= PIZ_AGENT_FLAG_INIT;
    }
}

bool pizAgentEventLoopIsCondition (PIZAgent *x)
{
    bool condition = false;
    
    if (pizLinklistCount (x->run)   ||
        pizLinklistCount (x->low)   ||
        pizLinklistCount (x->high)  ||
        (x->flags & PIZ_AGENT_FLAG_RUNNING)) {
        condition = true;
    }
    
    return condition;
}

bool pizAgentEventLoopIsWorkTime (PIZAgent *x)
{
    bool    isWorkTime = false;
    PIZTime now;
    PIZNano elapsed;
    PIZNano timeOut;
    
    pizTimeSet  (&now);
    pizNanoSet  (&timeOut, PIZ_AGENT_CONSTANT_RATIO_WORK / x->bpm);
    
    if (!(pizTimeElapsedNano (&x->grainStart, &now, &elapsed))) {
        if (elapsed < timeOut) {
            isWorkTime = true;
        }
    }
    
    return isWorkTime;
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

void pizAgentNotificationLoopNotify (PIZAgent *x)
{
    PIZEvent *event = NULL;
            
    PIZ_AGENT_LOCK_NOTIFICATION
    
    if (!(pizLinklistPtrAtIndex (x->notification, 0, (void **)&event))) {
        pizLinklistChuckByPtr (x->notification, event);
    }
    
    PIZ_AGENT_UNLOCK_NOTIFICATION   
    
    if (event) {
    //
    PIZ_AGENT_LOCK_OBSERVER
    
    if (x->observer && x->notify) {
        (*x->notify)(x->observer, event);
    }
    
    PIZ_AGENT_UNLOCK_OBSERVER
    //
    }
} 

// -------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------:x