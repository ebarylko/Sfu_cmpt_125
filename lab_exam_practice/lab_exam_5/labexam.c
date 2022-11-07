#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "labexam.h"

int lower_vowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
    return 1;
  }
  return 0;
}

// change lowercase vowels, return number of changes made
int modify(char* str) {
  int changes = 0;
  int pos = 0;
  while (str[pos]) {
    if (lower_vowel(str[pos])) {
      str[pos] = '*';
      changes++;
    }
    pos++;
  }
  return changes;
}

// modifies all lowercase vowels into asterisks
// returns number of changes made
// go over each string and check if char is lowercase vowel,
// if so modify it, and increment counter
//return counter at end
int vowels2asterisks(char* ar[], int n) {
  int changes = 0;
  for (int pos = 0; pos < n; pos++) {
    changes += modify(ar[pos]);
  }
  return changes;
}

int occurences(const int* arr, int pos, int length) {
  int val = arr[pos];
  int matches = 0;

  while (pos < length && arr[pos] == val) {
    matches++;
    pos++;
  }

  return matches;
}

// go through array, and count longest sequence
// if result is greater than max, change val,
// return max at end
int longest_equal_seq(const int* ar, int n) {
  int pos = 0;
  int max = 0;
  while (pos < n) {
    int matches = occurences(ar, pos, n);
    if (matches > max) 
      max = matches;
    pos += matches;
  }
  return max;
}

// take two queues and swap their content
// create third queue, and grab values of q1.
// put all values of q2 into q1, then put values from q3 into q2
// free q2.
void queues_swap(queue_t* q1, queue_t* q2) {
  // implement me
  return;
}  
