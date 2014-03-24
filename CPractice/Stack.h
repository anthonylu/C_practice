//
//  Stack.h
//  C_practice
//
//  Created by ChangChun Lu on 3/24/14.
//  Copyright (c) 2014 ChangChun Lu. All rights reserved.
//

#ifndef C_practice_Stack_h
#define C_practice_Stack_h
typedef struct stack {
    int *data;
    int top, current_size;
} Stack;
Stack* getStackInstant();
int push(Stack* s, int data);
int pop(Stack* s);
#endif
