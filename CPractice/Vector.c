//
//  Vector.c
//  CPractice
//
//  Created by ChangChun Lu on 4/6/14.
//  Copyright (c) 2014 ChangChun Lu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"

Vector* getVectorInstance(int dim) {
    Vector* vector = malloc(sizeof(Vector));
    vector->dim = dim;
    vector->elem = (double*) malloc(sizeof(double)*dim);
    int i;
    
    for (i = 0; i < dim; ++i)
        vector->elem[i] = 0;

    return vector;
}

Vector* duplicateVector(Vector* a) {
    Vector *new = getVectorInstance(a->dim);
    int i = 0;
    for (i=0; i<a->dim; ++i)
        new->elem[i] = a->elem[i];
    return new;
}

// a->elem = b->elem
int replaceByVector(Vector* a, Vector* b) {
    int i = -1;
    
    if (a == NULL || b == NULL)
        return i;
    
    if (a->dim == b->dim) {
        for (i=0; i<a->dim; ++i)
            a->elem[i] = b->elem[i];
    }
    
    return i;
}

double dotProduct(Vector* a, Vector* b) {
    double result = -1;
    int i;
    if (a->dim == b->dim) {
        result = 0;
        for (i=0; i<a->dim; ++i)
            result += a->elem[i]*b->elem[i];
    }
    
    return result;
}

// a = a + b
void vectorAdd(Vector* a, Vector* b) {
    int i = 0;
    if (a->dim == b->dim)
        for (i = 0; i < a->dim; ++i)
            a->elem[i] += b->elem[i];
}

// a = a - b
void vectorSub(Vector* a, Vector* b) {
    int i = 0;
    if (a->dim == b->dim)
        for (i = 0; i < a->dim; ++i)
            a->elem[i] -= b->elem[i];
}

void printVector(Vector* v) {
    int i;
    for (i=0; i<v->dim; ++i) {
        printf("%lf ", v->elem[i]);
    }
    printf("\n");
}

void freeVector(Vector* v) {
    free(v->elem);
    free(v);
}