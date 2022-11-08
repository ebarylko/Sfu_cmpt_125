#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "labexam.h"

// return pos of where hyphen is no longer found or end of string
//"--aabc-----hi***"
int find_hyphens(const char* str, int pos) {
  // lookiing for apperance of hyphen
  while (str[pos] && str[pos] != '-') {
    pos++;
  }

  int matches = 0;
  if (str[pos]) {
    //count hyphens
    while (str[pos] == '-') {
      pos++;
      matches++;
    }
  }
  return matches;
}

/**
 *Write a function that gets a string and returns the 
 number of substrings consisting of hyphens only 
 */
int count_hyphens_substrings(const char* str) {
  // int length = strlen(str);
  int matches = 0;
  int hyphens = 0;
  int pos = 0;
  printf("hyphens:%d\n", find_hyphens("a!ba-ei-XXoi---", 9));
  while ((matches = find_hyphens(str, pos)) > 0) {
    hyphens++;
    pos += matches;
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
  node_t* curr = orig->list->head;
  while (curr) {
    stack_push(unordered_s, curr->data);
    curr = curr->next;
  }

  while (!(stack_is_empty(unordered_s))) {
    stack_push(ordered_s, stack_pop(unordered_s));
  }

  free(unordered_s);
  return ordered_s;
}

