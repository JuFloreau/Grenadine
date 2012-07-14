/*
 *  tralalaUser.c
 *
 *  nicolas.danet@free.fr
 *
 */

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#include "tralalaUser.h"
#include "tralalaParse.h"
#include "tralalaPaint.h"

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

extern t_tllSymbols tll_table;

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

PIZ_LOCAL void      tralala_swapNote    (t_tll *x, t_symbol *s);
PIZ_LOCAL bool      tralala_insideLasso (t_tll *x, t_symbol *s);
PIZ_LOCAL bool      tralala_grabNotes   (t_tll *x);
PIZ_LOCAL void      tralala_addNote     (t_tll *x);
PIZ_LOCAL long      tralala_hitZone     (t_tll *x);
PIZ_LOCAL t_symbol  *tralala_hitNote    (t_tll *x);

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -
#pragma mark ---
#pragma mark -

void tralala_key(t_tll *x, t_object *pv, long keycode, long m, long textcharacter)
{
	;
}

void tralala_wheel(t_tll *x, t_object *view, t_pt pt, long m, double x_inc, double y_inc)
{
    long h = object_attr_getlong(x, TLL_SYM_XOFFSET) - (x_inc * 100);
    long v = object_attr_getlong(x, TLL_SYM_YOFFSET) - (y_inc * 100);
        
    object_attr_setlong(x, TLL_SYM_XOFFSET, h);
    object_attr_setlong(x, TLL_SYM_YOFFSET, v);
}

void tralala_down(t_tll *x, t_object *pv, t_pt pt, long m)
{	
    x->cursor = pt;
    
    TLL_LOCK
    
    if (!(m & eShiftKey)) {
        dictionary_clear(x->status);
    } else {
        x->flags |= TLL_FLAG_SHIFT;
    }
    
    if (m & eCommandKey) {
        tralala_addNote(x);
        
    } else if (m & eControlKey) {
        long k;
        if (k = tralala_hitZone(x)) {
            dictionary_appendlong(x->status, TLL_SYM_ZONE, k);
        }
    
    } else {
        t_symbol *s = NULL;
        if (s = tralala_hitNote(x)) {
            tralala_swapNote(x, s);
        } else {
            x->flags |= TLL_FLAG_LASSO;
        }
    }
    
    TLL_UNLOCK
    
    x->origin = pt;
        
    TLL_DIRTY_ZONE 
    TLL_DIRTY_NOTES_DRAW  
}

void tralala_move(t_tll *x, t_object *pv, t_pt pt, long m)
{
    x->cursor = pt; 
    TLL_DRAW
}

void tralala_drag(t_tll *x, t_object *pv, t_pt pt, long m)
{
    x->cursor = pt;
        
    if (x->flags & TLL_FLAG_LASSO) {
    //
    bool k;
        
    TLL_LOCK
    k = tralala_grabNotes(x);
    TLL_UNLOCK
     
    if (k) {
        TLL_DIRTY_NOTES
    }
    
    TLL_DIRTY_LASSO_DRAW
    //
    }
}

void tralala_up(t_tll *x, t_object *pv, t_pt pt, long m)
{
    if (x->flags & TLL_FLAG_LASSO) {
        TLL_DIRTY_LASSO_DRAW
    }
    
    x->flags = TLL_FLAG_NONE;
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -
#pragma mark ---
#pragma mark -

void tralala_swapNote(t_tll *x, t_symbol *s)
{
    if (dictionary_hasentry(x->status, s)) {
        t_symbol *last = NULL;
        dictionary_getsym(x->status, TLL_SYM_LAST, &last);
        if (s == last) { dictionary_deleteentry(x->status, TLL_SYM_LAST); }
        dictionary_deleteentry(x->status, s);
        
    } else {
        dictionary_appendsym(x->status, TLL_SYM_LAST, s);
        dictionary_appendlong(x->status, s, TLL_SELECTED);
    }
}

bool tralala_insideLasso(t_tll *x, t_symbol *s)
{
    return false;
}

bool tralala_grabNotes(t_tll *x)
{
    long i, n;
    bool draw = false;
    t_symbol **keys = NULL;
    
    if (!(dictionary_getkeys(x->current, &n, &keys))) {
    //
    long argc;
    t_atom *argv = NULL;
    
    for (i = 0; i < n; i++) {
        if (!(dictionary_getatoms(x->current, (*(keys + i)), &argc, &argv))) { 
        //
        if ((atom_getsym(argv) == TLL_SYM_NOTE)) {
            if (tralala_insideLasso(x, (*(keys + i)))) {
                ;
            }
        }
        //
        }
    }
    
    dictionary_freekeys(x->current, n, keys);
    //
    }
    
    return draw;
}

void tralala_addNote(t_tll *x)
{
    t_atom a[2];
    
    atom_setlong(a, X_TO_POSITION(x->cursor.x));
    atom_setlong(a + 1, Y_TO_PITCH(x->cursor.y));
    
    tralala_parseMessage(x, TLL_SYM_NOTE, 2, a);
}

long tralala_hitZone(t_tll *x)
{
    long argc, k = 0;
    t_atom *argv = NULL;
    long position = X_TO_POSITION(x->cursor.x);
    long pitch = Y_TO_PITCH(x->cursor.y);
    
    if (!(dictionary_getatoms(x->current, TLL_SYM_ZONE, &argc, &argv))) {
    //
    if (position < atom_getlong(argv + 1)) { 
        k = TLL_SELECTED_START;
         
    } else if (position > atom_getlong(argv + 2)) { 
        k = TLL_SELECTED_END;
        
    } else if (pitch < atom_getlong(argv + 3)) { 
        k = TLL_SELECTED_DOWN;
        
    } else if (pitch > atom_getlong(argv + 4)) { 
        k = TLL_SELECTED_UP;
        
    } else {
        k = TLL_SELECTED;
    }
    //
    }
    
    return k;
}

t_symbol *tralala_hitNote(t_tll *x)
{
    long i, n;
    t_symbol *note = NULL;
    t_symbol **keys = NULL;
    long position = X_TO_POSITION(x->cursor.x - 1.);
    long pitch = Y_TO_PITCH(x->cursor.y - 1.);
    
    if (!(dictionary_getkeys(x->current, &n, &keys))) {
    //
    long argc;
    t_atom *argv = NULL;
    
    for (i = 0; i < n; i++) {
        if (!(dictionary_getatoms(x->current, (*(keys + i)), &argc, &argv))) { 
        //
        if ((atom_getsym(argv) == TLL_SYM_NOTE)) {
            long p = atom_getlong(argv + 2);
            long a = atom_getlong(argv + 1);
            long b = a + atom_getlong(argv + 4);
            if ((pitch == p) && (position >= a) && (position <= b)) {
                note = (*(keys + i));
                break;
            }
        }
        //
        }
    }
    
    dictionary_freekeys(x->current, n, keys);
    //
    }
    
    return note;
}

// -------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------:x