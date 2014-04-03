//
//  Queue.h
//  CPractice
//
//  Created by ChangChun Lu on 3/24/14.
//  Copyright (c) 2014 ChangChun Lu. All rights reserved.
//

#ifndef CPractice_Queue_h
#define CPractice_Queue_h
typedef struct queue {
    int head, tail, size, count;
    int* data;
} Queue;

Queue* getQueueInstance();
void enqueue(Queue* q, int d);
int dequeue(Queue* q);
#endif
