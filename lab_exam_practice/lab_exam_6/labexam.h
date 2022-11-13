#ifndef LAB_EXAM_207_208_H
#define LAB_EXAM_207_208_H

#include <stdbool.h>

#include "lib/LL.h"
#include "lib/stack.h"
#include "lib/queue.h"


// the function gets a string
// and rotates the characters of the string to the right by 1
// for example, if the input is "ABCDEFG"
// then after the function finishes, the string becomes "GABCDEF"
void str_right_rotate(char* str);


// the function gets an array of ints of length n, and a function foo
// and returns a new array (on the heap) of the same length
// where ret[i] = foo(ar[i]) for all i
int* map_to_new_array(const int* ar, int n, int(*foo)(int));


// gets two stacks, and swaps their content
void stacks_swap(stack_t* s1, stack_t* s2);



#endif
