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


int longest_equal_seq(const int* ar, int n) {
  // implement me
  return -1;
}


void queues_swap(queue_t* q1, queue_t* q2) {
  // implement me
  return;
}  
