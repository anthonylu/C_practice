//
//  Vector.h
//  CPractice
//
//  Created by ChangChun Lu on 4/6/14.
//  Copyright (c) 2014 ChangChun Lu. All rights reserved.
//

#ifndef CPractice_Vector_h
#define CPractice_Vector_h
typedef struct vector {
    int dim;
    double* elem;
} Vector;

Vector* getVectorInstance(int dim);
Vector* duplicateVector(Vector* a);
int replaceByVector(Vector* a, Vector* b);
double dotProduct(Vector* a, Vector* b);
void vectorAdd(Vector* a, Vector* b);
void vectorSub(Vector* a, Vector* b);
void printVector(Vector* v);
void freeVector(Vector* v);
#endif
