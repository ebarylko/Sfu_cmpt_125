#ifndef LAB_EXAM_101_102_H
#define LAB_EXAM_101_102_H

#include <stdbool.h>

#include "lib/LL.h"
#include "lib/stack.h"
#include "lib/queue.h"


// gets an array of strings of length n, and reverses the array
void rev_arr(const char** ar, int n);


// the function gets ar of length n>0
// it moves all zeros to the end of the array
// and returns the number of zeros
int move_zeros(int* ar, int n);


// the funcion gets a linked list of ints
// and returns a new copy of the list
// assumption: list != NULL
LL_t* LL_copy(LL_t* list);


#endif
