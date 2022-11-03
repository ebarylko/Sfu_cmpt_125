#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/BTnode.h"
#include "labexam.h"

void test_q1() { 
  int ar[4][3] = {{1, 2, 3},
                  {4, 7,-2},
                  {9,10,12},
                  {1, 5, 4}};
  int* m = max_row(4,3, ar);
  int m0 = m[0];
  int m1 = m[1];
  int m2 = m[2];
  int m3 = m[3];

  int ar2[1][1] = {{6}};
  int* mx = max_row(1,1, ar2);
  int mr = mx[0];
  free(m);
  free(mx); // checking dynamic memory allocation
  if (m0==3 && m1==7 && m2==12 && m3==5 && mr == 6)
    printf("Q1 ok\n");
  else
    printf("Q1 ERROR\n");
}

void test_q2() { 
  char str1[] = "HELLO WORLD";
  int ans1 = count_substrings(str1, 'L');
  if (ans1==2)
    printf("Q2-1 ok\n");
  else
    printf("Q2-1 ERROR : expected 2, return = %d\n", ans1);

  char* str2 = "AABBCD A*_* AAAACabcd";
  int ans2 = count_substrings(str2, 'A');
  if (ans2==3)
    printf("Q2-2 ok\n");
  else
    printf("Q2-2 ERROR : expected 3, return = %d\n", ans2);

}

void test_q3() { 
  BTnode_t* n1 = create_node(1);
  BTnode_t* n2 = create_node(2);
  BTnode_t* n3 = create_node(3);
  BTnode_t* n4 = create_node(4);
  BTnode_t* n5 = create_node(5);
  BTnode_t* n6 = create_node(6);
  BTnode_t* n7 = create_node(7);

  set_left_child(n1, n2);
  set_right_child(n1, n3);
  set_left_child(n2,n4);
  set_right_child(n2, n5);
  set_left_child(n3, n6);
  set_left_child(n6, n7);
/*
         n1
        /  \
      n2     n3
     / \    /
   n4  n5  n6
          /
        n7
*/

  int ans1 = count_nodes_one_child(n1);
  if (ans1==2)
    printf("Q3-1 ok\n");
  else
    printf("Q3-1 ERROR : expected 2, return = %d\n", ans1);

  int ans2 = count_nodes_one_child(n2);
  if (ans2==0)
    printf("Q3-2 ok\n");
  else
    printf("Q3-1 ERROR : expected 0, return = %d\n", ans2);

}

int main(void) {
  test_q1();
  test_q2();
  test_q3();
  return 0;
}
