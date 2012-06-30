/*
 *  tralala.c
 *
 *  nicolas.danet@free.fr
 *
 */

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#include "tralalaParse.h"
#include "jpatcher_api.h"

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

t_tllSymbols tll_table;

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

PIZ_LOCAL void tralala_send (t_tll *x, PIZEventCode code, long argc, t_atom *argv);

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -
#pragma mark ---
#pragma mark -

static t_class *tll_class;
static long identifier;

int main(void)
{	
    t_class	*c = NULL;
    
    c = class_new("tralala", (method)tralala_new, (method)tralala_free, sizeof(t_tll), 0L, A_GIMME, 0);

    class_addmethod(c, (method)tralala_jsave,      "appendtodictionary",   A_CANT,  0);
    class_addmethod(c, (method)tralala_assist,     "assist",               A_CANT,  0);
    class_addmethod(c, (method)tralala_play,       "bang",                 A_GIMME, 0);
    class_addmethod(c, (method)tralala_play,       "play",                 A_GIMME, 0);
    class_addmethod(c, (method)tralala_play,       "end",                  A_GIMME, 0);
    class_addmethod(c, (method)tralala_loop,       "loop",                 A_GIMME, 0);
    class_addmethod(c, (method)tralala_stop,       "stop",                 A_GIMME, 0);
    class_addmethod(c, (method)tralala_unloop,     "unloop",               A_GIMME, 0);
    class_addmethod(c, (method)tralala_list,       "list",                 A_GIMME, 0);
    class_addmethod(c, (method)tralala_anything,   "anything",             A_GIMME, 0);

    class_register(CLASS_BOX, c);

    tll_class = c;
    
    tralala_parseInit(&tll_table);

    return 0;
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

void *tralala_new(t_symbol *s, long argc, t_atom *argv)
{
    t_tll *x = NULL;

    if (x = (t_tll *)object_alloc(tll_class)) {
    //
    t_symbol *s = NULL;
    PIZError err = PIZ_ERROR;
    
    if (x->data = dictionary_new( )) {
    //
    t_dictionary *d = NULL;
    t_dictionary *t = NULL;
    
    err = PIZ_GOOD;
    x->flags = TLL_FLAG_NONE;
    
    if ((d = (t_dictionary *)gensym("#D")->s_thing) 
        && (dictionary_entryisdictionary(d, TLL_SYM_TRALALA))) {
        dictionary_getdictionary(d, TLL_SYM_TRALALA, (t_object **)&t);
        dictionary_copyunique(x->data, t);
            
    } else {
        x->flags |= TLL_FLAG_INIT;
    }
    
    if (!(dictionary_entryisdictionary(x->data, TLL_SYM_RESTORE)) 
        && (x->restore = dictionary_new( ))) {
        dictionary_appenddictionary(x->data, TLL_SYM_RESTORE,(t_object *)x->restore);
    }
    
    if (!(dictionary_entryisdictionary(x->data, TLL_SYM_CURRENT)) 
        && (x->current = dictionary_new( ))) {
        dictionary_appenddictionary(x->data, TLL_SYM_CURRENT, (t_object *)x->current);
    }
        
    err |= (dictionary_getdictionary(x->data, TLL_SYM_RESTORE, (t_object **)&x->restore)) != MAX_ERR_NONE;
    err |= (dictionary_getdictionary(x->data, TLL_SYM_CURRENT, (t_object **)&x->current)) != MAX_ERR_NONE;
    //
    }
    
    s = symbol_unique( );
    s->s_thing = (t_object *)x;
    atom_setsym(&x->link, s);
    
    x->identifier = ++identifier;
        
    if (!err && (x->agent = pizAgentNew(x->identifier))) {
        x->right       = bangout((t_object *)x);
        x->middleRight = outlet_new((t_object *)x, NULL);
        x->middleLeft  = outlet_new((t_object *)x, NULL);
        x->left        = listout((t_object *)x);
                
        pizAgentAttach(x->agent, (void *)x, (PIZMethod)tralala_callback);
        
        dictionary_clear(x->current);
        defer_low(x, (method)tralala_init, NULL, 0, NULL);

    } else {
        object_free(x);
        x = NULL;
    }
    //
    }	
	
	return x;
}

void tralala_init(t_tll *x, t_symbol *s, short argc, t_atom *argv)
{
    if (x->flags & TLL_FLAG_INIT) {
        tralala_send(x, PIZ_EVENT_INIT, 0, NULL);
        x->flags &= ~TLL_FLAG_INIT; 

    } else {
        tralala_parseDictionary(x, x->restore);
    }    
}

void tralala_free(t_tll *x)
{ 
    if (x->agent) {
        pizAgentDetach(x->agent, (void *)x);
        pizAgentFree(x->agent);
    }
    
    object_free(x->data);
}

void tralala_assist(t_tll *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) { 
        sprintf(s, "Messages");
        
    } else {	
        switch (a) {
            case 0 : sprintf(s, "(List) Played");     break;
            case 1 : sprintf(s, "(Anything) Dumped"); break;
            case 2 : sprintf(s, "(Anything) End");    break;
            case 3 : sprintf(s, "(Bang) Will End");   break;
        }
    }
}

