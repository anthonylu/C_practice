//
//  Queue.c
//  CPractice
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
    q->size = QUEUESIZE;
    q->data = malloc(sizeof(int)*QUEUESIZE);
    return q;
}

void extendQueue(Queue* q) {
    if (q->head >= QUEUESIZE) {// remove unused space before q-> head
        int* newData = malloc(sizeof(int)*(q->size-QUEUESIZE));
        int i,j;
        for (i = q->head, j = 0; i < q->tail; ++i, ++j) {
            newData[j] = q->data[i];
        }
        free(q->data);
        q->data = newData;
        q->size = q->size-QUEUESIZE;
        q->tail -= q->head;
        q->head = 0;
    } else {
        q->size += QUEUESIZE;
        q->data = realloc(q->data, sizeof(int)*q->size);
    }
}

void enqueue(Queue* q, int d) {
    if (q->tail == q->size-1) {
        extendQueue(q);
    }
    q->data[q->tail++] = d;
}

int dequeue(Queue* q) {
    if (q->head == q->tail) {
        return -1;
    }
    return q->data[q->head++];
}