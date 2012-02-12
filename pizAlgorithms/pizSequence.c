/*
 * \file    pizSequence.c
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

#include "pizSequence.h"

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#include <stdlib.h>
#include <time.h>

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

static long piz_modes[ ] = 
   {0,-1, 0, 1, 0, 0, 1, 0,-1, 0, 1, 0,     // Ionian
    0,-1, 0, 0,-1, 0, 1, 0,-1, 0, 0,-1,     // Dorian
    0, 0,-1, 0,-1, 0, 1, 0, 0,-1, 0,-1,     // Phrygian
    0,-1, 0, 1, 0, 1, 0, 0,-1, 0, 1, 0,     // Lydian
    0,-1, 0, 1, 0, 0, 1, 0,-1, 0, 0,-1,     // Mixolydian
    0,-1, 0, 0,-1, 0, 1, 0, 0,-1, 0,-1,     // Aeolian
    0, 0,-1, 0,-1, 0, 0,-1, 0,-1, 0,-1,     // Locrian
    0,-1, 0, 0,-1, 0, 1, 0, 0,-1, 0,-1,     // Natural
    0,-1, 0, 0,-1, 0, 1, 0, 0,-1, 1, 0,     // Harmonic
    0,-1, 0, 0,-1, 0, 1, 0,-1, 0, 1, 0,     // Melodic
    0,-1, 0,-1, 0,-1, 0, 1, 0,-1, 0, 1,     // Whole tone
    0,-1, 0,-1, 0,-1, 1, 0,-1, 0,-1, 1,     // Pentatonic major
    0,-1, 1, 0, 1, 0,-1, 0,-1, 1, 0,-1,     // Pentatonic minor
    0, 0,-1, 0, 0, 1, 0, 0, 1, 0, 0,-1,     // Octatonic half whole
    0,-1, 0, 0, 1, 0, 0,-1, 0, 0, 1, 0,     // Octatonic whole half
    0,-1,-2, 1, 0,-1, 1, 0,-1,-2, 1, 0,     // Seventh major
    0,-1,-2, 1, 0,-1, 1, 0,-1, 1, 0,-1,     // Seventh dominant
    0,-1, 1, 0,-1,-2, 1, 0,-1, 1, 0,-1,     // Seventh minor
    0,-1,-2, 1, 0,-1, 1, 0, 1, 0,-1,-2,     // Seventh major sixth
    0,-1, 1, 0,-1,-2, 1, 0, 1, 0,-1,-2,     // Seventh minor sixth
    0,-1, 1, 0,-1, 1, 0,-1,-2, 1, 0,-1,     // Seventh half diminished
    0,-1, 1, 0,-1, 1, 0,-1, 1, 0,-1,-2,     // Seventh diminished
    0,-1,-2, 2, 1, 0, 1, 0,-1, 1, 0,-1,     // Seventh suspended
    0,-1,-2, 1, 0,-1, 2, 1, 0,-1, 0,-1,     // Seventh sharp five
    0,-1,-2, 1, 0, 1, 0,-1,-2, 1, 0,-1};    // Seventh flat five

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

PIZSequence *pizSequenceNew ( )
{
    PIZSequence *x = NULL;
    
    if (x = (PIZSequence *)malloc (sizeof(PIZSequence)))
        {
            long argv[2]    = {0, PIZ_SEQUENCE_MAXIMUM_NOTES};
            
            x->map          = pizGrowingArrayNew (4);
            x->scale        = pizGrowingArrayNew (PIZ_MAGIC_SCALE);
            x->pattern      = pizGrowingArrayNew (4);
            x->values1      = (long *)malloc (sizeof(long) * PIZ_POOL_SIZE);
            x->values2      = (long *)malloc (sizeof(long) * PIZ_POOL_SIZE);
            x->notes1       = (PIZNote **)malloc (sizeof(PIZNote *) * PIZ_POOL_SIZE);
            x->notes2       = (PIZNote **)malloc (sizeof(PIZNote *) * PIZ_POOL_SIZE);
            x->hashTable    = pizBoundedHashTableNew (2, argv);
            
            if (x->map && 
                x->scale &&
                x->pattern &&
                x->values1 &&
                x->values2 &&
                x->notes1 &&
                x->notes2 &&
                x->hashTable &&
                (x->timeline = (PIZLinklist **)calloc (PIZ_SEQUENCE_TIMELINE_SIZE, sizeof(PIZLinklist **)))) {
                
                    srand ((unsigned int)time(NULL));
                    
                    pizItemset1024Clear (&x->mapFlags);
                    
                    pthread_mutex_init (&x->lock, NULL);
                    
                    x->markedNote       = NULL;
                    x->start            = PIZ_DEFAULT_START;
                    x->end              = PIZ_DEFAULT_END;
                    x->down             = PIZ_DEFAULT_DOWN;
                    x->up               = PIZ_DEFAULT_UP;
                    x->count            = 0;
                    x->index            = 0;
                    x->chance           = PIZ_DEFAULT_CHANCE;
                    x->channel          = PIZ_DEFAULT_CHANNEL;
                    x->velocity         = 0;
                    x->grid             = PIZ_SNAP_NONE;
                    x->noteValue        = PIZ_SNAP_NONE;
                    x->tempStart        = PIZ_DEFAULT_START;
                    x->tempEnd          = PIZ_DEFAULT_END;
                    x->tempDown         = PIZ_DEFAULT_DOWN;
                    x->tempUp           = PIZ_DEFAULT_UP;
                    x->tempOriginStart  = PIZ_DEFAULT_START;
                    x->tempOriginDown   = PIZ_DEFAULT_DOWN;
                    x->tempOriginWidth  = (PIZ_DEFAULT_END - PIZ_DEFAULT_START);
                    x->tempOriginHeight = (PIZ_DEFAULT_UP - PIZ_DEFAULT_DOWN);
                }
            else
                {
                    pizSequenceFree (x);
                    x = NULL;
                }
        }
    
    return x;
}

void pizSequenceFree (PIZSequence *x)
{
    if (x) {
        PIZLOCK
        
        if (x->timeline) {
            long i;
            for (i = 0; i < PIZ_SEQUENCE_TIMELINE_SIZE; i++) {
                    pizLinklistFree (x->timeline[i]);
                }
                
            free (x->timeline);
            x->timeline = NULL;
        }
        
        pizGrowingArrayFree (x->map);
        pizGrowingArrayFree (x->scale);
        pizGrowingArrayFree (x->pattern);
        
        pizBoundedHashTableFree (x->hashTable);
        
        if (x->values1) {
            free (x->values1);
            }
        if (x->values2) {
            free (x->values2);
            }
        if (x->notes1) {
            free (x->notes1);
            }
        if (x->notes2) {
            free (x->notes2);
            }
            
        PIZUNLOCK
        
        pthread_mutex_destroy (&x->lock);
        
        free (x);
    }
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

long pizSequenceCount (PIZSequence *x)
{   
    long k; 
    
    PIZLOCK
    k = x->count;
    PIZUNLOCK
    
    return k;
}   

long pizSequenceIndex (PIZSequence *x)
{
    long k;
    
    PIZLOCK
    k = x->index;
    PIZUNLOCK
    
    return k;
}

long pizSequenceChannel (PIZSequence *x)
{
    long k;
    
    PIZLOCK
    k = x->channel;
    PIZUNLOCK
    
    return k;
}

long pizSequenceVelocity (PIZSequence *x)
{
    long k;
    
    PIZLOCK
    k = x->velocity;
    PIZUNLOCK
    
    return k;
}

PIZSnapValue pizSequenceGrid (PIZSequence *x)
{
    long k;
    
    PIZLOCK
    k = x->grid;
    PIZUNLOCK
    
    return k;
}

PIZSnapValue pizSequenceNoteValue (PIZSequence *x)
{
    long k;
    
    PIZLOCK
    k = x->noteValue;
    PIZUNLOCK
    
    return k;
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

void pizSequenceSetChance (PIZSequence *x, long value)
{
    PIZLOCK
    x->chance = CLAMP (value, 0, 100);
    PIZUNLOCK
}

void pizSequenceSetChannel (PIZSequence *x, long channel)
{
    PIZLOCK
    x->channel = CLAMP (channel, 1, PIZ_MAGIC_CHANNEL);
    PIZUNLOCK
}

void pizSequenceSetVelocity (PIZSequence *x, long value)
{
    PIZLOCK
    x->velocity = value;
    PIZUNLOCK
}

void pizSequenceSetGrid (PIZSequence *x, PIZSnapValue snapValue)
{
    PIZLOCK
    x->grid = snapValue;
    PIZUNLOCK
}

void pizSequenceSetNoteValue (PIZSequence *x, PIZSnapValue noteValue)
{
    PIZLOCK
    x->noteValue = noteValue;
    PIZUNLOCK
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

PIZError pizSequenceSetScale (PIZSequence *x, PIZScaleKey key, PIZScaleType type, const PIZGrowingArray *a)
{
    long err = PIZ_GOOD;
    long *ptr = NULL;

    PIZLOCK
    
    pizGrowingArrayClear (x->scale);
    
    if (type == PIZ_SCALE_CUSTOM) {
        if (a && (pizGrowingArrayCount (a) == PIZ_MAGIC_SCALE)) { 
            ptr = pizGrowingArrayPtr (a);
        } else {
            err = PIZ_ERROR;
        }
    } else if (type != PIZ_SCALE_NONE) {
        ptr = piz_modes + (type * PIZ_MAGIC_SCALE); 
    }
    
    if (ptr) {
        long i;
        for (i = 0; i < PIZ_MAGIC_SCALE; i++) {
                pizGrowingArrayAppend (x->scale, *(ptr + ((PIZ_MAGIC_SCALE - key + i) % PIZ_MAGIC_SCALE)));
            }
        }
    
    PIZUNLOCK
    
    return err;
}   

PIZError pizSequenceSetPattern (PIZSequence *x, const PIZGrowingArray *a)
{
    long err = PIZ_ERROR;
     
    PIZLOCK
    
    if (a) {
            err = PIZ_GOOD;
            err |= pizGrowingArrayCopy (x->pattern, a);
        }
    
    PIZUNLOCK
    
    return err;
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

void pizSequenceClear (PIZSequence *x)
{
    PIZLOCK
    
    pizSequenceClearNotes (x);
    
    PIZUNLOCK
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

PIZError pizSequenceSetZoneWithArray (PIZSequence *x, const PIZGrowingArray *a)
{
    long err = PIZ_ERROR;
    
    PIZLOCK
    
    if (a && (pizGrowingArrayCount (a) == PIZ_SEQUENCE_ZONE_SIZE))
        {
            long tempStart  = pizGrowingArrayValueAtIndex (a, PIZ_SEQUENCE_START);
            long tempEnd    = pizGrowingArrayValueAtIndex (a, PIZ_SEQUENCE_END);
            long tempDown   = pizGrowingArrayValueAtIndex (a, PIZ_SEQUENCE_DOWN);
            long tempUp     = pizGrowingArrayValueAtIndex (a, PIZ_SEQUENCE_UP);
            
            tempStart   = CLAMP (tempStart, 0, PIZ_SEQUENCE_TIMELINE_SIZE);
            tempEnd     = CLAMP (tempEnd,   0, PIZ_SEQUENCE_TIMELINE_SIZE);
            tempDown    = CLAMP (tempDown,  0, PIZ_MAGIC_PITCH);
            tempUp      = CLAMP (tempUp,    0, PIZ_MAGIC_PITCH);
    
            if (tempStart != tempEnd) 
                {
                    if (tempEnd < tempStart) {
                            long k      = tempEnd;
                            tempEnd     = tempStart;
                            tempStart   = k;
                        }
                    
                    if (tempUp < tempDown) {
                            long k      = tempUp;
                            tempUp      = tempDown;
                            tempDown    = k;
                        }
                    
                    x->start = tempStart;
                    x->end   = tempEnd;
                    x->down  = tempDown;
                    x->up    = tempUp;
                    
                    err = PIZ_GOOD;
                } 
        }
    
    PIZUNLOCK
    
    return err;
}

PIZError pizSequenceAddNotesWithArray (PIZSequence *x, const PIZGrowingArray *a, long modeFlags)
{
    bool haveChanged = false;
    long err = PIZ_ERROR;
    
    PIZLOCK
    
    if (modeFlags & PIZ_SEQUENCE_ADD_FLAG_CLEAR) {
            pizSequenceClearNotes (x);
        }
        
    if (a) {
        long i, count;
        long *ptr = NULL;
        
        err = PIZ_GOOD;
        
        count   = pizGrowingArrayCount (a) / PIZ_SEQUENCE_NOTE_SIZE;
        ptr     = pizGrowingArrayPtr (a);
        
        for (i = (count - 1); i >= 0; i--) {
            if (!(pizSequenceAddNote (x, ptr + (i * PIZ_SEQUENCE_NOTE_SIZE), modeFlags))) {
                err |= PIZ_ERROR;
            } else {
                haveChanged = true;
            }
        }
        
        if (haveChanged) {
            pizSequenceCleanMap (x);
        }
    }
    
    PIZUNLOCK
    
    return err;
}

PIZError pizSequenceAddNoteWithCoordinates (PIZSequence *x, const PIZCoordinates *coordinates, long modeFlags)
{
    long err = PIZ_GOOD;
    long values[PIZ_SEQUENCE_NOTE_SIZE];
    
    PIZLOCK
        
    values[PIZ_SEQUENCE_POSITION]       = coordinates->position;
    values[PIZ_SEQUENCE_PITCH]          = coordinates->pitch;
    values[PIZ_SEQUENCE_VELOCITY]       = PIZ_DEFAULT_VELOCITY;
    values[PIZ_SEQUENCE_CHANNEL]        = PIZ_CHANNEL_NONE;
    values[PIZ_SEQUENCE_IS_SELECTED]    = true;
    values[PIZ_SEQUENCE_IS_MARKED]      = true;

    if (x->noteValue != PIZ_SNAP_NONE) {
        values[PIZ_SEQUENCE_DURATION] = x->noteValue;
    } else {
        values[PIZ_SEQUENCE_DURATION] = x->grid;
    }
    
    if (!(pizSequenceAddNote (x, values, modeFlags))) {
        err |= PIZ_ERROR;
    } else {
        pizSequenceCleanMap (x);
    }
                    
    PIZUNLOCK
    
    return err;
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

PIZError pizSequenceZoneToArray (PIZSequence *x, PIZGrowingArray *a)
{
    long err = PIZ_ERROR;

    PIZLOCK
    
    if (a) {
            err = PIZ_GOOD;
            
            err |= pizGrowingArrayAppend (a, x->start);
            err |= pizGrowingArrayAppend (a, x->end);
            err |= pizGrowingArrayAppend (a, x->down);
            err |= pizGrowingArrayAppend (a, x->up);
        }
    
    PIZUNLOCK
    
    return err;
}

PIZError pizSequenceNotesToArray (PIZSequence *x, PIZGrowingArray *a, PIZGrowingArray *b)
{
    long i, scale;
    long err = PIZ_GOOD;
    
    PIZLOCK
    
    scale = pizGrowingArrayCount (x->scale);
    
    for (i = 0; i < pizGrowingArrayCount (x->map); i++) {   
        PIZNote *note       = NULL;
        PIZNote *nextNote   = NULL;
        
        long p = pizGrowingArrayValueAtIndex (x->map, i);
        
        pizLinklistPtrAtIndex (x->timeline[p], 0, (void **)&note);
        
        while (note) {
            long pitch;
            
            pizLinklistNextByPtr (x->timeline[p], (void *)note, (void **)&nextNote);
            
            pitch = note->data[PIZ_PITCH];
            
            if (scale) {
                    pitch += pizGrowingArrayValueAtIndex (x->scale, pitch % scale);
                }
                        
            if (note->isSelected && b) {
                err |= pizGrowingArrayAppend (b, note->position);
                err |= pizGrowingArrayAppend (b, CLAMP (pitch, 0, PIZ_MAGIC_PITCH));
                err |= pizGrowingArrayAppend (b, note->data[PIZ_VELOCITY]);
                err |= pizGrowingArrayAppend (b, note->data[PIZ_DURATION]);
                err |= pizGrowingArrayAppend (b, note->data[PIZ_CHANNEL]);
                err |= pizGrowingArrayAppend (b, note->isSelected);
                err |= pizGrowingArrayAppend (b, (note == x->markedNote));
            } else if (a) {
                err |= pizGrowingArrayAppend (a, note->position);
                err |= pizGrowingArrayAppend (a, CLAMP (pitch, 0, PIZ_MAGIC_PITCH));
                err |= pizGrowingArrayAppend (a, note->data[PIZ_VELOCITY]);
                err |= pizGrowingArrayAppend (a, note->data[PIZ_DURATION]);
                err |= pizGrowingArrayAppend (a, note->data[PIZ_CHANNEL]);
                err |= pizGrowingArrayAppend (a, note->isSelected);
                err |= pizGrowingArrayAppend (a, (note == x->markedNote));
            }

            note = nextNote;
        }
    }
    
    PIZUNLOCK
    
    return err;
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

bool pizSequenceClean (PIZSequence *x, long value)
{
    long i, scale, v;
    long index = 0;
    bool haveChanged = false;

    PIZLOCK
        
    scale = pizGrowingArrayCount (x->scale);
    v = CLAMP (value, 0, PIZ_MAGIC_PITCH);
    
    for (i = 0; i < (PIZ_MAGIC_PITCH + 1); i++) {
            x->values2[i] = 0;
        }
    
    for (i = 0; i < pizGrowingArrayCount (x->map); i++) {   
        PIZNote *note       = NULL;
        PIZNote *nextNote   = NULL;
        
        long p = pizGrowingArrayValueAtIndex (x->map, i);
        
        pizLinklistPtrAtIndex (x->timeline[p], 0, (void **)&note);
        
        while (note) {
            long j, start, end, m, n, pitch;
            bool death = false;
            
            pizLinklistNextByPtr (x->timeline[p], (void *)note, (void **)&nextNote);
            
            pitch = note->data[PIZ_PITCH];
                    
            if (scale) {
                    pitch += pizGrowingArrayValueAtIndex (x->scale, pitch % scale);
                }
            
            start   = pitch - v;
            end     = start + (2 * v);
            
            m = CLAMP (start, 0, PIZ_MAGIC_PITCH);
            n = CLAMP (end, 0, PIZ_MAGIC_PITCH);
            
            for (j = m; j <= n; j++) {
                if (x->values2[j] == (p + 1)) {
                        death = true;
                    }
                }
            
            if (death) {
                x->notes1[index] = note;
                x->values1[index] = p;
                index ++;
            } else {
                x->values2[pitch] = (p + 1);
            }
            
            note = nextNote;
        }
    }
    
    if (index) {
        for (i = 0; i < index; i++) {
            if (x->notes1[i] == x->markedNote) {
                    x->markedNote = NULL;
                }
                        
            if (!pizLinklistRemoveByPtr (x->timeline[x->values1[i]], (void *)x->notes1[i])) {
                    x->count --;
                }
        }
        
        haveChanged = true;
    }
    
    PIZUNLOCK
    
    return haveChanged;
}

bool pizSequenceApplyPattern (PIZSequence *x)
{
    long patternSize, i;
    bool haveChanged = false;
    
    PIZLOCK
    
    patternSize = pizGrowingArrayCount (x->pattern);
    
    for (i = 0; i < pizGrowingArrayCount (x->map); i++) {   
        PIZNote *note       = NULL;
        PIZNote *nextNote   = NULL;
        
        long p = pizGrowingArrayValueAtIndex (x->map, i);
        
        pizLinklistPtrAtIndex (x->timeline[p], 0, (void **)&note);
        
        while (note) {
            long newPosition;
            
            pizLinklistNextByPtr (x->timeline[p], (void *)note, (void **)&nextNote);
            
            newPosition = note->originPosition;
            
            if (patternSize) {
                newPosition = pizSequenceSnapPositionToPattern (x, note->originPosition, patternSize);
            }

            if (note->position != newPosition) {   
                PIZNote *newNote = NULL;
                long    values[PIZ_SEQUENCE_NOTE_SIZE + 1];
                
                values[PIZ_SEQUENCE_POSITION]       = newPosition;
                values[PIZ_SEQUENCE_PITCH]          = note->data[PIZ_PITCH];
                values[PIZ_SEQUENCE_VELOCITY]       = note->data[PIZ_VELOCITY];
                values[PIZ_SEQUENCE_DURATION]       = note->data[PIZ_DURATION];
                values[PIZ_SEQUENCE_CHANNEL]        = note->data[PIZ_CHANNEL];
                values[PIZ_SEQUENCE_IS_SELECTED]    = note->isSelected;
                values[PIZ_SEQUENCE_IS_MARKED]      = false;
                values[PIZ_SEQUENCE_NOTE_SIZE]      = note->originPosition;
                
                if (newNote = pizSequenceAddNote (x, values, PIZ_SEQUENCE_ADD_FLAG_ORIGIN)) {
                    if (note == x->markedNote) {
                            x->markedNote = NULL;
                        }
                        
                    if (!(pizLinklistRemoveByPtr (x->timeline[p], (void *)note))) {
                            x->count --;
                        }
                    
                    haveChanged = true;
                }
            }
                
            note = nextNote;
        }
    }
    
    if (haveChanged) {
        pizSequenceCleanMap (x);
    }
    
    PIZUNLOCK
    
    return haveChanged; 
}

bool pizSequenceApplyAmbitus (PIZSequence *x)
{
    long i, scale;
    bool haveChanged = false;

    PIZLOCK
    
    scale = pizGrowingArrayCount (x->scale);

    for (i = 0; i < pizGrowingArrayCount (x->map); i++) {   
        PIZNote *note       = NULL;
        PIZNote *nextNote   = NULL;
        
        long p = pizGrowingArrayValueAtIndex (x->map, i);
        
        pizLinklistPtrAtIndex (x->timeline[p], 0, (void **)&note);
            
        while (note) {
            long tempPitch;
            
            pizLinklistNextByPtr (x->timeline[p], (void *)note, (void **)&nextNote);
            
            tempPitch = pizSequenceMovePitchToAmbitus (x, note->data[PIZ_PITCH]);
            
            if (note->data[PIZ_PITCH] != tempPitch) {
                    haveChanged = true;
                    note->data[PIZ_PITCH] = tempPitch;
                }
                
            note = nextNote;
        }
    }
    
    PIZUNLOCK
    
    return haveChanged;
}

void pizSequenceTransposeOctave (PIZSequence *x, bool down)
{
    long i, step;
    
    if (down) {
        step = -PIZ_MAGIC_SCALE;
    } else {
        step = PIZ_MAGIC_SCALE;
    }
        
    PIZLOCK
        
    x->down = CLAMP (x->down + step, 0, PIZ_MAGIC_PITCH);
    x->up   = CLAMP (x->up + step, 0, PIZ_MAGIC_PITCH);
    
    for (i = 0; i < pizGrowingArrayCount (x->map); i++) {   
        PIZNote *note       = NULL;
        PIZNote *nextNote   = NULL;
        
        long p = pizGrowingArrayValueAtIndex (x->map, i);
        
        pizLinklistPtrAtIndex (x->timeline[p], 0, (void **)&note);
        
        while (note) {
            pizLinklistNextByPtr (x->timeline[p], (void *)note, (void **)&nextNote);

            note->data[PIZ_PITCH] = CLAMP (note->data[PIZ_PITCH] + step, 0, PIZ_MAGIC_PITCH);
            
            note = nextNote;
        }
    }
    
    PIZUNLOCK
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

bool pizSequenceIsAtEnd (PIZSequence *x)
{
    bool k = false;
    
    PIZLOCK
    
    if (x->index >= x->end) {
            k = true;
        }
    
    PIZUNLOCK
    
    return k;
}

void pizSequenceGoToStart (PIZSequence *x)
{
    PIZLOCK
    
    x->index = x->start;
    
    PIZUNLOCK
}

PIZError pizSequenceProceedStep (PIZSequence *x, PIZGrowingArray *a)
{
    long err = PIZ_ERROR;
    
    PIZLOCK
    
    if (x->index < x->start) {
            x->index = x->start;
        }
        
    if (x->index < x->end) {
    
        err = PIZ_GOOD;
                    
        if (a && (x->timeline[x->index]) && (pizLinklistCount (x->timeline[x->index]))) {
            long    scale;
            PIZNote *note       = NULL;
            PIZNote *nextNote   = NULL;
            
            scale = pizGrowingArrayCount (x->scale);
            
            pizLinklistPtrAtIndex (x->timeline[x->index], 0, (void **)&note);
            
            while (note) {
                long pitch;
                
                pizLinklistNextByPtr (x->timeline[x->index], (void *)note, (void **)&nextNote);
                
                pitch = note->data[PIZ_PITCH];
                
                if (scale) {
                        pitch += pizGrowingArrayValueAtIndex (x->scale, pitch % scale);
                    }
                
                if ((pitch >= x->down) && (pitch <= x->up)) {
                    long velocity       = note->data[PIZ_VELOCITY];
                    long noteChannel    = note->data[PIZ_CHANNEL];
                            
                    if (velocity) {
                            velocity += x->velocity;
                        } 
                    
                    if (noteChannel == PIZ_CHANNEL_NONE) {
                            noteChannel = x->channel;
                        }
                        
                    err |= pizGrowingArrayAppend (a, CLAMP (pitch, 0, PIZ_MAGIC_PITCH));
                    err |= pizGrowingArrayAppend (a, CLAMP (velocity, 0, PIZ_MAGIC_VELOCITY));
                    err |= pizGrowingArrayAppend (a, note->data[PIZ_DURATION]);
                    err |= pizGrowingArrayAppend (a, noteChannel);
                }
                
                note = nextNote;
            }
        }
        
        x->index ++;
    }
    
    PIZUNLOCK
    
    return err;
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

PIZNote *pizSequenceAddNote (PIZSequence *x, long *values, long modeFlags)
{
    PIZNote *newNote    = NULL;
    long    err         = PIZ_GOOD;
    long    position    = values[PIZ_SEQUENCE_POSITION];
    long    pitch       = CLAMP (values[PIZ_SEQUENCE_PITCH],    0, PIZ_MAGIC_PITCH);
    long    velocity    = CLAMP (values[PIZ_SEQUENCE_VELOCITY], 0, PIZ_MAGIC_VELOCITY);
    long    duration    = CLAMP (values[PIZ_SEQUENCE_DURATION], 1, PIZ_SEQUENCE_MAXIMUM_DURATION); 
    long    channel     = CLAMP (values[PIZ_SEQUENCE_CHANNEL],  0, PIZ_MAGIC_CHANNEL); 
    long    isSelected  = values[PIZ_SEQUENCE_IS_SELECTED];
    long    isMarked    = values[PIZ_SEQUENCE_IS_MARKED];
    
    if (modeFlags & PIZ_SEQUENCE_ADD_FLAG_SNAP) {
            position = MAX (((long)(position / (double)x->grid)) * x->grid, 0);
        }
    
    if (modeFlags & PIZ_SEQUENCE_ADD_FLAG_PATTERN) {
            long patternSize = pizGrowingArrayCount (x->pattern);  
            if (patternSize) {
                    long temp = pizSequenceSnapPositionToPattern (x, position, patternSize);
                    position = CLAMP (temp, 0, (PIZ_SEQUENCE_TIMELINE_SIZE - duration));
                }
        } 
    
    if (modeFlags & PIZ_SEQUENCE_ADD_FLAG_AMBITUS) {
            pitch = pizSequenceMovePitchToAmbitus (x, pitch);
        }
        
    if (modeFlags & PIZ_SEQUENCE_ADD_FLAG_UNSELECT) {
            isSelected = false;
            isMarked = false;
        }
                
    err |= (position < 0);
    err |= (position > (PIZ_SEQUENCE_TIMELINE_SIZE - MAX (duration, 1)));
    err |= (x->count >= PIZ_SEQUENCE_MAXIMUM_NOTES);
    
    if (modeFlags & PIZ_SEQUENCE_ADD_FLAG_CLIP) {
        err |= (position < x->start);
        err |= (position >= x->end);
        err |= (pitch < x->down);
        err |= (pitch > x->up);
    }
        
    if (!err && (newNote = (PIZNote *)malloc (sizeof(PIZNote)))) {
        newNote->flags              = PIZ_SEQUENCE_NOTE_FLAG_NONE;
        newNote->data[PIZ_PITCH]    = pitch;
        newNote->data[PIZ_VELOCITY] = velocity;
        newNote->data[PIZ_DURATION] = duration;
        newNote->data[PIZ_CHANNEL]  = channel;
        newNote->isSelected         = isSelected;
        newNote->position           = position;
    
        if (modeFlags & PIZ_SEQUENCE_ADD_FLAG_ORIGIN) {
            newNote->originPosition = values[PIZ_SEQUENCE_NOTE_SIZE];
        } else {
            newNote->originPosition = newNote->position;
        }
        
        if (!x->timeline[newNote->position]) {
            if (!(x->timeline[newNote->position] = pizLinklistNew ( ))) {
                    err |= PIZ_MEMORY;
                }
        }
        
        if (!err && !(pizItemset1024IsSetAtIndex (&x->mapFlags, newNote->position))) {
            if (!(err |= pizGrowingArrayAppend (x->map, newNote->position))) {
                    pizItemset1024SetAtIndex (&x->mapFlags, newNote->position);
                }
        }
                    
        if (!err && !(pizLinklistInsert (x->timeline[newNote->position], (void *)newNote))) {
            if (isMarked) {
                    x->markedNote = newNote;
                }
                        
            x->count ++;
        } else {
            free (newNote);
            newNote = NULL;
        }
    }
        
    return newNote;
}   

void pizSequenceCleanMap (PIZSequence *x)
{
    long i;
            
    pizItemset1024Clear  (&x->mapFlags);
    pizGrowingArrayClear (x->map);
                            
    for (i = 0; i < PIZ_SEQUENCE_TIMELINE_SIZE; i++) {
        if (x->timeline[i] && pizLinklistCount (x->timeline[i])) {
            pizItemset1024SetAtIndex (&x->mapFlags, i);
            pizGrowingArrayAppend    (x->map, i);
        }
    }
}

void pizSequenceClearNotes (PIZSequence *x)
{
    if (x->count) {
        long i;
        
        for (i = 0; i < pizGrowingArrayCount (x->map); i++) {
                long p = pizGrowingArrayValueAtIndex (x->map, i);
                pizLinklistClear (x->timeline[p]);
            }
        
        pizItemset1024Clear  (&x->mapFlags);
        pizGrowingArrayClear (x->map);
        
        x->count = 0;
        x->markedNote = NULL;
    }
}

long pizSequenceMovePitchToAmbitus (PIZSequence *x, long pitch)
{
    long scale, offset = 0;
    
    if (scale = pizGrowingArrayCount (x->scale)) {
            offset = pizGrowingArrayValueAtIndex (x->scale, pitch % scale);
        }

    pitch += offset;
            
    if (pitch < x->down) {
        while ((pitch < x->down) && (pitch < PIZ_MAGIC_PITCH)) {
            pitch += PIZ_MAGIC_SCALE;
        }
    } else if (pitch > x->up) {
        while ((pitch > x->up) && (pitch > 0)) {
            pitch -= PIZ_MAGIC_SCALE;
        }
    }
            
    pitch -= offset;
    
    return (CLAMP (pitch, 0, PIZ_MAGIC_PITCH));
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

PIZ_INLINE long pizSequenceSnapPositionToPattern (PIZSequence *x, long toSnapped, long patternSize)
{
    long j = MAX ((long)(toSnapped / (double)x->grid), 0);
    long k = j % patternSize;
    
    toSnapped = j * x->grid;
    toSnapped += pizGrowingArrayValueAtIndex (x->pattern, k) * x->grid;

    return toSnapped;
}

// -------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------:x