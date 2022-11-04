#include <stdio.h>
#include <stdlib.h>

/**
 *queue the functions are: enqueue, dequeue, isEmpty.
For Stack the functions are: push, pop, isEmpty.
For Linked List the functions are: add_to_head, add_to_tail, remove_from_head,
 remove_from_tail, as well as list->head, node->next, node->data.... @brief 
 * 
 */

/**
 *Write a function node_t* get_middle(LL_t* list).
* The function gets a linked list, and returns the pointer to the middle element.

* If the number of element in the list is even, it returns the pointer to the element in position (size/2).
* If the list is empty the function returns NULL.

* You may not assume that you have the length() function. @brief 
 * 
 */

// linked list: head, tail, number of elements
// node: data, pointer to next node

typedef struct node{
    int data;
    node* next;
} node;

typedef struct {
    node* head;
    node* tail;
    int elems;
} linked_list;

linked_list* create_list() {
    linked_list* list = (linked_list*)malloc(sizeof(linked_list));
    list->head = NULL;
    list->tail = NULL;
    list->elems = 0;
    return list;
}

void list_exists_test() {
    linked_list* list = create_list();
    if (list) {
        printf("The list is valid");
    } else 
        printf("The list is not valid");
}


int main() {
    list_exists_test();
    return 0;
}