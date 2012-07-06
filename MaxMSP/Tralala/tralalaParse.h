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
#include "ext_quickmap.h"

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

#define TLL_SYM_END         (tll_table.end)
#define TLL_SYM_RUN         (tll_table.run)
#define TLL_SYM_NOTE        (tll_table.note)
#define TLL_SYM_TEXT        (tll_table.text)
#define TLL_SYM_CLEAR       (tll_table.clear)
#define TLL_SYM_TRALALA     (tll_table.tralala)
#define TLL_SYM_UNTITLED    (tll_table.untitled)
#define TLL_SYM_X_OFFSET    (tll_table.xoffset)
#define TLL_SYM_Y_OFFSET    (tll_table.yoffset)

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

typedef struct _tllSymbols {
    t_symbol *end;
    t_symbol *run;
    t_symbol *note;
    t_symbol *text;
    t_symbol *clear;
    t_symbol *tralala;
    t_symbol *untitled;
    t_symbol *xoffset;
    t_symbol *yoffset;
    } t_tllSymbols;

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