void tralala_jsave(t_tll *x, t_dictionary *d)
{
    if (d) {
        t_dictionary *t = NULL;
                
        dictionary_clear(x->restore);
        dictionary_copyunique(x->restore, x->current);
        
        if (t = dictionary_new( )) {
            dictionary_copyunique(t, x->data);
            dictionary_appenddictionary(d, TLL_SYM_TRALALA, (t_object *)t);
        }
    }
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

void tralala_callback(void *ptr, PIZEvent *event)
{
    long k, argc = 0;
    long *argv = NULL;
    t_tll *x = NULL;
    PIZEventCode code;
    
    x = (t_tll *)ptr;
    pizEventCode(event, &code);
    
    switch (code) {
    //
    case PIZ_EVENT_NOTE_PLAYED :
        pizEventData(event, &argc, &argv);
        k = argv[PIZ_EVENT_DATA_DURATION]; 
        argv[PIZ_EVENT_DATA_DURATION] = (long)(k * (PIZ_AGENT_CONSTANT_BPM_MS / argv[PIZ_EVENT_DATA_BPM]));
        atom_setlong_array(4, x->played, 4, argv + 1);
        outlet_list(x->left, NULL, 4, x->played); 
        break;
        
    case PIZ_EVENT_NOTE_DUMPED :
        pizEventData(event, &argc, &argv);
        atom_setlong_array(5, x->dumped, 5, argv);
        outlet_anything(x->middleLeft, TLL_SYM_NOTE, 5, x->dumped); 
        break;

    case PIZ_EVENT_WILL_DUMP :
        outlet_anything(x->middleLeft, TLL_SYM_CLEAR, 0, NULL);
        break;

    case PIZ_EVENT_WILL_END :
        outlet_bang(x->right);
        break;
    
    case PIZ_EVENT_END :
        pizEventTime(event, &x->time);
        outlet_anything(x->middleRight, TLL_SYM_END, 1, &x->link);
        break;
    
    default :
        tralala_parseNotification(x, event);
        break;
    //
    }
        
    pizEventFree(event);
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -  

void tralala_play(t_tll *x, t_symbol *s, long argc, t_atom *argv) 
{   
    tralala_send(x, PIZ_EVENT_PLAY, argc, argv);
}

void tralala_loop(t_tll *x, t_symbol *s, long argc, t_atom *argv) 
{   
    tralala_send(x, PIZ_EVENT_LOOP, argc, argv);
}

void tralala_stop(t_tll *x, t_symbol *s, long argc, t_atom *argv) 
{   
    tralala_send(x, PIZ_EVENT_STOP, 0, NULL);
}

void tralala_unloop(t_tll *x, t_symbol *s, long argc, t_atom *argv) 
{   
    tralala_send(x, PIZ_EVENT_UNLOOP, 0, NULL);
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

void tralala_list(t_tll *x, t_symbol *s, long argc, t_atom *argv)
{
    tralala_parseMessage(x, s, argc, argv);
}

void tralala_anything(t_tll *x, t_symbol *s, long argc, t_atom *argv)
{
    tralala_parseMessage(x, s, argc, argv);
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -
#pragma mark ---
#pragma mark -
        
void tralala_send(t_tll *x, PIZEventCode code, long argc, t_atom *argv)
{
    PIZEvent *event = NULL;
    
    if (event = pizEventNew(code)) {
    //
    if ((argc && argv) && (atom_gettype(argv) == A_SYM)) {
        t_symbol *s = atom_getsym(argv);
        t_object *o = s->s_thing;
        if (o && !NOGOOD(o) && object_classname_compare(o, TLL_SYM_TRALALA)) {
            PIZTime time;
            t_tll *ptr = (t_tll *)o;
            pizTimeCopy(&time, &ptr->time);
            pizEventSetTime(event, &time);
        }
    }
                        
    pizEventSetIdentifier(event, x->identifier);
    pizAgentAddEvent(x->agent, event);
    //
    }
}

// -------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------:x