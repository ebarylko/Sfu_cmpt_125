#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "labexam.h"

int count_hyphens(const char* str, int pos) {
  int occurences = 0;
  while (str[pos] == '-') {
    pos++;
    occurences++;
  }
  return occurences;
}

// returns how many chars were consumed to find a hyphen
int find_hyphen(const char* str, int pos) {
  // lookiing for apperance of hyphen
  // "-"
  int consumed = 0;
  while (str[pos] && str[pos] != '-') {
    pos++;
    consumed++;
  }

  return str[pos] ? consumed : -1;
}

/**
 *Write a function that gets a string and returns the 
 number of substrings consisting of hyphens only 
 */
// go through string until hyphen is found. return number of 
// chars consumed to get there. count number of hypehns, then 
// add that to pos. repeat until we pass over string
int count_hyphens_substrings(const char* str) {
  int consumed = 0;
  int hyphens = 0;
  int pos = 0;
  while ((consumed = find_hyphen(str, pos)) != -1) {
    hyphens++;
    pos += consumed;
    pos += count_hyphens(str, pos);
  }
  return hyphens;
}

int countif(LL_t* list, bool(*pred)(int)) {
  int matches = 0;
  node_t* curr = list->head;
  while (curr) {
    if (pred(curr->data)) 
      matches++;
    curr = curr->next;
  }
  return matches;
}
/**
 *gets a stack orig, and creates a new stack with the same content
// when the function returns, orig needs to be in its initial state @brief 
 */
// make a second stack, copy all values from the first stack
// onto here. will be in reverse order.a
// create third stack to reorder elements by inserting them.
// while second stack ! empty, continue to add vals
// free second stack, return third stack.

stack_tt* stack_copy(stack_tt* orig) {
  stack_tt* unordered_s = stack_create();
  stack_tt* ordered_s = stack_create();

  while (!(stack_is_empty(orig))) {
    stack_push(unordered_s, stack_pop(orig));
  }

  while (!(stack_is_empty(unordered_s))) {
    int val = stack_pop(unordered_s); 
    stack_push(ordered_s, val);
    stack_push(orig, val);
  }

  free(unordered_s);
  return ordered_s;
}

