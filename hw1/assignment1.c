#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assignment1.h"
#include <stdbool.h>

/**
 * @brief count even numbers between x and y, inclusive  
 * @param x starting number 
 * @param y ending number
 * @return a long with the amount of even numbers between x and y, inclusive 
 */
long count_even(long x, long y)
{
  bool odd_x = x % 2 != 0, odd_y = y % 2 != 0;
  long digits = x > y ? x - y : y - x ;
  // The amount of even numbers between x and y is always half the difference
  // plus one if one or both numbers are even.
  return digits / 2 + !(odd_x && odd_y);
}


/**
 * @brief takes an array of integers, the current position, and the length of the array
 * @param arr an array of positive or negative integers
 * @param pos the current position to start from in the array
 * @param length the size of the array
 * @return int the number of times the integer occurs in the array
 */
int occurrences(const int *arr, int pos, int length) {
  int curr_num = arr[pos];
  int start_pos = pos;
  while (arr[pos] == curr_num && pos < length) {
    pos++;
  }
  return pos - start_pos;
}

/**
 * @brief comparing function used for qsort
 * @param a pointer to a number 
 * @param b pointer to a number
 * @return a positive int if *a is greater than *b, 
 * 0 if *a = *b, a negative int otherwise
 */
int comp(const void* a, const void* b) {
  return ( *(int*)a - *(int*)b);
}


/**
 * @brief gets a array of integers, and returns the most frequent integer in the array
 * @param arr an array of positive or negative integers
 * @param n the quantity of numbers in the array
 * @return int the most frequent occuring integer in the array
 */
int most_frequent(const int* arr, int n) {
  int* new_arr = (int*)malloc(n * sizeof(int));
  for (int pos = 0; pos < n; pos ++) {
    new_arr[pos] = arr[pos];
  }
  qsort((void*)new_arr, n, sizeof(int), comp);
  int i = 0, max = 0, cnt = 0, num;
  while (i < n) {
    cnt = occurrences(new_arr, i, n);
    if (cnt > max)  {
      num = new_arr[i];
    }
    i += cnt;
  }
  free(new_arr);
  return num;
}

/**
 * @brief takes a string, and returns true if it is an odd palindrome, false otherwise
 * @param str the string to check
 * @return true if the string is an odd palindrome
 * @return false if the condition above is not satisfied
 */
bool is_odd_palindrome(const char* str) {
  int length = strlen(str);
  if (length % 2 == 0)
  {
    return false;
  }
  //calculating the middle index of the string
  int chars = (length - 1) / 2, i;
  //checking that the characters before the middle index match the characters after the middle index
  for (i = 0; i < chars && str[i] == str[length - 1 - i]; i++)
    ;
  return i == chars;
}



/**
 * @brief takes a string and returns the length of the largest odd palindrome within
 * @param str the string to check
 * @return int the length of the largest odd palindrome found
 */
int longest_odd_subpalindrome(const char *str)
{
  int max = 0;
  int length = strlen(str);
  int middle = length / 2;

  for (int i = 0; str[i] != '\0'; i++)
  {
    int limit = i <= middle ? i : length - i - 1;
    int pos;
    for (pos = 1; pos <= limit && str[i - pos] == str[i + pos]; pos++)
      ;

    if ((2 * pos - 1) > max)
    {
      max = 2 * pos - 1;
    }
  }
  return max;
}

char* str_div_by_digit(const char* num, int digit) {
  int length = strlen(num);
  int mod = 0, pos = 0;
  int i;
  char* result = (char*)malloc( (length + 3) * sizeof(char));

  for (i = 0; i < length; i++) {
    int dt = num[i] - '0';
    mod = mod * 10 + dt;
    result[pos] = mod / digit + '0';
    if (pos || result[pos] != '0') {
      pos++;
    }
    mod =  (mod % digit);
  }
  mod %= digit;
  if (!pos) {
    pos++; 
  }
  result[pos++] = 'R';
  result[pos++] = mod + '0';
  result[pos] = '\0';
  return result;
}  
