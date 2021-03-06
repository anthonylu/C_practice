//
//  Search.h
//  C_practice
//
//  Created by ChangChun Lu on 3/21/14.
//  Copyright (c) 2014 ChangChun Lu. All rights reserved.
//

#ifndef C_practice_Search_h
#define C_practice_Search_h
typedef struct node {
    int value;
    struct node *left, *right;
} Node;

int min(int a[], int length);
int max(int a[], int length);
int kthMin(int a[], int length, int start, int k);
void swapInt(int *a, int *b);
int binarySearch(int* sortedData, int size, int target);
#endif
