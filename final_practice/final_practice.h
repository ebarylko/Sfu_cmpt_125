#ifndef FINAL_PRACTICE
#define FINAL_PRACTICE

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node {
    int val;
    struct node* next;
} node;

typedef struct {
    node* head;
    node* tail;
    int elems;
} linked_list;

bool is_good_password(const char* str);

int find_peak(const int* A, int n); 

void sort_mountain(int* A, int n, int k); 

linked_list* create_list();

void free_list(linked_list* list);

void add_to_tail(linked_list* list, int val);

int rest(linked_list* list);

bool is_ordered_list(linked_list* list); 
#endif