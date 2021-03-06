
/*
 *  Copyright (c) 2011, Nicolas Danet, 
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

#include "pizMarkovModel.h"

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

#include <math.h>   

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

#define PIZ_SIZE_ALPHABET           128
#define PIZ_MAXIMUM_SIZE_GRAPH      32
#define PIZ_MAXIMUM_SIZE_VECTOR     32
#define PIZ_DEFAULT_SIZE_GRAPH      6
#define PIZ_DEFAULT_SIZE_VECTOR     6
#define PIZ_DEFAULT_PERSISTENCE     0.5

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -

PIZ_INLINE void pizMarkovModelBaumWelch             (PIZMarkovModel *x, long argc, long *argv);
PIZ_STATIC void pizMarkovModelFillStochastically    (PIZMarkovModel *x, long argc, double *argv);

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -
#pragma mark ---
#pragma mark -

PIZMarkovModel *pizMarkovModelNew(long argc, long *argv)
{
    PIZMarkovModel *x = NULL;

    if (x = (PIZMarkovModel *)malloc(sizeof(PIZMarkovModel))) {
    //
    x->vectorSize  = PIZ_DEFAULT_SIZE_VECTOR;
    x->graphSize   = PIZ_DEFAULT_SIZE_GRAPH;
    x->persistence = PIZ_DEFAULT_PERSISTENCE;
    
    if (argc && ((argv[0] > 0)  && (argv[0] <= PIZ_MAXIMUM_SIZE_GRAPH))) {
        x->graphSize = argv[0];
    }
    
    if ((argc == 2) && ((argv[1] > 0) && (argv[1] <= PIZ_MAXIMUM_SIZE_VECTOR))) {
        x->vectorSize = argv[1];
    }

    x->start            = (double *)malloc(x->graphSize  * sizeof(double));
    x->transition       = (double *)malloc(x->graphSize  * x->graphSize * sizeof(double));
    x->emission         = (double *)malloc(x->graphSize  * PIZ_SIZE_ALPHABET * sizeof(double));
    x->tempStart        = (double *)malloc(x->graphSize  * sizeof(double));
    x->tempTransition   = (double *)malloc(x->graphSize  * x->graphSize * sizeof(double));
    x->tempEmission     = (double *)malloc(x->graphSize  * PIZ_SIZE_ALPHABET * sizeof(double));
    x->alpha            = (double *)malloc(x->vectorSize * x->graphSize * sizeof(double));
    x->tempAlpha        = (double *)malloc(x->vectorSize * x->graphSize * sizeof(double));
    x->beta             = (double *)malloc(x->vectorSize * x->graphSize * sizeof(double));
    x->coefficient      = (double *)malloc(x->vectorSize * sizeof(double));
    
    if (x->start            &&
        x->transition       &&
        x->emission         &&
        x->tempStart        &&
        x->tempTransition   &&
        x->tempEmission     &&
        x->alpha            &&
        x->beta             &&
        x->coefficient      &&
        x->tempAlpha) {
        long i;
        
        x->count = 0;
        
        x->seed = PIZ_SEED;
        
        pizMarkovModelFillStochastically(x, x->graphSize, x->start);
        
        for (i = 0; i < x->graphSize; i++) {
            pizMarkovModelFillStochastically(x, x->graphSize, x->transition + (i * x->graphSize));
        }
        
        for (i = 0; i < x->graphSize; i++)  {
            pizMarkovModelFillStochastically(x, PIZ_SIZE_ALPHABET, x->emission + (i * PIZ_SIZE_ALPHABET));
        }
        
    } else {
        pizMarkovModelFree(x);
        x = NULL;
    }
    //
    }
    
    return x;
}

void pizMarkovModelFree(PIZMarkovModel *x)
{
    if (x) {
        if (x->start) {
            free(x->start);
        }
        if (x->transition) {
            free(x->transition);
        }
        if (x->emission) {
            free(x->emission);
        }
        if (x->tempStart) {
            free(x->tempStart);
        }
        if (x->tempTransition) {
            free(x->tempTransition);
        }
        if (x->tempEmission) {
            free(x->tempEmission);
        }
        if (x->alpha) {
            free(x->alpha);
        }
        if (x->tempAlpha) {
            free(x->tempAlpha);
        }
        if (x->beta) {
            free(x->beta);
        }
        if (x->coefficient) {
            free(x->coefficient);
        }
        
        free(x);
    }
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

PIZError pizMarkovModelClear(PIZMarkovModel *x)
{
    long i;
                    
    x->count = 0;
                    
    pizMarkovModelFillStochastically(x, x->graphSize, x->start);
                    
    for (i = 0; i < x->graphSize; i++) {
        pizMarkovModelFillStochastically(x, x->graphSize, x->transition + (i * x->graphSize));
    }
        
    for (i = 0; i < x->graphSize; i++) {
        pizMarkovModelFillStochastically(x, PIZ_SIZE_ALPHABET, x->emission + (i * PIZ_SIZE_ALPHABET));
    }
    
    return PIZ_GOOD;
}

PIZError pizMarkovModelAdd(PIZMarkovModel *x, long argc, long *argv)
{
    PIZError err = PIZ_ERROR;
    
    if (argc && argv) {
        long t;
        
        err = PIZ_GOOD;

        for (t = 0; t < argc; t++) {
            argv[t] = CLAMP(argv[t], 0, PIZ_SIZE_ALPHABET - 1); 
        }   
            
        for (t = 0; t < argc; t += x->vectorSize) {
            pizMarkovModelBaumWelch(x, MIN((argc - t), x->vectorSize), argv + t);
            x->count ++;
        }
    }
        
    return err;
}

PIZError pizMarkovModelProceed(PIZMarkovModel *x, long argc, long *argv)
{
    PIZError err = PIZ_ERROR;
    
    if (argc && argv) {
        long i, j = 1;
        long p = 0;
        long v = 0;
        double h, k = 0.;

        err = PIZ_GOOD;
        
        h = rand_r(&x->seed) / (RAND_MAX + 1.0);
        
        for (i = 0; i < x->graphSize; i++) {
            k += x->start[i];
            
            if (k > h) {
                p = i;
                break;
            }
        }
        
        k = 0.;
        h = rand_r(&x->seed) / (RAND_MAX + 1.0);
        
        for (i = 0; i < PIZ_SIZE_ALPHABET; i++) {
            k += x->emission[(p * PIZ_SIZE_ALPHABET) + i];
            
            if (k > h) {
                v = i;
                break;
            }
        }
        
        argv[0] = v;
        argc --;
        
        while (argc)  {
            k = 0.;
            h = rand_r(&x->seed) / (RAND_MAX + 1.0);
    
            for (i = 0; i < x->graphSize; i++) {
                k += x->transition[(p * x->graphSize) + i];
                
                if (k > h) {
                    p = i;
                    break;
                }
            }
            
            k = 0.;
            h = rand_r(&x->seed) / (RAND_MAX + 1.0);
    
            for (i = 0; i < PIZ_SIZE_ALPHABET; i++) {
                k += x->emission[(p * PIZ_SIZE_ALPHABET) + i];
                
                if (k > h) {
                    v = i;
                    break;
                }
            }
            
            argv[j] = v;
            argc --;
            j ++;
        }
    }
    
    return err;
}

long pizMarkovModelCount(const PIZMarkovModel *x)
{
    return x->count;
}

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
#pragma mark -
#pragma mark ---
#pragma mark -

PIZ_INLINE void pizMarkovModelBaumWelch(PIZMarkovModel *x, long argc, long *argv)
{
    long t, i, j, n;
    double f = 0.;
    double s = 0.;
                
    for (t = 0; t < x->graphSize; t++) {
        x->tempAlpha[t * x->vectorSize] = x->start[t] * x->emission[(t * PIZ_SIZE_ALPHABET) + argv[0]];
        s += x->tempAlpha[t * x->vectorSize];
    }
    
    if (s) {
        x->coefficient[0] = 1. / s;
    } else {
        x->coefficient[0] = 0.;
    }

    for (t = 0; t < x->graphSize; t++) {                    
        x->alpha[t * x->vectorSize] = x->tempAlpha[t * x->vectorSize] * x->coefficient[0];
    }
    
    for (t = 0; t < (argc - 1); t++) {
    //
    s = 0.;
    for (j = 0; j < x->graphSize; j++) {
        double k = 0.;
        
        for (i = 0; i < x->graphSize; i++) {
            k += x->alpha[(i * x->vectorSize) + t] * x->transition[(i * x->graphSize) + j];
        }
        
        x->tempAlpha[(j * x->vectorSize) + t + 1] = k * x->emission[(j * PIZ_SIZE_ALPHABET) + argv[t + 1]];
        s += x->tempAlpha[(j * x->vectorSize) + t + 1];
    }
    
    if (s) {
        x->coefficient[t + 1] = 1. / s;
    } else {
        x->coefficient[t + 1] = 0.;
    }

    for (j = 0; j < x->graphSize; j++) {
    x->alpha[(j * x->vectorSize) + t + 1] = x->tempAlpha[(j * x->vectorSize) + t + 1] * x->coefficient[t + 1];
    }
    //    
    }
    
    for (t = 0; t < x->graphSize; t++) {
        x->beta[(t * x->vectorSize) + argc - 1] = x->coefficient[argc - 1];
    }
    
    for (t = (argc - 2); t >= 0; t--) {
    //
    for (i = 0; i < x->graphSize; i++) {
        double k = 0.;
        
        for (j = 0; j < x->graphSize; j++) {
            double temp = x->emission[(j * PIZ_SIZE_ALPHABET) + argv[t + 1]];
            k += x->transition[(i * x->graphSize) + j] * x->beta[(j * x->vectorSize) + t + 1] * temp;
        }
        
        x->beta[(i * x->vectorSize) + t] = x->coefficient[t] * k;
    }
    //    
    }
    
    f = x->coefficient[0]; 
    
    for (t = 1; t < argc; t++) {
        f *= x->coefficient[t];
    }
        
    if (f) {
    //
    for (i = 0; i < x->graphSize; i++) {
        x->tempStart[i] = (x->alpha[i * x->vectorSize] * x->beta[i * x->vectorSize]) / x->coefficient[0];
    }
                        
    for (i = 0; i < x->graphSize; i++) {
        double memo[PIZ_MAXIMUM_SIZE_GRAPH];
        
        s = 0.;
        
        for (j = 0; j < x->graphSize; j++) {
            memo[j] = 0.;
            
            for (n = 0; n < (argc - 1); n++) {
                memo[j] += x->alpha[(i * x->vectorSize) + n] 
                        * x->transition[(i * x->graphSize) + j]
                        * x->emission[(j * PIZ_SIZE_ALPHABET) + argv[n + 1]]
                        * x->beta[(j * x->vectorSize) + n + 1];
            }
            
            s += memo[j];
        }
            
        for (j = 0; j < x->graphSize; j++) {
            if (s) {
                x->tempTransition[(i * x->graphSize) + j] = memo[j] / s;
            }
        }
    }
    
    for (i = 0; i < x->graphSize; i++) {
        double memo[PIZ_MAXIMUM_SIZE_VECTOR];
        
        s = 0.;
        
        for (j = 0; j < argc; j++) {
        //
        memo[j] = (x->alpha[(i * x->vectorSize) + j] * x->beta[(i * x->vectorSize) + j]) / x->coefficient[j];
        s += memo[j];
        //
        }
            
        if (s) {
            for (j = 0; j < PIZ_SIZE_ALPHABET; j++) {
                double k = 0.;
                
                for (n = 0; n < argc; n++) {
                    if (argv[n] == j) {
                        k += memo[n];   
                    }
                }
            
                x->tempEmission[(i * PIZ_SIZE_ALPHABET) + j] = k / s;
            }
        }
    }
    
    for (i = 0; i < x->graphSize; i++) {
        x->start[i] = ((x->start[i] * x->persistence) + x->tempStart[i]) / (x->persistence + 1.);
    }
    
    for (i = 0; i < (x->graphSize * x->graphSize); i++) {
        x->transition[i] = ((x->transition[i] * x->persistence) + x->tempTransition[i]) / (x->persistence + 1.);
    }
    
    for (i = 0; i < (x->graphSize * PIZ_SIZE_ALPHABET); i++) {
        x->emission[i] = ((x->emission[i] * x->persistence) + x->tempEmission[i]) / (x->persistence + 1.);
    }
    //    
    } 
}

void pizMarkovModelFillStochastically(PIZMarkovModel *x, long argc, double *argv)
{
    long i, f = (long)(6 * (rand_r(&x->seed) / (RAND_MAX + 1.0)) + 1.);
    double s = 0.;
    
    for (i = 0; i < argc; i++) {
        argv[i] = pow((rand_r(&x->seed) / (RAND_MAX + 1.0)), f);
        s += argv[i];
    }
        
    for (i = 0; i < argc; i++) {
        argv[i] = argv[i] / s;
    }
}

// -------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------:x