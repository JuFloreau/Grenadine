/**
 * \file    pizSequenceInterface.h
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

#ifndef PIZ_SEQUENCE_INTERFACE_H
#define PIZ_SEQUENCE_INTERFACE_H

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#include "pizSequence.h"

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

bool pizSequenceHasMarkedNote (PIZSequence *x);
long pizSequenceMarkedNoteValue (PIZSequence *x, PIZSelector selector);
void pizSequenceChangeMarkedNoteValue (PIZSequence *x, PIZSelector selector, long value);

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

void pizSequenceSetTempZoneByZone (PIZSequence *x);
bool pizSequenceSetTempZoneWithCoordinates (PIZSequence *x, const PIZCoordinates *c, long side);
bool pizSequenceMoveTempZoneWithDelta (PIZSequence *x, long pitch, long position);

PIZError pizSequenceTempZoneToArray (PIZSequence *x, PIZGrowingArray *a);

PIZError pizSequenceSetZoneByTempZone (PIZSequence *x);

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

void pizSequenceSelectAllNotes (PIZSequence *x);
void pizSequenceUnselectAllNotes (PIZSequence *x);

long pizSequenceSelectNoteWithCoordinates (PIZSequence *x, const PIZCoordinates *c);
long pizSequenceInvertNoteWithCoordinates (PIZSequence *x, const PIZCoordinates *c);

void pizSequenceInitLasso (PIZSequence *x);
long pizSequenceSelectNotesWithLasso (PIZSequence *x, const PIZCoordinates *m, const PIZCoordinates *n, bool r);

PIZError pizSequenceRemoveSelectedNotes (PIZSequence *x);

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

PIZ_LOCAL PIZ_INLINE void pizSequenceUnselectNotes (PIZSequence *x);
PIZ_LOCAL PIZ_INLINE long pizSequenceSnapRound (PIZSequence *x, long toSnapped);

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#endif // PIZ_SEQUENCE_INTERFACE_H