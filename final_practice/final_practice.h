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

typedef struct bt_node {
    int val;
    struct bt_node* parent;
    struct bt_node* left;
    struct bt_node* right;
} bt_node;

// should I typedef binary_tree to just be a node?
typedef struct {
   bt_node* root;
} binary_tree;

typedef binary_tree binary_search_tree;

typedef struct dl_node {
    int val;
    struct dl_node* next;
    struct dl_node* previous;
} dl_node;

typedef struct {
    dl_node* head;
    dl_node* tail;
    int elems;
} doubly_linked_list;


bool is_good_password(const char* str);

int find_peak(const int* A, int n); 

void sort_mountain(int* A, int n, int k); 

linked_list* create_list();

void free_list(linked_list* list);

void add_to_tail(linked_list* list, int val);

int rest(linked_list* list);

bool is_ordered_list(linked_list* list); 

// bt_node* create_bt_node(int val);

// binary_tree* create_tree_from_node(bt_node* root);

void destroy_tree(binary_tree* tree); 

binary_tree* arr_to_tree(int* arr, int length); 

bt_node* next_inorder(bt_node* nd);

void print_arr(int arr[], int size); 

void merge_sort(int arr[], int size); 

bool invalid_arr(int arr[]); 

bool is_invalid_interval(int start, int end); 

bool two_elems(int start, int end);

void order_pair(int arr[], int start, int end); 

int* order_arr_interval(int unsorted[], int start, int end, int pivot);

void overwrite_arr_interval(int target[], int sorted[], int start, int elems); 

void copy_elems_to_arr(int target_arr[], int start_pos, int source_arr[], int start, int end); 

void quick_sort(int arr[], int size); 

doubly_linked_list* create_dll(); 

void add_to_head(doubly_linked_list* list, int val); 

int rest_dll(doubly_linked_list* list); 

void remove_node(doubly_linked_list* list, dl_node* target); 

void print_list(doubly_linked_list* list); 

void filter(doubly_linked_list* list, bool (*func) (int)); 

void mirror_tree(binary_tree* tree); 

bt_node* find_predecessor(bt_node* nd); 

int longest_incr_subsequence(const int* arr, int size); 

bool has_elem_in_front(int pos, int end);

bool less_than_next_elem(const int* arr, int pos); 

int count_subseq(const int* arr, int pos, int end); 

char* print_max_number(const int* arr, int size); 

int* gen_freq(const int* arr, int size); 

bool just_zeroes(int* freq, int size); 

char* gen_string(int* freq, int size); 

int binary_search(const int* arr, int size, int target); 
#endif