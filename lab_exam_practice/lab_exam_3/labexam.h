#ifndef LAB_EXAM_103_104_H
#define LAB_EXAM_103_104_H

#include <stdbool.h>

#include "lib/LL.h"
#include "lib/stack.h"
#include "lib/queue.h"



// the function gets two strings and checks if one is reverse of the other
// it returns true if one is the reverse of the other
// and returns false otherwise
bool is_reverse(const char* str1, const char* str2);


// gets an array of ints of length n
// returns a linked list containing the values from the array in the same order
LL_t* array_to_LL(int* ar, int n);


// gets a stack s and a positive int k
// the function modifies the stack
// removing the k elements at the bottom of the stack
// if the stack has less then k elements, all of them are removed
// the function returns the number of elements removed
int stack_forget(stack_tt* s, int k);



#endif
