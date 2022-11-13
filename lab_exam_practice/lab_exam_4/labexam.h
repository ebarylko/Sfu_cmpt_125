#ifndef LAB_EXAM_203_204_H
#define LAB_EXAM_203_204_H

#include <stdbool.h>

#include "lib/LL.h"
#include "lib/stack.h"
#include "lib/queue.h"


// the function gets a string
// and returns the number of substrings consisting of hyphens only.
// For example: if str = "xyz--x-abc--", the function needs to return 4
int count_hyphens_substrings(const char* str);


// gets a linked list of ints and a predicate
// returns the number of nodes in the list for which pred(node->data)==true
int countif(LL_t* list, bool(*pred)(int));


// gets a stack orig, and creates a new stack with the same content
// when the function returns, orig needs to be in its initial state
stack_tt* stack_copy(stack_tt* orig);


#endif
