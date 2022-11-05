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
    struct node* next;
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

node* create_node(int val) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}

void free_node(node* node) {
;
}

//if empty, add and make head and tail point to same place
// make element point to head, and replace it as the head
// increment size list
// if size is 0, when adding elem head and tail point to the same place
void add_to_head(linked_list* list, node* node) {
    node->next = list->head;
    list->head = node;
    if (!(list->elems)) {
        list->tail = node;
    }
    (list->elems)++;
}

// if empty, add and make head and tail point to same place
// make tail point to new pointer, and make new pointer be tail
// increment size of list
// if empty 
void add_to_tail(linked_list* list, node* node) {
    if (!(list->elems)) {
        list->tail = node;
        list->head = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    (list->elems)++;
}

// if empty, do nothing
// else, assign another variable of the head, and make the element in front of
// the head be the new head. free the old head, and decrement the size of the list
// if only one element, make the tail null after
void remove_head(linked_list* list) {
    if (!(list->elems))
        return;


    node* old_head = list->head;
    if (list->elems == 1) {
        list->head = NULL;
        list->tail = NULL;
    } else 
        list->head = list->head->next;

    free(old_head);
    (list->elems)--;
}

void list_exists_test() {
    linked_list* list = create_list();
    if (list) {
        printf("The list is valid");
    } else 
        printf("The list is not valid");
}

void add_node_test() {
    linked_list* list = create_list();
    linked_list* list2 = create_list();

    node* node1 = create_node(5);
    node* node2 = create_node(6);
    node* node3 = create_node(3);
    add_to_head(list, node1);
    add_to_head(list, node2);
    add_to_head(list, node3);
    add_to_tail(list2, node1);
    add_to_tail(list2, node2);
    add_to_tail(list2, node3);

    if (list->elems == 3 && list->head->data == 3 && list->tail->data == 5) {
        printf("\nHead_insertion worked");
    } else 
        printf("Head_insertion failed");

    if (list2->elems == 3 && list2->head->data == 5 && list2->tail->data == 3) {
        printf("\nTail_insertion worked");
    } else 
        printf("\nTail_insertion failed");

}

void remove_node_test() {
    linked_list* list = create_list();
    linked_list* list2 = create_list();

    node* node1 = create_node(5);
    node* node2 = create_node(6);
    node* node3 = create_node(3);

    add_to_head(list, node1);
    add_to_head(list, node2);
    add_to_head(list, node3);

    add_to_tail(list2, node1);
    add_to_tail(list2, node2);
    add_to_tail(list2, node3);

    remove_head(list);
    if (list->elems == 2 && list->head->data == 6 && list->tail->data == 5) {
        printf("\nHead_removal worked");
    } else 
        printf("\nHead_removal failed");
        printf("\n %d, head: %d, tail: %d", list->elems, list->head->data, list->tail->data);

    // if (list2->elems == 3 && list2->head->data == 5 && list2->tail->data == 3) {
    //     printf("\nTail_insertion worked");
    // } else 
    //     printf("\nTail_insertion failed");

}


int main() {
    list_exists_test();
    add_node_test();
    remove_node_test();
    return 0;
}