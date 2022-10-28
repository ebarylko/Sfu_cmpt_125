#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "labexam.h"

int count_occur(const int arr[], int pos, int length) {
  int val = arr[pos];
  int matches = 0;
  while (pos < length && arr[pos] == val) {
    matches++;
    pos++;
  }
  return matches;
}

// go up to instance of character, count occurences,check if they are greater than max
// add occurences to index and check until end
// "abbaac", "b",
int longest_seq(const int* ar, int n, int k) {
  int pos = 0;
  int max = 0;
  // go through entire string
  while (pos < n) {
   int occurences = 1;
    if (ar[pos] == k) {
      occurences = count_occur(ar, pos, n);
      // check occurences of char
      if (occurences > max) {
        max = occurences;
      }
    }
    // // move to character following sequence
    pos += occurences;
  }
  return max;
}

// takes a string, and converts all digits to *. if no digits, does nothing 
// go through entire string, and change digits
void hide_digits(char* str) {
  for (int pos = 0; str[pos]; pos++) {
    if (isdigit(str[pos])) {
      str[pos] = '*';
    }
  }
}

// returns the sums of the farthest values in the tree
// go deeper into the tree until no more values can be found, then sum the 
// resulting values found
//if tree not filled, return 0. if only containing root, return root.
// else , return sum of leaves
// if one of branches is valid, go through it.
int sum_leaves(const BTnode_t* root) {
  // check for empty tree
  if (!root) {
    return 0;
  }
  BTnode_t * left = root->left;
  BTnode_t * right = root->right;
  if (left || right) {
    return sum_leaves(left) + sum_leaves(right);
  }
  // if there are no children
  return root->value;
}
