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

void extend(Stack* s);
void push(Stack* s, int d) {
    if (s->top == s->current_size-1) {
        extend(s);
    }
    s->data[s->top++] = d;
}

int pop(Stack* s) {
    int result = -1;
    if (s->top == 0) {
        return result;
    }
    result = s->data[--s->top];
    return result;
}

void extend(Stack *s) {
    s->data = realloc(s->data, sizeof(int)*(s->current_size+STACKSIZE));
    s->current_size += STACKSIZE;
}
