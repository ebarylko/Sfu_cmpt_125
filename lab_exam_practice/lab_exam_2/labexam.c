#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "labexam.h"
#define max(a,b) ((a) > (b) ? (a) : (b)) 

// get largest element in row
// start at 0,then go to final column comparing the max element
// store result of comparison, and then return at end
// return the max element at the end
int get_max(int row, int width, int arr[][width]) {
  int result = arr[row][0];
  for (int start = 1; start < width; start++) {
      result = max(result, arr[row][start]);
  }
  return result;
}

// takes 2d array, and returns new array with greatest element from
// each column in pos i in pos i of array
// go over all rows, and grab largest elem.store value in variable
// store largest value in the new array
// return new array
// set max initially as smallest int value, then adjust to 
// current values in the array
int* max_row(int height, int width, int ar[height][width]) {
  int* largest_vals = (int*)malloc(height * sizeof(int));
  for (int row = 0; row < height; row++) {
    int max = get_max(row, width, ar);
    largest_vals[row] = max;
  }
  return largest_vals;
}

// looking for char. if not found, return -1. else, return pos
int find_char(const char* str, int pos, int length, char c) {
  while (str[pos] && str[pos] != c)
    pos++;
  return pos != length ? pos : -1;
}

// moves to next unique char
int next_char(const char* str, int pos, char c) {
  while (str[pos] && str[pos] == c) 
    pos++;
  return pos;
}

int count_occurences(const char* str, char c) {
  int occurences = 0;
  int char_index;
  int search_index = 0;
  int length = strlen(str);
  while ((char_index = find_char(str, search_index, length, c)) != -1) {
    occurences++;
    search_index = next_char(str, char_index, c);
  }
  return occurences;

}
//"HELLO WORLD"
int count_substrings(const char* str, char c) {
return count_occurences(str, c);
}

// takes the root of the tree, and returns the number of
// nodes with only one child
// go through tree, if tree has both children, recur
// if there is not both children, return the value of
// the sum of the nodes
/*
         n1
        /  \
      n2     n3
     / \    /
   n4  n5  n6
          /
        n7
*/
// sum children should get sum of all children in thee tree
// if condition is not going through
int count_nodes_one_child(const BTnode_t* root) {
  if (!root) 
    return 0;
  BTnode_t* left = root->left;  
  BTnode_t* right = root->right;
  return (!left ^ !right) +
         count_nodes_one_child(left) +
         count_nodes_one_child(right);
}
