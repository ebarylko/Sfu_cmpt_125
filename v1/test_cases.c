#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "labexam.h"

void test_q1() { 
  const char* ar[] = {"123", "abc", "hello", "yes", "---"};
  const char* correct[] = {ar[4],ar[3],ar[2],ar[1],ar[0]};

  rev_arr(ar, 5);


  /**********test answer**********/ 
  bool okFlag = true;
  for(int i=0;i<5;i++) {
    if (strcmp(ar[i],correct[i])!=0) {
      okFlag = false;
    }
  }

  if (okFlag)
    printf("Q1 ok\n");
  else
    printf("Q1 ERROR\n");
}

void test_q2() { 
  int ar1[] = {1,2,0,3,0,3,1,0};
  int ar2[] = {9,0,0,0,0,0,0,0,0,111};
  int ans1 = move_zeros(ar1, 8);
  int ans2 = move_zeros(ar2, 10);


  /**********test answer**********/ 
  int correct1[] = {1,2,3,3,1,0,0,0};
  int correct2[] = {9,111,0,0,0,0,0,0,0,0};

  bool okFlagAns = (ans1==3 && ans2==8);
  if (!okFlagAns)
    printf("Q2 ERROR : incorrect answer\n");

  bool okFlagArr = true;
  for(int i=0;i<6;i++) {
    if (ar1[i]!=correct1[i])
      okFlagArr = false;
  }
  for(int i=0;i<10;i++) {
    if (ar2[i]!=correct2[i])
      okFlagArr = false;
  }
  if (!okFlagArr)
    printf("Q2 ERROR : incorrect arrays\n");

  if (okFlagAns && okFlagArr)
    printf("Q2 ok\n");

}


void test_q3() { 
  LL_t* list = LL_create();
  for(int i=0;i<=10;i++) {
    LL_add_to_head(list, i);
    LL_add_to_tail(list, i);
  }

  LL_t* ans = LL_copy(list);


  /**********test answer**********/ 
  bool okFlag = (ans && list!=ans && LL_equal(list, ans));

  if (list)
    LL_free(list);
  if (ans)
    LL_free(ans);
  
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
