//
//  GeometricSequence.c
//  C_practice
//
//  Created by ChangChun Lu on 3/18/14.
//  Copyright (c) 2014 ChangChun Lu. All rights reserved.
//

#include <stdio.h>

double geoSum(double a1, double an, double r) {
    double result = 0.0;
    for (; a1 <= an; a1 *= r) {
        result += a1;
    }
    return result;
}

double geoProduct(double a1, double an, double r) {
    double result = 1.0;
    for (; a1 <= an; a1 *= r) {
        result *= a1;
    }
    return result;
}
