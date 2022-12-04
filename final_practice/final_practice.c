#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


#include "final_practice.h"

bool is_lowercase(char c) {
    return c >= 'a' && c <= 'z';
}

bool is_uppercase(char c) {
    return c >= 'A' && c <= 'Z';
}

bool is_symbol(char c) {
    return c == '!' ||  c == '#' || c == '@';
}

bool valid_pwd(const char* str) {
    int digits = 0;
    int lower_case = 0;
    int upper_case = 0;
    int symbols = 0;

    while (*str) {
        if (isdigit(*str))
            digits++;

        if (is_lowercase(*str))
            lower_case++;

        if (is_uppercase(*str))
            upper_case++;

        if (is_symbol(*str))
            symbols++;

        str++;
    }

    return digits && lower_case && upper_case && symbols;
}

bool is_good_password(const char* str) {
    if (!str || strlen(str) < 8 ) 
        return false;

    return valid_pwd(str);
}

// if pos == length, I can't check to the right. must check to the left and see
// that left value is smaller than val at pos
// if pos == start, same issue as above but cant check to the right
// if pos - 1 > pos, return true. else, false
// must check if val to the left bigger than val at pos.
// if pos == start, return false. else, return the check
bool right_of_mountain(const int* arr, int pos, int start, int end) {
    if (pos == start)
        return false;

    return arr[pos] < arr[pos - 1];
}

bool left_of_mountain(const int* arr, int pos, int start, int end) {
    if (pos == end)
        return false;

    return arr[pos] < arr[pos + 1];
}

//  [1, 4, 5, 6, 7, 3, 1]
// check if midpoint is right or left of mountain,
// if left of mountain go from mid + 1 to end
// if right of mountain go from start to mid - 1
// if not left or right of mountain, point is the mountain. return val
int peak(const int* arr, int start, int end) {
    int mid = (end - start + 1) / 2;

    if (right_of_mountain(arr, start + mid, start, end)) 
        return peak(arr, start, start + mid - 1);
    
    if (left_of_mountain(arr, start + mid, start, end)) 
        return peak(arr, start + mid + 1, end);

    return start + mid;
}

// [1 3 5 2 0]
// [10, 4]
// [-1 0 3 4 5 8]
// return 0 if !A or n = 1
// if at index 0 val is greater than right found peak
// if at index n - 1 val greater than left found peak
// 
int find_peak(const int* A, int n)  {
    if (!A || n == 1)
      return 0;

    return peak(A, 0, n - 1);
}


//Write a function that gets a mountain array of length n, and the index k
//representing the peak, and sorts the array in the increasing order in O(n) time.
// if !A, return.


void swap(int* arr, int pos1, int pos2) {
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

void reverse_mountain(int* arr, int length) {
    int mid = length / 2;
    int end = length - 1;
    for (int pos = 0; pos < mid; pos++) {
        swap(arr, pos, end - pos);
    }
}

void overwrite_arr(int* arr1, int* arr2, int size) {
    for (int pos = 0; pos < size; pos++) {
        arr1[pos] = arr2[pos];
    }
}

void order_mountain(int* arr, int length) {
    int* new_arr = (int*)malloc(sizeof(int) * length);

    int start = 0;
    int end = length - 1;
    int new_pos = 0;

    while (start <= end) {
        int val = arr[start] > arr[end] ? arr[end--] : arr[start++];
        new_arr[new_pos++] = val;
    }

    overwrite_arr(arr, new_arr, length);
    free(new_arr);
}

void sort_mountain(int* A, int n, int k) {
    if (!A || n <= 1 || k == n - 1)
        return;

    order_mountain(A, n);
}

node* create_node(int val) {
    node* nd = (node*)malloc(sizeof(node));
    nd->val = val;
    nd->next = NULL;
    return nd;
}

linked_list* create_list() {
    linked_list* list = (linked_list*)malloc(sizeof(linked_list));
    list->head = NULL;
    list->tail = NULL;
    list->elems = 0;
    return list;
}


bool is_empty_list(linked_list* list) {
    return list->elems == 0;
}

void add_to_tail(linked_list* list, int val) {
    if (!list) 
        return;

    node* nd = create_node(val);

    if (is_empty_list(list)) {
        list->head = nd;
    } else {
      list->tail->next = nd;
    }

    list->tail = nd;
    list->elems++;
}

int rest(linked_list* list) {
    if (!list || is_empty_list(list)) 
        return 0;

    node* old_head = list->head;
    int val = old_head->val;
    list->head = old_head->next;
    free(old_head);
    list->elems--;

    if (is_empty_list(list)) {
        list->tail = NULL;
    }

    return val;
}

void free_list(linked_list* list) {
    while (list->head)
        rest(list);
    free(list);
}

bool pos_before_neg(node* nd) {
    return nd->val >= 0 && nd->next->val < 0;
}

bool is_ordered_list(linked_list* list) {
    if (!list || is_empty_list(list))
      return true;

    node* nd = list->head;
    while (nd->next && !pos_before_neg(nd)) {
        nd = nd->next;
    }
    
    return nd->next ? false : true;
}