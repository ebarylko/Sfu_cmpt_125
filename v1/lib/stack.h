#ifndef STACK_H
#define STACK_H

#include "LL.h"


typedef struct {
  LL_t* list;
} stack125_t; 

// creates a new stack
stack125_t* stack_create();

// pushes a given item to the stack
// Pre condition: stack is not empty
void stack_push(stack125_t* s, int item);

// pops the top element from the stack
// Pre condition: stack is not empty
int stack_pop(stack125_t* s);

// returns 1 if the stack is empty, and returns 0 otherwise
int stack_is_empty(stack125_t* s);

// releases the memory
void stack_free(stack125_t* s);


#endif
