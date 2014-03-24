//
//  ArithmetricSequence.c
//  C_practice
//
//  Created by ChangChun Lu on 3/18/14.
//  Copyright (c) 2014 ChangChun Lu. All rights reserved.
//

#include <stdio.h>

int sum(int a1, int an, int d) {
    int result = 0;
    for (; a1 <= an; a1 += d) {
        result += a1;
    }
    return result;
}

int product(int a1, int an, int d) {
    int result = 1;
    for (; a1 <= an; a1 += d) {
        result *= a1;
    }
    return result;
}

int factorial(int n) {
    return product(1, n, 1);
}