/*
 *  tralalaParse.h
 *
 *  nicolas.danet@free.fr
 *
 */

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#ifndef TLL_TRALALA_PARSE_H
#define TLL_TRALALA_PARSE_H

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#include "tralala.h"

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

typedef struct _tllSymbols {
    t_symbol *play;
    t_symbol *note;
    t_symbol *clear;
    t_symbol *tralala;
    t_symbol *current;
    t_symbol *restore;
    } t_tllSymbols;

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

#define TLL_SYM_PLAY        (tll_table.play)
#define TLL_SYM_NOTE        (tll_table.note)
#define TLL_SYM_CLEAR       (tll_table.clear)
#define TLL_SYM_TRALALA     (tll_table.tralala)
#define TLL_SYM_CURRENT     (tll_table.current)
#define TLL_SYM_RESTORE     (tll_table.restore)

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

void tralala_parseInit          (t_tllSymbols *table);

void tralala_parseDictionary    (t_tll *x, t_dictionary *d);
void tralala_parseMessage       (t_tll *x, t_symbol *s, long argc, t_atom *argv);
void tralala_parseNotification  (t_tll *x, PIZEvent *event);
      
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#endif // TLL_TRALALA_PARSE_H