#include <stdbool.h>

#include "lib/BTnode.h"


#ifndef LAB_EXAM2_H
#define LAB_EXAM2_H

// gets a 2d array of ints
// returns array MAX with MAX[i] = maximal value in i'th row
int* max_row(int height, int width, int ar[height][width]);

// counts subsequences consisting only of c’s
int count_substrings(const char* str, char c);


// gets a root of a binary tree
// returns the number of nodes with exactly one child
int count_nodes_one_child(const BTnode_t* root);

#endif
