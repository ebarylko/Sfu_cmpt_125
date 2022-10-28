#include <stdbool.h>

#include "lib/BTnode.h"


#ifndef LAB_EXAM1_H
#define LAB_EXAM1_H

// gets an array of length n
// returns the length of the longest subsequence
// of consecutive k’s in the array
int longest_seq(const int* ar, int n, int k);
 
// replaces each digit with '*'
void hide_digits(char* str);

// gets a root of a binary tree,
// returns the sum of all numbers in the leaves
// if the tree is empty, returns 0
int sum_leaves(const BTnode_t* root);

#endif
