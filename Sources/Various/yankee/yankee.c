/*
 *  yankee.c
 *
 *  nicolas.danet@free.fr
 *
 */

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#include "ext.h"
#include "ext_obex.h"
#include "ext_systhread.h"

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#include "pizNeuralGas.h"
#include "pizArray.h"

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#define MAXIMUM_SIZE_LIST       256

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#define DEFAULT_LAMBDA          2
#define DEFAULT_ALPHA           0.5
#define DEFAULT_BETA            0.1
#define DEFAULT_EPSILON1        0.5
#define DEFAULT_EPSILON2        0.25
#define DEFAULT_KAPPA           10

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#define LOCK    systhread_mutex_lock(x->algorithmMutex);
#define UNLOCK  systhread_mutex_unlock(x->algorithmMutex);

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

typedef struct _yankee {
    t_object            ob;
    long                lambda;
    long                kappa;
    double              epsilon1;
    double              epsilon2;
    double              alpha;
    double              beta;
    long                *values; 
    PIZNeuralGas        *neuralGas;
    t_systhread_mutex   algorithmMutex;
    void                *leftOutlet;
    void                *rightOutlet;
    } t_yankee;

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

void        *yankee_new         (t_symbol *s, long argc, t_atom *argv);
void        yankee_free         (t_yankee *x);
void        yankee_assist       (t_yankee *x, void *b, long m, long a, char *s);

t_max_err   yankee_setLambda    (t_yankee *x, t_object *attr, long argc, t_atom *argv);
t_max_err   yankee_setEpsilon1  (t_yankee *x, t_object *attr, long argc, t_atom *argv);
t_max_err   yankee_setEpsilon2  (t_yankee *x, t_object *attr, long argc, t_atom *argv);
t_max_err   yankee_setAlpha     (t_yankee *x, t_object *attr, long argc, t_atom *argv);
t_max_err   yankee_setBeta      (t_yankee *x, t_object *attr, long argc, t_atom *argv);
t_max_err   yankee_setKappa     (t_yankee *x, t_object *attr, long argc, t_atom *argv);

void        yankee_learn        (t_yankee *x, t_symbol *s, long argc, t_atom *argv);
void        yankee_int          (t_yankee *x, long n);
void        yankee_dump         (t_yankee *x, long n);
void        yankee_clear        (t_yankee *x);

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

PIZ_INLINE void     pizNeuralGasSetLambda       (PIZNeuralGas *x, long n);
PIZ_INLINE void     pizNeuralGasSetEpsilon1     (PIZNeuralGas *x, double f);
PIZ_INLINE void     pizNeuralGasSetEpsilon2     (PIZNeuralGas *x, double f);
PIZ_INLINE void     pizNeuralGasSetAlpha        (PIZNeuralGas *x, double f);
PIZ_INLINE void     pizNeuralGasSetBeta         (PIZNeuralGas *x, double f);
PIZ_INLINE void     pizNeuralGasSetKappa        (PIZNeuralGas *x, double f);
PIZ_INLINE PIZError pizNeuralGasEncodeToArray   (const PIZNeuralGas *x, long n, PIZArray *a);

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

static t_class *yankee_class;

