#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "labexam.h"
// get largest element in row
// start at 0,then go to final column comparing the max element
// store result of comparison, and then return at end
// return the max element at the end
int get_max(int row, int width,int arr[][width]) {
  int max = arr[row][0];
  for (int start = 1; start < width; start++) {
    if (arr[row][start] > max) {
      max = arr[row][start];
    }
  }
  return max;
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

int count_substrings(const char* str, char c) {
  // implement me
  return -1;
}


int count_nodes_one_child(const BTnode_t* root) {
  // implement me
  return -1;
}
