#include "assignment3.h"
/**
 * @brief takes two strings, and returns the difference of their lengths if 
 * they do not have the same length. else, returns the strcmp of the two strings
 * 
 * @param str1 the first string to compare
 * @param str2 the second string to compare
 * @return int the difference in the lengths of the two strings if they are not 
 * the same, else returns the difference of the first character of each string
 */
int string_sort(const void* str1, const void* str2) {
  const char* act_str1 = *(const char**)str1;
  const char* act_str2 = *(const char**)str2;
  int len_1 = strlen(act_str1);
  int len_2 = strlen(act_str2);
  if (len_1 != len_2) {
    return len_1 - len_2;
  }
  return strcmp(act_str1, act_str2);
}

/**
 * @brief takes an array of strings and a integer N 
 * representing the length of the array sorts the array such that
 * longer strings come after shorter strings and strings of equal length are
 * ordered by result of comparing first character
 * 
 * @param A an array of strings
 * @param n an integer representing the size of the array
 */
void sort_strings(const char* A[], int n) {
  qsort((void*)A, n, sizeof(char*), string_sort);
}  

/**
 * @brief takes an array of ints, and two indices in the array. swaps the values
 * of the indices in the array
 * 
 * @param arr 
 * @param index1 
 * @param index2 
 */
void swap(int arr[], int index1, int index2) {
  int temp = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = temp;
}

/**
 * @brief takes an array of ints and a number N indicating the amount of elements.
 * sorts the array using insertion sort and returns an array of length N 
 * where every position from 0 -> n-1 has the value of how many swaps were made
 * for insertion sort of original array at that pos
 * 
 * @param array an array of integers
 * @param n the amount of elements in the array
 * @return int* an array where every pos has the value of how many swaps were made
 * in the other array using insertion sort
 */
int* insertion_sort(int* array, int n) {
  int* new_ar = (int*)malloc(n * sizeof(int));
  // no swaps are made on the first element
  new_ar[0] = 0;
  int swaps;
  int j;
  //regular insertion sort, but now marks amount of swaps made
  for (int start = 1; start < n; start++) {
    swaps = 0;
    j = start;
    while (array[j - 1] > array[j] && j > 0) {
      swap(array, j - 1, j);
      j--;
      swaps++;
    }
    new_ar[start] = swaps;
  }

  return new_ar;
}

/**
 * @brief takes an array of integers, the length of the array, and a boolean predicate
 * if the predicate returns true for an element in the array, returns the index
 * of the first element which the predicate returns true. else, returns -1.
 * 
 * @param A 
 * @param n 
 * @param pred 
 * @return int 
 */
int find(int* A, int n, bool (*pred)(int)) {
  int pos;
  for (pos = 0; pos < n && !pred(A[pos]); pos++);
  return pos < n ? pos : -1;
}

/**
 * @brief takes an array, the length of the array, and a predicate.
 * returns the amount of items for which the predicate returns true
 * 
 * @param A 
 * @param n 
 * @param pred 
 * @return int 
 */
int count(int* A, int n, bool (*pred)(int)) {
  int matches = 0;
  for (int pos = 0; pos < n; pos++) {
    if (pred(A[pos])){
      matches++;
    }
  }
  return matches;
}

/**
 * @brief takes an array, length of array, and a function. applies the function to
 * every element in the array
 * 
 * @param A 
 * @param n 
 * @param f 
 */
void map(int* A, int n, int (*f)(int)) {
  for (int pos = 0; pos < n; pos++) {
    A[pos] = f(A[pos]);
  }
}

/**
 * @brief takes an array, the length of the array, and a function that takes
 * two integers. returns the result after applying the function to the first two
 * elements, then applying it to the result of the first call with the third 
 * element, and then applying it to the result of the last call with the fourth 
 * element, and so forth until the end. returns the accumalated value of all the 
 * calls
 * @param A 
 * @param n 
 * @param f 
 * @return int 
 */
int reduce(int* A, int n, int (*f)(int,int)) {
int acc = A[0];  
for (int pos = 1; pos < n; pos++) {
  acc = f(acc, A[pos]);
}
return acc;
}
