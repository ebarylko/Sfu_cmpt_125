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
  int* new_arr = (int*)malloc(n * sizeof(int));
  int pos;
  for (pos = 0; pos < n; pos ++) {
    new_arr[pos] = arr[pos];
  }
  qsort((void*)new_arr, n, sizeof(int), comp);
  int i = 0, max = 0, cnt = 0, num;
  while (i < n) {
    cnt = max_occur(new_arr, new_arr[i], i, n);
    if (cnt > max)  {
      num = new_arr[i];
    }
    i += cnt;
  }
  free(new_arr);
  return num;
}


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
  //int length = strlen(str);
  //  for (int i = 0; str[i] != NULL; i++) {
  //    for(int pos = length - 1 - i; pos >= i; pos -= 1) {
  //      if ((pos - i) % 2 == 0) {
  //        if (is_palindrome(str, i, pos) && (pos - i + 1) > max) {
  //          max = (pos - i + 1) ;
    for (int i = 0; str[i] != '\0'; i++) {
      for(int pos = i; str[pos] != '\0'; pos++) {
        if ((pos - i) % 2 == 0) {
          if (is_palindrome(str, i, pos) && (pos - i + 1) > max) {
            max = (pos - i + 1) ;
        }
      }
    }
  }
  return max;
 } 


/*
Initialize mod = 0
quo[i] = (mod * 10 + num[i]) / m
mod = (mod * 10 + num[i]) % m
Where i denotes the position of the i-th digit

*/

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
