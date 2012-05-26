/*
 *  tralalaSymbols.h
 *
 *  nicolas.danet@free.fr
 *
 */

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#ifndef PIZ_TRALALA_SYMBOLS_H
#define PIZ_TRALALA_SYMBOLS_H

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#include "ext.h"
#include "pizSequence.h"

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

void tralala_symbolsInit ( );

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

PIZError tralala_keyWithSymbol          (const t_symbol *s, long *value);
PIZError tralala_scaleWithSymbol        (const t_symbol *s, long *value);
PIZError tralala_valueWithSymbol        (const t_symbol *s, long *value);
PIZError tralala_optionWithSymbol       (const t_symbol *s, long *value);
PIZError tralala_noteValueWithSymbol    (const t_symbol *s, long *value);

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#endif // PIZ_TRALALA_SYMBOLS_H