//
//  Compare.c
//  C_practice
//
//  Created by ChangChun Lu on 3/23/14.
//  Copyright (c) 2014 ChangChun Lu. All rights reserved.
//

#include <stdio.h>

int findMax(int a, int b) {
    int result[2];
    result[0] = a;
    result[1] = b;
    int sign_bit = (unsigned int) (a - b) >> (sizeof(int)*8-1);
    
    return result[sign_bit];
}

int compareInt(int a, int b) {
    int result[2] = {1, -1}; // >=, <
    int sign_bit = (unsigned int) (a - b) >> (sizeof(int)*8-1);
    
    return result[sign_bit];
}