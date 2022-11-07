#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "labexam.h"


// checks if one string is reverse of other
// if they do not have same amount of characters, then not reverse
// start of one string and end of other string must match
// get out when char from either do not match
// go through entire string to make sure
bool is_reverse(const char* str1, const char* str2) {
  int length_1 = strlen(str1);
  int length_2 = strlen(str2);
  // do not have same amount of chars
  if (length_1 != length_2) 
    return false;
  for (int pos = 0; pos < length_1; pos++) {
    if (str1[pos] != str2[length_1 - 1 - pos]) 
      return false;
  }

  return true;
}

// always add to tail
//create list, then continuosly add on elements
LL_t* array_to_LL(int* ar, int n) {
  LL_t* list = LL_create();
  for (int pos = 0; pos < n; pos++) {
    LL_add_to_tail(list, ar[pos]);
  }
  return list;
}

// returns number of elements removed
//removes k elements from bottom of stack
// I don't know number of elements in stack
// make copy, use popped values and add to head
// take out amount of values from the stack
// add values that remain to old stack, free copy
// make a copy of the stack and remove all the elements, 
// count how many there are. move all elements to another stack
// then remove elements based on that
// based on that, I can only store the amounts of elements i need
int stack_forget(stack_tt* s, int k) {
  stack_tt* new_stack = stack_create();
  // reorder values so values to pop are from bottom of stack
  while (!(stack_is_empty(s))) {
    stack_push(new_stack, stack_pop(s));
  }
  int elems = 0;
  while (k && (!(stack_is_empty(new_stack)))) {
      stack_pop(new_stack);
      k--;
      elems++;
  }

  while (!(stack_is_empty(new_stack))) {
    stack_push(s, stack_pop(new_stack));
  }
  stack_free(new_stack);
  return elems;
}



