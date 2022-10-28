#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/BTnode.h"
#include "labexam.h"

// void print_arr(int arr[], int length) {
//   for (int pos = 0; pos < length; pos++) {
//     printf("\n%d-", arr[pos])
//   }
// }

void test_q1() { 
  int a1[] = {1, 1, 3, 3, 3, 1, 5, 1};
  if (longest_seq(a1, 8, 1) == 2)
    printf("Q1-1 ok\n");
  else
    printf("Q1-1 ERROR\n");

  int seq;
  int a2[] = {1,3,3,2,3,3,3,3};
  if ((seq = (longest_seq(a2, 8, 3))) == 4)
    printf("Q1-2 ok\n");
  else
    printf("Q1-2 ERROR\n val:%d", seq);

  int a3[] = {3,3,3,3,3,3,3,3};
  if (longest_seq(a3, 8, 3) == 8)
    printf("Q1-3 ok\n");
  else
    printf("Q1-3 ERROR\n");

  int a4[] = {1,3,3,2,3,3,3,3};
  if (longest_seq(a4, 8, 9) == 0)
    printf("Q1-4 ok\n");
  else
    printf("Q1-4 ERROR\n");

}

void test_q2() { 
  char str1[] = "hi123";
  hide_digits(str1);
  if (strcmp(str1, "hi***")==0)
    printf("Q2-1 ok\n");
  else
    printf("Q2-1 ERROR : expected 'hi***', return = %s\n", str1);

  char str2[] = "Hello World";
  hide_digits(str2);
  if (strcmp(str2, "Hello World")==0)
    printf("Q2-2 ok\n");
  else
    printf("Q2-2 ERROR : expected 'Hello World', return = %s\n", str2);

  char str3[] = "";
  hide_digits(str3);
  if (strcmp(str3, "")==0)
    printf("Q2-3 ok\n");
  else
    printf("Q2-3 ERROR : expected '', return = %s\n", str1);

}

void test_q3() { 

  BTnode_t* r = create_node(1);
  BTnode_t* x = NULL;


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
/*       n1
        /  \
      n2     n3
     / \    /
   n4  n5  n6
          /
        n7
*/

  int sum_n = sum_leaves(n1);
  int sum_r = sum_leaves(r);
  int sum_x = sum_leaves(x);

  if (sum_n ==16 && sum_r == 1 && sum_x == 0) // 4+5+7==16
    printf("Q3 ok\n");
  else
    printf("Q3 ERROR : expected 16, return = %d\n", sum_n);

}

int main(void) {
  test_q1();
  test_q2();
  test_q3();
  return 0;
}
