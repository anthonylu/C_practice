//
//  Search.c
//  C_practice
//
//  Created by ChangChun Lu on 3/21/14.
//  Copyright (c) 2014 ChangChun Lu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int min(int a[], int length) {
    int result = a[0], i = 1;
    for (; i < length; ++i) {
        if (result > a[i]) {
            result = a[i];
        }
    }
    
    return result;
}

int max(int a[], int length) {
    int result = a[0], i = 1;
    for (; i < length; ++i) {
        if (result < a[i]) {
            result = a[i];
        }
    }
    
    return result;
}

void swapInt(int *a, int *b) {
    if (a == b) return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int kthMin(int a[], int length, int start, int k) {
    int select = start+rand()%(length-start),tmp = a[start], i = start+1, j = length-1;
    a[start] = a[select];
    a[select] = tmp;
    
    while (1) {
        while (a[start] >= a[i] && i < length) ++i;
        while (a[start] <= a[j] && j > start) --j;
        if (i >= j) {
            break;
        }
        swapInt(&a[i], &a[j]);
    }
    
    if (j+1 == k) {
        return a[start];
    } else if (j+1 < k) {
        return kthMin(a, length, j+1, k);
    } else {
        if (j == length-1 && a[start] > a[j]) {
            swapInt(&a[start], &a[j]);
            --j;
        }
        return kthMin(a, j+1, 0, k);
    }
}

int binarySearch(int* sortedData, int size, int target) {
    int result = -1, start = 0, end = size-1, middle = (0.5+(start+end)/2);
    while(start < end) {
        if (sortedData[middle] == target) {
            result = middle;
            break;
        } else if (sortedData[middle] > target) {
            end = middle-1;
        } else {
            start = middle+1;
        }
        middle = (0.5+(start+end)/2);
    }
    if (sortedData[start] == target) result = start;
    return result;
}
