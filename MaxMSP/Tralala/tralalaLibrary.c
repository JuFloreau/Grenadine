/*
 *  tralalaLibrary.c
 *
 *  nicolas.danet@free.fr
 *
 */

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#include "tralalaLibrary.h"

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

extern t_tllSymbols tll_table;

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#define TINY 2

#define TLL_PIXELS_PER_STEP     2.
#define TLL_PIXELS_PER_SEMITONE 24.

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark-

PIZ_LOCAL void symbolWithTag    (t_symbol **s, long tag);
PIZ_LOCAL void tagWithSymbol    (long *tag, t_symbol *s);

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -
#pragma mark ---
#pragma mark -

static t_quickmap *tll_code;
static t_quickmap *tll_type;
static t_quickmap *tll_length;
static t_quickmap *tll_direction;
static t_quickmap *tll_select;
static t_quickmap *tll_key;
static t_quickmap *tll_notification;

void tralala_parseInit(t_tllSymbols *table)
{
//
tll_code         = (t_quickmap *)quickmap_new( );
tll_type         = (t_quickmap *)quickmap_new( );
tll_length       = (t_quickmap *)quickmap_new( );
tll_direction    = (t_quickmap *)quickmap_new( );
tll_key          = (t_quickmap *)quickmap_new( );
tll_select       = (t_quickmap *)quickmap_new( );
tll_notification = (t_quickmap *)quickmap_new( );

table->end           = gensym("end");
table->clear         = gensym("clear");
table->tralala       = gensym("tralala");
table->untitled      = gensym("untitled");
table->run           = gensym("run");
table->note          = gensym("note");
table->text          = gensym("text");
table->zone          = gensym("zone");
table->background    = gensym("background");
table->xoffset       = gensym("xoffset");
table->yoffset       = gensym("yoffset");
table->color         = gensym("color");
table->attr_modified = gensym("attr_modified");
table->getname       = gensym("getname");
table->patching_rect = gensym("patching_rect");

quickmap_add(tll_code, gensym("bpm"),                     (void *)(TINY + PIZ_EVENT_BPM));
quickmap_add(tll_code, gensym("learn"),                   (void *)(TINY + PIZ_EVENT_LEARN));
quickmap_add(tll_code, gensym("list"),                    (void *)(TINY + PIZ_EVENT_LEARN));
quickmap_add(tll_code, gensym("forget"),                  (void *)(TINY + PIZ_EVENT_FORGET));
quickmap_add(tll_code, gensym("dump"),                    (void *)(TINY + PIZ_EVENT_DUMP));
quickmap_add(tll_code, gensym("chance"),                  (void *)(TINY + PIZ_EVENT_CHANCE));
quickmap_add(tll_code, gensym("velocity"),                (void *)(TINY + PIZ_EVENT_VELOCITY));
quickmap_add(tll_code, gensym("channel"),                 (void *)(TINY + PIZ_EVENT_CHANNEL));
quickmap_add(tll_code, gensym("chord"),                   (void *)(TINY + PIZ_EVENT_CHORD));
quickmap_add(tll_code, gensym("cell"),                    (void *)(TINY + PIZ_EVENT_CELL));
quickmap_add(tll_code, gensym("value"),                   (void *)(TINY + PIZ_EVENT_VALUE));
quickmap_add(tll_code, gensym("scale"),                   (void *)(TINY + PIZ_EVENT_SCALE));
quickmap_add(tll_code, gensym("pattern"),                 (void *)(TINY + PIZ_EVENT_PATTERN));
quickmap_add(tll_code, gensym("note"),                    (void *)(TINY + PIZ_EVENT_NOTE));
quickmap_add(tll_code, gensym("zone"),                    (void *)(TINY + PIZ_EVENT_ZONE));
quickmap_add(tll_code, gensym("clear"),                   (void *)(TINY + PIZ_EVENT_CLEAR));
quickmap_add(tll_code, gensym("clean"),                   (void *)(TINY + PIZ_EVENT_CLEAN));
quickmap_add(tll_code, gensym("rotate"),                  (void *)(TINY + PIZ_EVENT_ROTATE));
quickmap_add(tll_code, gensym("scramble"),                (void *)(TINY + PIZ_EVENT_SCRAMBLE));
quickmap_add(tll_code, gensym("sort"),                    (void *)(TINY + PIZ_EVENT_SORT));
quickmap_add(tll_code, gensym("change"),                  (void *)(TINY + PIZ_EVENT_CHANGE));
quickmap_add(tll_code, gensym("fill"),                    (void *)(TINY + PIZ_EVENT_FILL));
quickmap_add(tll_code, gensym("kill"),                    (void *)(TINY + PIZ_EVENT_KILL));
quickmap_add(tll_code, gensym("cycle"),                   (void *)(TINY + PIZ_EVENT_CYCLE));
quickmap_add(tll_code, gensym("zoulou"),                  (void *)(TINY + PIZ_EVENT_ZOULOU));
quickmap_add(tll_code, gensym("romeo"),                   (void *)(TINY + PIZ_EVENT_ROMEO));
quickmap_add(tll_code, gensym("juliet"),                  (void *)(TINY + PIZ_EVENT_JULIET));

quickmap_add(tll_type, gensym("none"),                    (void *)(TINY + PIZ_MODE_NONE));
quickmap_add(tll_type, gensym("ionian"),                  (void *)(TINY + PIZ_IONIAN));
quickmap_add(tll_type, gensym("dorian"),                  (void *)(TINY + PIZ_DORIAN));
quickmap_add(tll_type, gensym("phrygian"),                (void *)(TINY + PIZ_PHRYGIAN));
quickmap_add(tll_type, gensym("lydian"),                  (void *)(TINY + PIZ_LYDIAN));
quickmap_add(tll_type, gensym("mixolydian"),              (void *)(TINY + PIZ_MIXOLYDIAN));
quickmap_add(tll_type, gensym("aeolian"),                 (void *)(TINY + PIZ_AEOLIAN));
quickmap_add(tll_type, gensym("locrian"),                 (void *)(TINY + PIZ_LOCRIAN));
quickmap_add(tll_type, gensym("natural"),                 (void *)(TINY + PIZ_NATURAL));
quickmap_add(tll_type, gensym("harmonic"),                (void *)(TINY + PIZ_HARMONIC));
quickmap_add(tll_type, gensym("melodic"),                 (void *)(TINY + PIZ_MELODIC));
quickmap_add(tll_type, gensym("whole_tone"),              (void *)(TINY + PIZ_WHOLE_TONE));
quickmap_add(tll_type, gensym("pentatonic_major"),        (void *)(TINY + PIZ_PENTATONIC_MAJOR));
quickmap_add(tll_type, gensym("pentatonic_minor"),        (void *)(TINY + PIZ_PENTATONIC_MINOR));
quickmap_add(tll_type, gensym("octatonic_half_whole"),    (void *)(TINY + PIZ_OCTATONIC_HALF_WHOLE));
quickmap_add(tll_type, gensym("octatonic_whole_half"),    (void *)(TINY + PIZ_OCTATONIC_WHOLE_HALF));
quickmap_add(tll_type, gensym("7th_major"),               (void *)(TINY + PIZ_SEVENTH_MAJOR));
quickmap_add(tll_type, gensym("7th_minor"),               (void *)(TINY + PIZ_SEVENTH_MINOR));
quickmap_add(tll_type, gensym("7th_dominant"),            (void *)(TINY + PIZ_SEVENTH_DOMINANT));
quickmap_add(tll_type, gensym("7th_major_sixth"),         (void *)(TINY + PIZ_SEVENTH_MAJOR_SIXTH));
quickmap_add(tll_type, gensym("7th_minor_sixth"),         (void *)(TINY + PIZ_SEVENTH_MINOR_SIXTH));
quickmap_add(tll_type, gensym("7th_half_diminished"),     (void *)(TINY + PIZ_SEVENTH_HALF_DIMINISHED));
quickmap_add(tll_type, gensym("7th_diminished"),          (void *)(TINY + PIZ_SEVENTH_DIMINISHED));
quickmap_add(tll_type, gensym("7th_dominant_suspended"),  (void *)(TINY + PIZ_SEVENTH_SUSPENDED));
quickmap_add(tll_type, gensym("7th_dominant_sharp_five"), (void *)(TINY + PIZ_SEVENTH_SHARP_FIVE));
quickmap_add(tll_type, gensym("7th_dominant_flat_five"),  (void *)(TINY + PIZ_SEVENTH_FLAT_FIVE));

quickmap_add(tll_length, gensym("none"),                  (void *)(TINY + PIZ_NOTE_NONE));
quickmap_add(tll_length, gensym("whole"),                 (void *)(TINY + PIZ_WHOLE_NOTE));
quickmap_add(tll_length, gensym("half"),                  (void *)(TINY + PIZ_HALF_NOTE));
quickmap_add(tll_length, gensym("quarter"),               (void *)(TINY + PIZ_QUARTER_NOTE));
quickmap_add(tll_length, gensym("eighth"),                (void *)(TINY + PIZ_EIGHTH_NOTE));
quickmap_add(tll_length, gensym("sixteenth"),             (void *)(TINY + PIZ_SIXTEENTH_NOTE));
quickmap_add(tll_length, gensym("thirty_second"),         (void *)(TINY + PIZ_THIRTY_SECOND_NOTE));
quickmap_add(tll_length, gensym("whole_triplet"),         (void *)(TINY + PIZ_WHOLE_NOTE_TRIPLET));
quickmap_add(tll_length, gensym("half_triplet"),          (void *)(TINY + PIZ_HALF_NOTE_TRIPLET));
quickmap_add(tll_length, gensym("quarter_triplet"),       (void *)(TINY + PIZ_QUARTER_NOTE_TRIPLET));
quickmap_add(tll_length, gensym("eighth_triplet"),        (void *)(TINY + PIZ_EIGHTH_NOTE_TRIPLET));
quickmap_add(tll_length, gensym("sixteenth_triplet"),     (void *)(TINY + PIZ_SIXTEENTH_NOTE_TRIPLET));
quickmap_add(tll_length, gensym("thirty_second_triplet"), (void *)(TINY + PIZ_THIRTY_SECOND_NOTE_TRIPLET));
quickmap_add(tll_length, gensym("whole_dotted"),          (void *)(TINY + PIZ_WHOLE_NOTE_DOTTED));
quickmap_add(tll_length, gensym("half_dotted"),           (void *)(TINY + PIZ_HALF_NOTE_DOTTED));
quickmap_add(tll_length, gensym("quarter_dotted"),        (void *)(TINY + PIZ_QUARTER_NOTE_DOTTED));
quickmap_add(tll_length, gensym("eighth_dotted"),         (void *)(TINY + PIZ_EIGHTH_NOTE_DOTTED));
quickmap_add(tll_length, gensym("sixteenth_dotted"),      (void *)(TINY + PIZ_SIXTEENTH_NOTE_DOTTED));

quickmap_add(tll_direction, gensym("up"),                 (void *)(TINY + PIZ_UP)); 
quickmap_add(tll_direction, gensym("down"),               (void *)(TINY + PIZ_DOWN));

quickmap_add(tll_select, gensym("pitch"),                 (void *)(TINY + PIZ_VALUE_PITCH));
quickmap_add(tll_select, gensym("velocity"),              (void *)(TINY + PIZ_VALUE_VELOCITY));
quickmap_add(tll_select, gensym("duration"),              (void *)(TINY + PIZ_VALUE_DURATION));
quickmap_add(tll_select, gensym("channel"),               (void *)(TINY + PIZ_VALUE_CHANNEL));

quickmap_add(tll_key, gensym("C"),                        (void *)(TINY + PIZ_KEY_C));
quickmap_add(tll_key, gensym("C#"),                       (void *)(TINY + PIZ_KEY_C_SHARP));
quickmap_add(tll_key, gensym("D"),                        (void *)(TINY + PIZ_KEY_D));
quickmap_add(tll_key, gensym("D#"),                       (void *)(TINY + PIZ_KEY_D_SHARP));
quickmap_add(tll_key, gensym("E"),                        (void *)(TINY + PIZ_KEY_E));
quickmap_add(tll_key, gensym("F"),                        (void *)(TINY + PIZ_KEY_F));
quickmap_add(tll_key, gensym("F#"),                       (void *)(TINY + PIZ_KEY_F_SHARP));
quickmap_add(tll_key, gensym("G"),                        (void *)(TINY + PIZ_KEY_G));
quickmap_add(tll_key, gensym("G#"),                       (void *)(TINY + PIZ_KEY_G_SHARP));
quickmap_add(tll_key, gensym("A"),                        (void *)(TINY + PIZ_KEY_A));
quickmap_add(tll_key, gensym("A#"),                       (void *)(TINY + PIZ_KEY_A_SHARP));
quickmap_add(tll_key, gensym("B"),                        (void *)(TINY + PIZ_KEY_B));

quickmap_add(tll_notification, gensym("bpm"),             (void *)(TINY + PIZ_EVENT_CHANGED_BPM));
quickmap_add(tll_notification, gensym("chance"),          (void *)(TINY + PIZ_EVENT_CHANGED_CHANCE));
quickmap_add(tll_notification, gensym("velocity"),        (void *)(TINY + PIZ_EVENT_CHANGED_VELOCITY));
quickmap_add(tll_notification, gensym("channel"),         (void *)(TINY + PIZ_EVENT_CHANGED_CHANNEL));
quickmap_add(tll_notification, gensym("chord"),           (void *)(TINY + PIZ_EVENT_CHANGED_CHORD));
quickmap_add(tll_notification, gensym("cell"),            (void *)(TINY + PIZ_EVENT_CHANGED_CELL));
quickmap_add(tll_notification, gensym("value"),           (void *)(TINY + PIZ_EVENT_CHANGED_VALUE));
quickmap_add(tll_notification, gensym("scale"),           (void *)(TINY + PIZ_EVENT_CHANGED_SCALE));
quickmap_add(tll_notification, gensym("pattern"),         (void *)(TINY + PIZ_EVENT_CHANGED_PATTERN)); 
quickmap_add(tll_notification, gensym("zone"),            (void *)(TINY + PIZ_EVENT_CHANGED_ZONE));
//
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

void tralala_parseDictionary(t_tll *x, t_dictionary *d)
{
    long i, n = 0;
    t_symbol **keys = NULL;
    
    if (!(dictionary_getkeys(d, &n, &keys))) {
    //
    for (i = 0; i < n; i++) {
    //
    long k;
    t_atom *data = NULL;
    
    if (!dictionary_getatoms(d, (*(keys + i)), &k, &data)) {
        if (atom_gettype(data) == A_SYM) {
            tralala_parseMessage(x, atom_getsym(data), k - 1, data + 1);
        }
    }
    //
    }
    
    dictionary_freekeys(d, n, keys);
    //
    }
}

void tralala_parseMessage(t_tll *x, t_symbol *s, long argc, t_atom *argv)
{
    PIZTime time;
    PIZEventCode code = 0;
        
    if (!(quickmap_lookup_key1(tll_code, (void *)s, (void **)&code))) {
    //
    long i, k = 0, msg = 0;
    long data[PIZ_EVENT_DATA_SIZE] = { 0 };
    PIZEvent *event = NULL;
     
    code -= TINY;
    
    if (msg = ((code == PIZ_EVENT_ROTATE)   ||
               (code == PIZ_EVENT_SCRAMBLE) ||
               (code == PIZ_EVENT_SORT)     ||
               (code == PIZ_EVENT_CHANGE)   ||
               (code == PIZ_EVENT_FILL)     ||
               (code == PIZ_EVENT_CYCLE)))  { k = 1; }
                     
    for (i = 0; i < argc; i++) {
    //
    if (atom_gettype(argv + i) == A_SYM) {
    //
    long t, j = 0, p = 0;
     
    if ((code == PIZ_EVENT_SCALE) || (code == PIZ_EVENT_CYCLE)) {
        if (!(quickmap_lookup_key1(tll_type, (void *)atom_getsym(argv + i), (void **)&t))) {
            j = t - TINY; p = 1; 
        } else if (!(quickmap_lookup_key1(tll_key, (void *)atom_getsym(argv + i), (void **)&t))) {
            j = t - TINY;
        }
        
    } else if ((code == PIZ_EVENT_CELL) || (code == PIZ_EVENT_VALUE)) {
        if (!(quickmap_lookup_key1(tll_length, (void *)atom_getsym(argv + i), (void **)&t))) {
            j = t - TINY; p = 0;
        } else {
            continue;
        }
        
    } else if (msg) {
        if (!(quickmap_lookup_key1(tll_direction, (void *)atom_getsym(argv + i), (void **)&t))) {
            j = t - TINY; p = 1;
        } else if (!(quickmap_lookup_key1(tll_select, (void *)atom_getsym(argv + i), (void **)&t))) {
            j = t - TINY;
        }
        
    } else {
        continue;
    }

    data[p] = j;
    k = MAX(p + 1, k);
    //
    }
    //
    }
    
    for (i = 0; i < argc; i++) {
    //
    if ((k < PIZ_EVENT_DATA_SIZE) && (atom_gettype(argv + i) == A_LONG)) {
        data[k] = atom_getlong(argv + i);
        k++;
    }
    //
    }
    
    if (event = pizEventNew(code)) {
        pizTimeSet(&time);
        pizEventSetTime(event, &time);
        pizEventSetData(event, k, data);
        pizEventSetIdentifier(event, x->identifier);
        pizAgentDoEvent(x->agent, event);
    }
    //
    }
}

void tralala_parseNotification(t_tll *x, PIZEvent *event)
{
    long i, k = 0;
    long *ptr;
    t_atom data[PIZ_EVENT_DATA_SIZE + 1];
    t_symbol *s = NULL;
    PIZEventCode code;
    
    pizEventCode(event, &code);
    pizEventData(event, &k, &ptr);
    
    for (i = 0; i < k; i++) {
        atom_setlong(data + i + 1, *(ptr + i));
    }
    
    if (!(quickmap_lookup_key2(tll_notification, (void *)(code + TINY), (void **)&s))) {
    
        if (code == PIZ_EVENT_CHANGED_SCALE) {
            t_symbol *sym1 = NULL;
            t_symbol *sym2 = NULL;

            quickmap_lookup_key2(tll_key,  (void *)((*(ptr + 0)) + TINY), (void **)&sym1);
            quickmap_lookup_key2(tll_type, (void *)((*(ptr + 1)) + TINY), (void **)&sym2);

            atom_setsym(data + 1, sym1);
            atom_setsym(data + 2, sym2);
        }

        atom_setsym(data, s);
        dictionary_appendatoms(x->current, s, k + 1, data);

        if (code == PIZ_EVENT_CHANGED_ZONE) {
            jbox_invalidate_layer((t_object*)x, NULL, TLL_SYM_ZONE);
        } 
    
    } else {
        symbolWithTag(&s, ptr[PIZ_EVENT_DATA_TAG]);
            
        if (code == PIZ_EVENT_NOTE_REMOVED) {
            dictionary_deleteentry(x->current, s);
            dictionary_deleteentry(x->selected, s);
        } else {
            atom_setsym(data, TLL_SYM_NOTE);
            dictionary_appendatoms(x->current, s, k - 1, data);
        }
        
        jbox_invalidate_layer((t_object*)x, NULL, TLL_SYM_NOTE);
    }
    
    jbox_redraw((t_jbox *)x);
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

void tralala_paintBackground(t_tll *x, t_object *pv)
{
    double w = (PIZ_SEQUENCE_SIZE_TIMELINE * TLL_PIXELS_PER_STEP);
    double h = ((PIZ_MAGIC_PITCH + 1) * TLL_PIXELS_PER_SEMITONE);
    t_jgraphics *g = NULL;

    if (g = jbox_start_layer((t_object *)x, pv, TLL_SYM_BACKGROUND, w, h)) {
        jgraphics_set_source_jrgba(g, &x->color);
        jgraphics_rectangle_draw_fast(g, 0., 0., w, h, 1.);
        jbox_end_layer((t_object*)x, pv, TLL_SYM_BACKGROUND);
    }
        
    jbox_paint_layer((t_object *)x, pv, TLL_SYM_BACKGROUND, -x->offsetX, -x->offsetY);
}

void tralala_paintCurrent(t_tll *x, t_object *pv)
{

}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -
#pragma mark ---
#pragma mark -

void symbolWithTag(t_symbol **s, long tag)
{
    char string[4];
    snprintf(string, 4, "%ld", tag);
    string[3] = 0;
    (*s) = gensym(string);
}

void tagWithSymbol(long *tag, t_symbol *s)
{
    (*tag) = atoi(s->s_name);
}

// -------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------:x