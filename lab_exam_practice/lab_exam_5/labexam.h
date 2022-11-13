#ifndef LAB_EXAM_201_202_H
#define LAB_EXAM_201_202_H

#include <stdbool.h>

#include "lib/LL.h"
#include "lib/stack.h"
#include "lib/queue.h"


// the function gets an array of strings of length n
// and modifies each string by changing all *lower case* vowels into asterisk
// and returns the total number of modified chars
// The vowels are: {a,e,i,o,u}
int vowels2asterisks(char* ar[], int n);


// the function gets an array of ints of length n>0
// and returns the longest consecutive sequence of equal numbers
// for example, on input [1,2,4,4,4,7,1,1,8,1,9,1,1]
// the function returns 3 because the number 4 appears three times in a row
int longest_equal_seq(const int* ar, int n);


// gets two queues, and swaps their content
void queues_swap(queue_t* q1, queue_t* q2);

#endif
