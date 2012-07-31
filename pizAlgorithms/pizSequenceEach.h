/**
 * \file    pizSequenceEach.h
 * \author  Jean Sapristi
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

#ifndef PIZ_SEQUENCE_EACH_H
#define PIZ_SEQUENCE_EACH_H

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#include "pizEvent.h"
#include "pizSequence.h"

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#define PIZ_SEQUENCE_FLAG_RANDOM        1UL
#define PIZ_SEQUENCE_FLAG_FILL          2UL
#define PIZ_SEQUENCE_FLAG_NEARBY        4UL
#define PIZ_SEQUENCE_FLAG_BACKWARD      8UL
#define PIZ_SEQUENCE_FLAG_FORWARD       16UL
#define PIZ_SEQUENCE_FLAG_PATTERN       32UL

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
PIZ_START_C_LINKAGE

PIZ_LOCAL void pizSequenceForEach               (PIZSequence *x, PIZMethod method, const PIZEvent *e, ulong f);

PIZ_LOCAL void pizSequenceEachRemove            (PIZSequence *x, PIZNote *note, const PIZEvent *e, ulong flag);
PIZ_LOCAL void pizSequenceEachChange            (PIZSequence *x, PIZNote *note, const PIZEvent *e, ulong flag);
PIZ_LOCAL void pizSequenceEachMove              (PIZSequence *x, PIZNote *note, const PIZEvent *e, ulong flag);
PIZ_LOCAL void pizSequenceEachCycle             (PIZSequence *x, PIZNote *note, const PIZEvent *e, ulong flag);
PIZ_LOCAL void pizSequenceEachDump              (PIZSequence *x, PIZNote *note, const PIZEvent *e, ulong flag);
PIZ_LOCAL void pizSequenceEachFillTempHash      (PIZSequence *x, PIZNote *note, const PIZEvent *e, ulong flag);
PIZ_LOCAL void pizSequenceEachFillTempNotes     (PIZSequence *x, PIZNote *note, const PIZEvent *e, ulong flag);

PIZ_END_C_LINKAGE
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#endif // PIZ_SEQUENCE_EACH_H