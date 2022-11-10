#include <stdlib.h>
#include <stdio.h>

#include "LL.h"



LL_t* LL_create() {
    LL_t* ret = malloc(sizeof(LL_t));
    if (ret == NULL)
        return NULL;
    ret->head = NULL;
    ret->tail = NULL;
    return ret;
}


void LL_add_to_head(LL_t* list, int value) {
    node_t* newNode = (node_t*) malloc(sizeof(node_t));
    
    if (newNode == NULL)
        return;

    newNode->data = value;
    newNode->next = list->head;

    if (list->head==NULL) { // edge case
      list->head = newNode;
      list->tail = newNode;
    }
    else {
      list->head = newNode;
    }
}

void LL_add_to_tail(LL_t* list, int value) {
 
    node_t* newNode = (node_t*) malloc(sizeof(node_t));
    if (newNode == NULL)
        return;

    newNode->data = value;
    newNode->next = NULL;

    if (list->head==NULL) {  // edge case: list was empty
      list->head = newNode;
      list->tail = newNode;
    }
    else {
      list->tail->next = newNode;
      list->tail = newNode;
    }
}

int LL_remove_from_head(LL_t* list) {
  node_t* prev_head = list->head;
  int ret = prev_head->data;
 
  list->head = list->head->next;

  if (list->head==NULL) // edge case: list becomes empty
    list->tail = NULL;

  LLnode_free(prev_head);
  return ret;
}


void LL_print(LL_t* list) {
  node_t* current = list->head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

bool LL_equal(LL_t* l1, LL_t* l2) {
  node_t* cur1 = l1->head;
  node_t* cur2 = l2->head;
  while (cur1 && cur2) {
    if (cur1->data!=cur2->data) 
      return false;
    cur1=cur1->next;
    cur2=cur2->next;
  }
  return (cur1==NULL && cur2==NULL);
}


void LLnode_free(node_t* node) {
  free(node);
}


void LL_free(LL_t* list) {
  node_t* cur;
  while (list->head != NULL) {
    cur = list->head;
    list->head = cur->next;
    LLnode_free(cur); 
  }
  free(list);
}
