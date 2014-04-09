//
//  PLA.h
//  CPractice
//
//  Created by ChangChun Lu on 4/6/14.
//  Copyright (c) 2014 ChangChun Lu. All rights reserved.
//

#include "Vector.h"

#ifndef CPractice_PLA_h
#define CPractice_PLA_h
typedef struct PLANode {
    Vector* vector;
    int label;
    struct PLANode* next;
} PLANode;
int pla_main(int argc, const char * argv[]);


#endif
