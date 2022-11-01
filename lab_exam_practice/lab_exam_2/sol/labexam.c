#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "labexam.h"

int compute_max_row_i(int height, int width, int ar[][width], int i) {
  int max = ar[i][0];
  int j;
  for (j=1;j<width; j++) {
    if (ar[i][j] > max)
      max = ar[i][j];
  }
  return max;
}

int* max_row(int height, int width, int ar[][width]) {
  int* MAX = (int*) malloc(height*sizeof(int));
  int i;
  for (i=0; i<height; i++)
    MAX[i] = compute_max_row_i(height, width, ar, i);
  return MAX;
}

int count_substrings(const char* str, char c) {
  int i;
  int count=0;
  int n = strlen(str);
  bool last_is_c = false;
  for (i=0; i<n; i++) {
    if (str[i] != c)
      last_is_c = false;
    else if (!last_is_c)  {
      count++;
      last_is_c = true;
    }
  }
  return count;
}


int count_nodes_one_child(const BTnode_t* root) {
  if (root==NULL)
    return 0;
  else if (root->left==NULL && root->right==NULL)
    return 0;
  else if (root->left!=NULL && root->right!=NULL)
    return count_nodes_one_child(root->left) + count_nodes_one_child(root->right);
  else // has one child
    return count_nodes_one_child(root->left) + count_nodes_one_child(root->right) + 1;
}
