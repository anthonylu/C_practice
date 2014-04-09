//
//  Queue.c
//  CPractice
//
//  A circular queue implementation
//
//  Created by ChangChun Lu on 3/24/14.
//  Copyright (c) 2014 ChangChun Lu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
const int QUEUESIZE = 10;

Queue* getQueueInstance() {
    Queue* q = malloc(sizeof(struct queue));
    q->head = 0;
    q->tail = 0;
    q->count = 0;
    q->size = QUEUESIZE;
    q->data = malloc(sizeof(int)*QUEUESIZE);
    return q;
}

void extendQueue(Queue* q) {
    //printf("extend queue\n");
    int* newData = malloc(sizeof(int)*(q->size+QUEUESIZE));
    int i,j;
    for (i = q->head, j = 0; j < q->count; ++j, i = (i+1)%q->size) {
        newData[j] = q->data[i];
    }
    free(q->data);
    q->data = newData;
    q->size += QUEUESIZE;
    q->tail = q->count;
    q->head = 0;
}

void enqueue(Queue* q, int d) {
    //printf("enqueue:%d\n",d);
    if (q->count == q->size-1) {
        extendQueue(q);
    }
    ++q->count;
    q->data[q->tail] = d;
    q->tail = (q->tail+1)%q->size;
}

int dequeue(Queue* q) {
    if (q->head == q->tail) {
        return -1;
    }
    --q->count;
    int result = q->data[q->head];
    q->head = (q->head+1)%q->size;
    return result;
}

void freeQueue(Queue* q) {
    free(q->data);
    free(q);
}