PIZ_PUBLIC int main(void)
{   
    t_class *c = NULL;
    
    c = class_new("yankee", (method)yankee_new, (method)yankee_free, (long)sizeof(t_yankee), 0L, A_GIMME, 0);

    class_addmethod(c, (method)yankee_assist,       "assist",   A_CANT, 0); 
    class_addmethod(c, (method)yankee_learn,        "learn",    A_GIMME, 0);
    class_addmethod(c, (method)yankee_int,          "int",      A_LONG, 0);
    class_addmethod(c, (method)yankee_dump,         "dump",     A_DEFLONG, 0);
    class_addmethod(c, (method)yankee_clear,        "clear",    0);
    class_addmethod(c, (method)object_obex_dumpout, "dumpout",  A_CANT, 0);
    
    CLASS_ATTR_LONG         (c, "kappa",        0, t_yankee, kappa);
    CLASS_ATTR_LABEL        (c, "kappa",        0, "Utility Threshold");
    CLASS_ATTR_ACCESSORS    (c, "kappa",        NULL, yankee_setKappa);
    CLASS_ATTR_FILTER_MIN   (c, "kappa",        1);
    CLASS_ATTR_LONG         (c, "lambda",       0, t_yankee, lambda);
    CLASS_ATTR_LABEL        (c, "lambda",       0, "New Node Rate");
    CLASS_ATTR_ACCESSORS    (c, "lambda",       NULL, yankee_setLambda);
    CLASS_ATTR_FILTER_MIN   (c, "lambda",       1);
    CLASS_ATTR_DOUBLE       (c, "epsilon1",     0, t_yankee, epsilon1);
    CLASS_ATTR_LABEL        (c, "epsilon1",     0, "Move Winner Factor");
    CLASS_ATTR_ACCESSORS    (c, "epsilon1",     NULL, yankee_setEpsilon1);
    CLASS_ATTR_FILTER_CLIP  (c, "epsilon1",     0., 1.);
    CLASS_ATTR_DOUBLE       (c, "epsilon2",     0, t_yankee, epsilon2);
    CLASS_ATTR_LABEL        (c, "epsilon2",     0, "Move Neighbours Factor");
    CLASS_ATTR_ACCESSORS    (c, "epsilon2",     NULL, yankee_setEpsilon2);
    CLASS_ATTR_FILTER_CLIP  (c, "epsilon2",     0., 1.);
    CLASS_ATTR_DOUBLE       (c, "alpha",        0, t_yankee, alpha);
    CLASS_ATTR_LABEL        (c, "alpha",        0, "Decrease Generators Error Factor");
    CLASS_ATTR_ACCESSORS    (c, "alpha",        NULL, yankee_setAlpha);
    CLASS_ATTR_FILTER_CLIP  (c, "alpha",        0., 1.);
    CLASS_ATTR_DOUBLE       (c, "beta",         0, t_yankee, beta);
    CLASS_ATTR_LABEL        (c, "beta",         0, "Decrease Global Error Factor");
    CLASS_ATTR_ACCESSORS    (c, "beta",         NULL, yankee_setBeta);
    CLASS_ATTR_FILTER_CLIP  (c, "beta",         0., 1.);
    
    CLASS_ATTR_ORDER        (c, "lambda",       0, "1");
    CLASS_ATTR_ORDER        (c, "epsilon1",     0, "2");
    CLASS_ATTR_ORDER        (c, "epsilon2",     0, "3");
    CLASS_ATTR_ORDER        (c, "alpha",        0, "4");
    CLASS_ATTR_ORDER        (c, "beta",         0, "5");
    CLASS_ATTR_ORDER        (c, "kappa",        0, "6");
    
    class_register(CLASS_BOX, c); 
    
    yankee_class = c;
    
    return PIZ_GOOD;
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

void *yankee_new(t_symbol *s, long argc, t_atom *argv)
{
    t_yankee *x = NULL;
    
    if (x = (t_yankee *)object_alloc(yankee_class)) {
    //
    long k[2] = { 0, 0 };
    
    if (argc && atom_gettype(argv) == A_LONG) {
        k[0] = atom_getlong(argv);
            
        if (argc == 2 && atom_gettype(argv + 1) == A_LONG) {
            k[1] = atom_getlong(argv + 1);
        }
    }
    
    x->values = (long *)sysmem_newptr(sizeof(long) * MAXIMUM_SIZE_LIST);
    x->neuralGas = pizNeuralGasNew(2, k);
                            
    if (x->values && x->neuralGas) {
    
        x->lambda   = DEFAULT_LAMBDA;
        x->epsilon1 = DEFAULT_EPSILON1;
        x->epsilon2 = DEFAULT_EPSILON2;
        x->alpha    = DEFAULT_ALPHA;
        x->beta     = DEFAULT_BETA;
        x->kappa    = DEFAULT_KAPPA;
        
        x->rightOutlet = outlet_new(x, NULL);
        object_obex_store((void *)x, gensym("dumpout"), (t_object *)x->rightOutlet);
        x->leftOutlet = listout((t_object *)x);
                
        systhread_mutex_new(&x->algorithmMutex, SYSTHREAD_MUTEX_NORMAL);
        
        attr_args_process(x, argc, argv);
            
    } else {
        object_free(x);
        x = NULL;
    }
    //
    }
            
    return x;
}

void yankee_free(t_yankee *x)
{ 
    pizNeuralGasFree(x->neuralGas);
        
    if (x->values) {
        sysmem_freeptr(x->values);
    }
        
    if (x->algorithmMutex) {
        systhread_mutex_free(x->algorithmMutex);
    }
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
    
void yankee_assist(t_yankee *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_INLET) { 
        sprintf(s, "(int) learn clear dump");
        
    } else {   
        switch (a) {
            case 0 : sprintf(s, "(list) Navigate"); break;
            case 1 : sprintf(s, "Dumpout"); break;
        }
    }
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

t_max_err yankee_setLambda(t_yankee *x, t_object *attr, long argc, t_atom *argv)
{
    if (argc && argv) {
        x->lambda = atom_getlong(argv);
        pizNeuralGasSetLambda(x->neuralGas, x->lambda);
    }

    return MAX_ERR_NONE;
}

t_max_err yankee_setEpsilon1(t_yankee *x, t_object *attr, long argc, t_atom *argv)
{
    if (argc && argv) {
        x->epsilon1 = atom_getfloat(argv);
        pizNeuralGasSetEpsilon1(x->neuralGas, x->epsilon1);
    }

    return MAX_ERR_NONE;
}

t_max_err yankee_setEpsilon2(t_yankee *x, t_object *attr, long argc, t_atom *argv)
{
    if (argc && argv) {
        x->epsilon2 = atom_getfloat(argv);
        pizNeuralGasSetEpsilon2(x->neuralGas, x->epsilon2);
    }

    return MAX_ERR_NONE;
}

t_max_err yankee_setAlpha(t_yankee *x, t_object *attr, long argc, t_atom *argv)
{
    if (argc && argv) {
        x->alpha = atom_getfloat(argv);
        pizNeuralGasSetAlpha(x->neuralGas, x->alpha);
    }

    return MAX_ERR_NONE;
}

t_max_err yankee_setBeta(t_yankee *x, t_object *attr, long argc, t_atom *argv)
{
    if (argc && argv) {
        x->beta = atom_getfloat(argv);
        pizNeuralGasSetBeta(x->neuralGas, x->beta);
    }

    return MAX_ERR_NONE;
}

t_max_err yankee_setKappa(t_yankee *x, t_object *attr, long argc, t_atom *argv)
{
    if (argc && argv) {
        x->kappa = atom_getlong(argv);
        pizNeuralGasSetKappa(x->neuralGas, (double)x->kappa);
    }

    return MAX_ERR_NONE;
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

void yankee_learn(t_yankee *x, t_symbol *s, long argc, t_atom *argv)           
{   
    LOCK
    
    atom_getlong_array(argc, argv, MIN(MAXIMUM_SIZE_LIST, argc), x->values);
    pizNeuralGasAdd(x->neuralGas, MIN(MAXIMUM_SIZE_LIST, argc), x->values);
    
    UNLOCK
}

void yankee_int(t_yankee *x, long n)
{
    char alloc;
    t_atom *argv = NULL;
    long argc = 0;

    if ((n > 0) && (atom_alloc_array(MIN(n, MAXIMUM_SIZE_LIST), &argc, &argv, &alloc) == MAX_ERR_NONE)) {
    //
    PIZError err = PIZ_ERROR;
        
    LOCK

    if (pizNeuralGasCount(x->neuralGas)) {
        if (!(err = pizNeuralGasProceed(x->neuralGas, argc, x->values))) {
            atom_setlong_array(argc, argv, argc, x->values);
        }
    }
    
    UNLOCK

    if (!err) {
        outlet_list(x->leftOutlet, NULL, argc, argv);
    }
        
    sysmem_freeptr(argv);
    //
    }
}
    
void yankee_clear(t_yankee *x)
{
    LOCK
    
    pizNeuralGasClear(x->neuralGas);
    
    UNLOCK
}

void yankee_dump(t_yankee *x, long n)
{
    char alloc;
    long size;
    long argc = 0;
    PIZError err = PIZ_GOOD;
    t_atom *argv = NULL;
    PIZArray *values = pizArrayNew(4);
    
    LOCK
    err = pizNeuralGasEncodeToArray(x->neuralGas, n, values);
    UNLOCK
    
    if (!err) {
        size = pizArrayCount(values);

        if (atom_alloc_array(size, &argc, &argv, &alloc) == MAX_ERR_NONE) {
            long *ptr = pizArrayPtr(values);

            atom_setlong_array(argc, argv, argc, ptr);
            outlet_list(x->rightOutlet, NULL, argc, argv);
                    
            sysmem_freeptr(argv);
        }
    }
    
    pizArrayFree(values);
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

PIZ_INLINE void pizNeuralGasSetLambda(PIZNeuralGas *x, long n)
{
    x->lambda = MAX(n, 1);
}

PIZ_INLINE void pizNeuralGasSetEpsilon1(PIZNeuralGas *x, double f)
{
    if (f > 0. && f < 1.) {
        x->epsilon1 = f;
    }
}

PIZ_INLINE void pizNeuralGasSetEpsilon2(PIZNeuralGas *x, double f)
{
    if (f > 0. && f < 1.) {
        x->epsilon2 = f;
    }
}

PIZ_INLINE void pizNeuralGasSetAlpha(PIZNeuralGas *x, double f)
{
    if (f > 0. && f < 1.) {
        x->alpha = f;
    }
}

PIZ_INLINE void pizNeuralGasSetBeta(PIZNeuralGas *x, double f)
{
    if (f > 0. && f < 1.) {
            x->beta = f;
        }
}

PIZ_INLINE void pizNeuralGasSetKappa(PIZNeuralGas *x, double f)
{
    if (f > 0.) {
        x->kappa = f;
    }
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

PIZ_INLINE PIZError pizNeuralGasEncodeToArray(const PIZNeuralGas *x, long n, PIZArray *a)
{
    PIZError err = PIZ_ERROR;
    
    if ((n >= 0) && (n < x->mapSize) && a) {
    //
    long i, j, t, k = 0;
    
    err = PIZ_GOOD;
    
    for (i = 0; i < PIZ_ITEMSET_SIZE; i++) {
        if (pizItemsetIsSetAtIndex(&x->map, i)) {
            if (k == n) {
                for (j = 0; j < x->vectorSize; j++) {
                    t = (long)(((*(x->vectorStock + (n * x->vectorSize) + j)) + 0.5));
                    err |= pizArrayAppend(a, t);
                }
            }
            
            k ++;
        }
    }
    //
    }
    
    return err;
}

// -------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------:x