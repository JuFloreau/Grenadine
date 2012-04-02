/**
 * \file	pizSequenceLibrary.h
 * \author	Jean Sapristi
 * \date	April 2, 2012.
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

#ifndef PIZ_SEQUENCE_LIBRARY_H
#define PIZ_SEQUENCE_LIBRARY_H

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#include "pizSequence.h"

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

PIZError            pizSequenceSetZoneWithArray         (PIZSequence *x, const PIZGrowingArray *a);
PIZError            pizSequenceAddNotesWithArray        (PIZSequence *x, const PIZGrowingArray *a, long flags);

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

PIZ_LOCAL PIZNote   *pizSequenceAddNote                 (PIZSequence *x, long *values, long flags);

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

PIZ_LOCAL void      pizSequenceRemoveNote               (PIZSequence *x, PIZNote *note);
PIZ_LOCAL void      pizSequenceRemoveAllNotes           (PIZSequence *x);
PIZ_LOCAL void      pizSequenceMoveNote                 (PIZSequence *x, PIZNote *note, long newPosition);
PIZ_LOCAL void      pizSequenceMakeMap                  (PIZSequence *x);

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

PIZ_LOCAL long      pizSequenceMovePitchToAmbitus       (PIZSequence *x, long pitch);
PIZ_LOCAL long      pizSequenceSnapPositionToPattern    (PIZSequence *x, long toSnapped, long patternSize);

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#endif // PIZ_SEQUENCE_LIBRARY_H