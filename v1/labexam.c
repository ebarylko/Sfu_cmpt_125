#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "labexam.h"

// takes an array of strings, and reverses it
// go all the way until the end, and swap the position of the strings
// ["a" "b" "c" "d"]
// go up to midpoint, and swap from beginning and end
void rev_arr(const char** ar, int n) {
  int mid = n / 2;
  int pos = 0;
  while (pos < mid) {
    const char* temp = ar[pos];
    ar[pos] = ar[n - 1 - pos];
    ar[n - 1 - pos] = temp;
    pos++;
  }
}

int num_sort(const void* num1, const void* num2) {
  return (*(int*)num1 - *(int*)num2);
}

// use qsort to order the array.
// count number of zeroes.
// using this amount, shift all the ints by that amount.
// add zeroes until end of array is reached
// [1 2 3], [9 0 1] -> [0 1 9]
// [0 0], [0 0 7 8]
int move_zeros(int* ar, int n) {
  //sort array
  qsort((void*)ar, n, sizeof(int), num_sort);
  int zeroes = 0;
  int pos = 0;
  // get amount of zeroes and stopping position
  while (pos < n && ar[pos] == 0) {
    zeroes++;
    pos++;
  }

// if there are just zeroes or no zeroes
  if (pos == n || zeroes == 0) 
    return zeroes;

//{1,2,3,3,1,0,0,0} -> [0 0 0 1 1 2 3 3] 
  while (pos < n) {
    ar[pos - zeroes] = ar[pos];
    pos++;
  }

  int fill_point = n - zeroes;
  while (fill_point < n) {
    ar[fill_point] = 0;
    fill_point++;
  }

  return zeroes;
}
// given list, return a copy of it.
// until list is empty, remove from head and add to tail to new 
// copy. return list
// store values from remove from head so it can be added later
LL_t* LL_copy(LL_t* list) {
  LL_t* new_list = LL_create();
  LL_t* copy_list = LL_create();

  while (list->head) {
    int val = LL_remove_from_head(list);
    LL_add_to_tail(new_list, val);
    LL_add_to_tail(copy_list, val);
  }

  while (copy_list->head) {
    LL_add_to_tail(list, LL_remove_from_head(copy_list));
  }

  LL_free(copy_list);
  return new_list;
}
