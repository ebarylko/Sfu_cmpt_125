#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "labexam.h"


int longest_seq(const int* ar, int n, int k) {
  int i;
  int max=0;
  int count=0;
  for(i=0; i<n; i++) {
    if (ar[i]==k) {
      count++;
      if (count>max)
        max = count;
    }
    else {
      count=0;
    }
  }
  return max;
}

 
void hide_digits(char* str) {
  int i;
  int n = strlen(str);
  for(i=0; i<n; i++) {
    if (str[i] >= '0' && str[i] <= '9')
      str[i] = '*';
  }
}

int sum_leaves(const BTnode_t* root) {
  if (root==NULL)
    return 0;
  else if (root->left == NULL && root->right == NULL) 
    return root->value;
  else
    return sum_leaves(root->left) +  sum_leaves(root->right);
}
