#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

stack125_t* stack_create() {
  stack125_t* s = (stack125_t*) malloc(sizeof(stack125_t));
  s->list = LL_create();
  return s;
}

void stack_push(stack125_t* s, int item) {
  LL_add_to_head(s->list, item);
}

int stack_pop(stack125_t* s) {
  return LL_remove_from_head(s->list);
}

int stack_is_empty(stack125_t* s) {
    return (s->list->head==NULL);
}


void stack_free(stack125_t* s) {
  LL_free(s->list);
  free(s);
}
