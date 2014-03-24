//
//  FibonacciSequence.c
//  C_practice
//
//  Created by ChangChun Lu on 3/19/14.
//  Copyright (c) 2014 ChangChun Lu. All rights reserved.
//

#include <stdio.h>

int getFibonacciNumber(int n) {
    int first = 1, second = 1, result = 0, i = 0;
    if (n <= 2) {
        return 1;
    }
    for (; i < n-2; ++i) {
        result = first + second;
        first = second;
        second = result;
    }
    return result;
}

int fibonacciSum(int n) {
    int first = 1, second = 1, current = 2, result = 2, i = 0;
    if (n < 2) {
        return 1;
    }

    for (; i < n-2; ++i) {
        current = first + second;
        first = second;
        second = current;
        result += current;
    }
    return result;
}