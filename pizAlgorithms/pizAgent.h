/**
 * \file	pizAgent.h
 * \author	Jean Sapristi
 * \date	March 19, 2012.
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

#ifndef PIZ_AGENT_H
#define PIZ_AGENT_H

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#include "pizEvent.h"

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#define PIZ_BPM_CONSTANT        25.E8
#define PIZ_DEFAULT_TEMPO       120

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#define PIZLOCKEVENT            pthread_mutex_lock   (&x->eventMutex);
#define PIZUNLOCKEVENT          pthread_mutex_unlock (&x->eventMutex);

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

typedef enum _PIZAgentFlag {
    PIZ_FLAG_NONE = 0,
    PIZ_FLAG_EXIT = 1,
    PIZ_FLAG_INIT = 2,
    PIZ_FLAG_PLAY = 4,
    PIZ_FLAG_LOOP = 8
    } PIZAgentFlag;

typedef struct _PIZAgent {
    long                flags;
    long                tempo;
    PIZTime             grainSize;
    PIZTime             grainStart;
    PIZTime             grainEnd;
    PIZLinklist         *runQueue;
    pthread_attr_t      attr;
    pthread_cond_t      eventCondition;
    pthread_mutex_t     eventMutex;
    pthread_t           eventLoop;
    long                eventLoopErr;
    } PIZAgent;                            

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

PIZAgent    *pizAgentNew            (void);
void        pizAgentFree            (PIZAgent *x);

void        *pizAgentEventLoop      (void *agent);
PIZError    pizAgentEventLoopInit   (PIZAgent *x);

void        pizAgentAppendEvent     (PIZAgent *x, PIZEvent *event);

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#endif // PIZ_AGENT_H