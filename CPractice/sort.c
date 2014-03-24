//
//  sort.c
//  C_practice
//
//  Created by ChangChun Lu on 3/22/14.
//  Copyright (c) 2014 ChangChun Lu. All rights reserved.
//

#include <stdio.h>
#include "Search.h"

void quickSort(int *a, int start, int end) {
    if (start >= end) return;
    int pivot = a[start], i = start+1, j = end;
    while (1) {
        while (pivot >= a[i] && i <= end) ++i;
        while (pivot <= a[j] && j > start) --j;
        if (i >= j) {
            break;
        }
        swapInt(&a[i], &a[j]);
    }
    if (start < j)
        swapInt(&a[start], &a[j]);
    quickSort(a, start, j-1);
    quickSort(a, j+1, end);
}