/**
 * \file    pizSequenceAttributes.h
 * \author  Jean Sapristi
 * \date    April 13, 2012.
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

#ifndef PIZ_SEQUENCE_ATTRIBUTES_H
#define PIZ_SEQUENCE_ATTRIBUTES_H

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#include "pizEvent.h"

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

void    pizSequenceSetChance        (PIZSequence *x, const PIZEvent *event);
void    pizSequenceSetVelocity      (PIZSequence *x, const PIZEvent *event);
void    pizSequenceSetChannel       (PIZSequence *x, const PIZEvent *event);
void    pizSequenceSetCell          (PIZSequence *x, const PIZEvent *event);
void    pizSequenceSetGrid          (PIZSequence *x, const PIZEvent *event);
void    pizSequenceSetNoteValue     (PIZSequence *x, const PIZEvent *event);

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

PIZError pizSequenceSetScale        (PIZSequence *x, const PIZEvent *event);
PIZError pizSequenceSetPattern      (PIZSequence *x, const PIZEvent *event); //

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#ifdef PIZ_EXTERN_INLINE

#endif // PIZ_EXTERN_INLINE

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#endif // PIZ_SEQUENCE_ATTRIBUTES_H