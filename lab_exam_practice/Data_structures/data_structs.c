#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

//data structures

typedef struct node{
    int data;
    struct node* next;
} node;

typedef struct {
    node* head;
    node* tail;
    int elems;
} linked_list;

typedef node* linked_list_iterator;

linked_list_iterator create_iterator(linked_list* list) {
return list->head;
}


bool has_next(linked_list_iterator iter) {
return iter && iter->next;
}

int get_elem(linked_list_iterator iter) {
return iter->data;
}

linked_list_iterator next(linked_list_iterator iter) {
return iter->next;
}

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

// get size of list
int get_size(linked_list* list) {
    return list->elems;
}

// adds to head
void add_to_head(linked_list* list, int val) {
    node* node = create_node(val);
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
//adds to tail
void add_to_tail(linked_list* list, int val) {
    node* node = create_node(val);
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
// gives all elements after head, returns taken element
int rest(linked_list* list) {
    if (!list->elems)
        return -1;


    node* old_head = list->head;
    int val = old_head->data;
    if (list->elems == 1) {
        list->tail = NULL;
    }

    list->head = list->head->next;
    free(old_head);
    list->elems--;
    return val;
}

//remove element from tai
// if only one element, made head and tail point to the same place
// if not, traverse until tail, free tail, set new tail, decrement size

void remove_tail(linked_list* list){ 
    if (!(list->elems))
        return;

    if (list->elems == 1) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    } else {
    node* curr = list->head;
    while (curr->next != list->tail)    
        curr = curr->next;

    free(list->tail);
    curr->next = NULL;
    list->tail = curr;
    }
    (list->elems)--;
}

//practice problems
/**
 *Write a function node_t* get_middle(LL_t* list).
* The function gets a linked list, and returns the pointer to the middle element.

* If the number of element in the list is even, it returns the pointer to the element in position (size/2).
* If the list is empty the function returns NULL.

* You may not assume that you have the length() function. @brief 
 * @brief 
 * 
 */
 // go up to midpoint, and return node at that point. if empty, return NULL
 // when midpoint is zero, we know to stop

node* get_mid(const linked_list* list) {
    if (!(list->elems)) 
        return NULL;
    int mid = list->elems / 2;
    node* curr = list->head;

    while (mid-- != 0)
        curr = curr->next;

    return curr;
}

// question 2
/**
 *Write a function LL_t* copy_list(LL_t* orig).
* The function gets a pointer to a linked list, and returns a copy with the have same elements in the same order.
* In the end orig must be in the same state as in the beginning.
 @brief 
 * 
 */


//tests

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

    add_to_head(list, 5);
    add_to_head(list, 6);
    add_to_head(list, 3);
    add_to_tail(list2, 5);
    add_to_tail(list2, 6);
    add_to_tail(list2, 3);

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

    add_to_head(list, 5);
    add_to_head(list, 6);
    add_to_head(list, 3);

    add_to_tail(list2, 5);
    // add_to_tail(list2, 6);
    // add_to_tail(list2, 3);

    rest(list);
    remove_tail(list2);
    if (list->elems == 2 && list->head->data == 6 && list->tail->data == 5) {
        printf("\nHead_removal worked");
    } else 
        printf("\nHead_removal failed");
        printf("\n %d, head: %d, tail: %d", list->elems, list->head->data, list->tail->data);

    if (list2->elems == 0 && list2->head == list2->tail) {
        printf("\nHead_removal worked for list 2");
    } else 
        printf("\nHead_removal failed for list 2");
        printf("\n %d, head: %d, tail: %d", list2->elems, list2->head, list2->tail);
}

void mid_list_test() {
    linked_list* list = create_list();
    int arr[] = {1};
    for (int pos = 0; pos < 1; pos++) 
        add_to_tail(list, arr[pos]);
    node* mid_node = get_mid(list);
    int val = mid_node->data;
    // free(mid_node);
    if (val == 1) {
        printf("middle node matches");
    } else {
        printf("Middle node does not match: %d", mid_node->data);
    }
}


int main() {
    list_exists_test();
    add_node_test();
    remove_node_test();
    // mid_list_test();
    return 0;
}