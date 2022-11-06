#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "labexam.h"

void test_q1() { 
  char* str1 = "Hello";
  char* str2 = "olleH";

  char* str3 = "Creativity";
  char* str4 = "Creativity";

  /**********test answer**********/
  if (is_reverse(str1, str2) && !is_reverse(str3, str4))
    printf("Q1 ok\n");
  else
    printf("Q1 ERROR\n");
}

void test_q2() { 
  int ar1[] = {2,6,2,3,8,9};
  LL_t* ans = array_to_LL(ar1, 6);
  
  /**********test answer**********/
  if (ans==NULL) {
    printf("Q2 ERROR : ans==NULL\n");
    return;
  }

  LL_t* correct_ans = LL_create();
  LL_add_to_tail(correct_ans,2);
  LL_add_to_tail(correct_ans,6);
  LL_add_to_tail(correct_ans,2);
  LL_add_to_tail(correct_ans,3);
  LL_add_to_tail(correct_ans,8);
  LL_add_to_tail(correct_ans,9);


  bool okFlag=LL_equal(ans, correct_ans);
  
  LL_free(correct_ans);
  LL_free(ans);

  if (okFlag)  
    printf("Q2 ok\n");
  else
    printf("Q2 ERROR : incorrect values\n");

}


void test_q3() { 

  stack_t* s = stack_create();
  for(int i=0;i<10;i++)
    stack_push(s,i);

  stack_forget(s, 4);

  /**********test answer**********/
  stack_t* correct_ans = stack_create();
  for(int i=4;i<10;i++)
    stack_push(correct_ans,i);


  bool okFlag=LL_equal(s->list, correct_ans->list);
  
  stack_free(correct_ans);
  stack_free(s);

  if (okFlag)
    printf("Q3 ok\n");
  else
    printf("Q3 ERROR\n");
}

int main(void) {
  test_q1();
  test_q2();
  test_q3();
  return 0;
}
