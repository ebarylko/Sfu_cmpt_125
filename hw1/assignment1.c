#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3, -3: 3|| 3, -4: 4|| 2, -2: 3

#include "assignment1.h"
// use inline if test? true : false
long count_even(long x, long y)
{
  bool odd_x = x % 2 != 0, odd_y = y % 2 != 0;
  long digits = x > y ? x - y : y - x ;
  return digits / 2 + !(odd_x && odd_y);
}

int comp(const void* a, const void* b) {
  return ( *(int*)a - *(int*)b);
}

//  int ar[6] = {1,7,-3,7,4,7};
// [-3, 1, 4, 7, 7, 7]

// typedef struct Plateau {
//   int nbr;
//   int length;
// } Pt;

// Pt count_pt(const int* arr, int n, int i) {
//   while (i < n && arr[i] == arr[j]) //   {
//     i++;
//   }

//   Pt pt = {arr[j], i - j};
//   return pt;
// }

int max_occur(const void *arr, int curr_num, int pos, int length) {
  int occured = 0;
  while (*((int *)arr + pos) == curr_num && pos < length) {
    occured += 1;
    pos++;
  }
  return occured;
}

int most_frequent(const int* arr, int n) {
  qsort((void*)arr, n, sizeof(int), comp);
  int i = 0, max = 0, cnt = 0, num;
  while (i < n) {
    cnt = max_occur(arr, arr[i], i, n);
    if (cnt > max)  {
      num = arr[i];
    }
    i += cnt;
  }
  return num;
}

  // there are X plataeus x1, x2...
  // while (i < n)
  // {
  //   Pt pt = count_pt(arr, n, i);
  //   max = max_fn(max, pt.length);
  //   i += pt.length - 1;
  // }



bool is_odd_palindrome(const char* str) {
  int length = strlen(str);
  if (length % 2 == 0)
  {
    return false;
  }
  int chars = (length - 1) / 2, i;
  for (i = 0; i < chars && str[i] == str[length - 1 - i]; i++)
    ;
  return i == chars;
}


bool is_palindrome(const char* str, int start, int end) {
  int i, j = 0, mid = (end - start) / 2;
  for (i = start; i < start + mid && str[i] == str[end - j]; i++, j++)
    ;
  return i == start + mid;
}

 int longest_odd_subpalindrome(const char* str) {
  int max = 0;
  for (int i = 0; str[i] != NULL; i++) {
    for(int pos = i; str[pos] != NULL; pos++) {
      if ((pos - i) % 2 == 0) {
        if (is_palindrome(str, i, pos) && (pos - i + 1) > max) {
          max = (pos - i + 1) ;
        }
      }
    }
  }
  return max;
 } 


char* str_div_by_digit(const char* num, int digit) {
  // implement me
  return NULL;
}  
