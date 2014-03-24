//
//  Stack.c
//  C_practice
//
//  Created by ChangChun Lu on 3/24/14.
//  Copyright (c) 2014 ChangChun Lu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

const int STACKSIZE = 10;

Stack* getStackInstant() {
    Stack* stack = malloc(sizeof(struct stack));
    stack->current_size = STACKSIZE;
    stack->top = 0;
    stack->data = malloc(sizeof(int)*STACKSIZE);
    return stack;
}

int extend(Stack* s);
int push(Stack* s, int d) {
    int result = -1;
    if (s->top == s->current_size-1) {
        result = extend(s);
    }
    s->data[s->top] = d;
    s->top = s->top + 1;
    return result;
}

int pop(Stack* s) {
    int result = -1;
    if (s->top == 0) {
        return result;
    }
    s->top = s->top-1;
    result = s->data[s->top];
    return result;
}

int extend(Stack *s) {
    int* newData = malloc(sizeof(int)*(s->current_size+STACKSIZE));
    int i = 0, result = -1;
    for (; i < s->current_size; ++i) {
        newData[i] = s->data[i];
    }
    free(s->data);
    s->current_size += STACKSIZE;
    s->data = newData;
    return result;
}
