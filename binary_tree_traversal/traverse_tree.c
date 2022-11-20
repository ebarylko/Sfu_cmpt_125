#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "traverse_tree.h"

// contract: binary tree will have children and parent. will be a collection of
// nodes, will not be sorted and not be balanced.
// will be able to search for parents, and children
// create tree, add children, destroy tree
// should I make function for accessing children? (should not changee regardless 
// of implementation)
// if adding children, must take a node
// could have a function that creates a node

// should this function take a val, since to create a tree requires a root,
// and a root needs a value.

node* create_node(int val) {
    node* nd = (node*)malloc(sizeof(node));
    nd->val = val;
    nd->parent = NULL;
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

void destroy_node(node* target) {
    if (!target) 
        return;
    destroy_node(target->left);
    destroy_node(target->right);
    free(target);
}

binary_tree* create_tree_from_node(node* root) {
    binary_tree* tree = (binary_tree*)malloc(sizeof(binary_tree));
    tree->root = root;
    return tree;
}

binary_tree* create_tree(int val) {
    node* root = create_node(val);
    return create_tree_from_node(root);
}

void destroy_tree(binary_tree* tree) {
    if (!tree) 
        return;
    destroy_node(tree->root);
    free(tree);
}

void add_left_child(node* tree, int val) {
    if (!tree)
        return;
    tree->left = create_node(val);
    tree->left->parent = tree;
}

void add_right_child(node* tree, int val) {
    if (!tree)
        return;
    tree->right = create_node(val);
    tree->right->parent = tree;
}
//       1
//      2 3
//2:  4 5 6 7

int inorder_node(node* target, int arr[], int size, int index) {
    if (!target) 
        return 0;
    int left = inorder_node(target->left, arr, size, index);
    if (index + left >= size)
        return left;
    arr[index + left] = target->val;
    int right = inorder_node(target->right, arr, size, index + left + 1);
    return left + right + 1;
}

int inorder_traverse(binary_tree* tree, int arr[], int size) {
    if (!tree)
        return 0;
    return inorder_node(tree->root, arr, size, 0);
}

int postorder_node(node* target, int arr[], int size, int index) {
    if (!target) 
        return 0;
    int left = postorder_node(target->left, arr, size, index);
    if (index + left >= size)
        return left;

    int right = postorder_node(target->right, arr, size, index + left);
    arr[index + left + right] = target->val;
    return left + right + 1;
}


int postorder_traverse(binary_tree* tree, int arr[], int size) {
    if (!tree)
        return 0;
    return postorder_node(tree->root, arr, size, 0);
}

// Write an algorithm that given two Binary Trees checks if they are equal.
bool equal_nodes(node* nd1, node* nd2) {
if (!nd1 ^ !nd2)
    return false;

if (!nd1 && !nd2) 
    return true;

int match = nd1->val == nd2->val;

return nd1->val == nd2->val &&
       equal_nodes(nd1->left, nd2->left) &&
       equal_nodes(nd1->right, nd2->right);
}

// check one node at a time, if nodes are valid check if they match. if they do not,
//return false. if both nodes are null, return true. if one is is null and other is 
// valid, return false.
// if both trees null, return true. if one tree null return false
bool equal_trees(binary_tree* tr1, binary_tree* tr2) {
if (!tr1 && !tr2)
    return true;

if (!tr1 ^ !tr2)
    return false;

return equal_nodes(tr1->root, tr2->root);
}

//Write an algorithm that gets a Binary Tree and modifies the tree so that it becomes its
// own mirror image. What happens when you apply the algorithm on a tree twice? 
//       1
//      2 3
//2: 4  5  6 7
//       1
//      3 2
//2: 7  6  5 4

void print_node(node* nd) {
    if (!nd) 
        return;
    printf("%d\n", nd->val);
    print_node(nd->left);
    print_node(nd->right);
}

void print_tree(binary_tree* tree) {
    if (!tree) 
        return;
    print_node(tree->root);
}

void mirror_nodes(node* nd) {
    if (!nd) 
        return;
    mirror_nodes(nd->left);
    mirror_nodes(nd->right);
    node* temp = nd->left;
    nd->left = nd->right;
    nd->right = temp;
}

void mirror_tree(binary_tree* tree) {
    if (!tree) 
        return;
    mirror_nodes(tree->root);
}

// Write an algorithm that gets a tree and computes 
//its depth using recursive/iterative implementation.

//recursively 

int max(int a, int b) {
    return a > b ? a : b;
}

int node_depth(node* nd) {
    if (!nd) 
        return -1;
    return max(node_depth(nd->left), node_depth(nd->right)) + 1;
}

int tree_depth(binary_tree* tree) {
    if (!tree) 
        return 0;
    return node_depth(tree->root);
}

//iteratively
// data type; stack that can hold a node of a tree
// stack: create, destroy, push, pop, size
// create stack, then add root. while stack not empty, do following check:
// if node is not valid, return 0. else, check distance from the root.
// if distance from root greater than max, change max. else, do nothing.
// push onto stack left and right nodes

linked_list* create_list() {
    linked_list* list = (linked_list*)malloc(sizeof(linked_list));
    list->head = NULL;
    list->tail = NULL;
    list->elems = 0;
    return list;
}

new_node* make_node(node* val) {
    new_node* new_nd = (new_node*)malloc(sizeof(new_node));
    new_nd->data = val;
    new_nd->next = NULL;
    return new_nd;
}

linked_list_iterator create_iterator(linked_list* list) {
return list->head;
}

bool has_next(linked_list_iterator iter) {
return iter;
}

node* get_elem(linked_list_iterator iter) {
return iter->data;
}

linked_list_iterator next(linked_list_iterator iter) {
return iter->next;
}


// get size of list
int get_size(linked_list* list) {
    int size = 0;
    linked_list_iterator iter = create_iterator(list);
    while (has_next(iter)) {
        size++;
        iter = next(iter);
    }
    return size;
}

// adds to head
void add_to_head(linked_list* list, node* val) {
    new_node* node = make_node(val);
    node->next = list->head;
    list->head = node;
    if (!(list->elems)) {
        list->tail = node;
    }
    (list->elems)++;
}


// gives all elements after head, returns taken element
node* rest(linked_list* list) {
    if (!list->elems)
        return NULL;

    new_node* old_head = list->head;
    node* val = old_head->data;
    if (list->elems == 1) {
        list->tail = NULL;
    }

    list->head = list->head->next;
    free(old_head);
    list->elems--;
    return val;
}

void free_list(linked_list* list) {
    while (list->head)
        rest(list);
    free(list);
}

typedef linked_list stack;

stack* create_stack() {
    stack* new_stack = create_list();
    return new_stack;
}

void free_stack(stack* stack) {
    free_list(stack);
}

int stack_size(stack* stack) {
    return get_size(stack);
}

void push(stack* stack, node* val) {
    add_to_head(stack, val);
}

node* pop(stack* stack) {
    return rest(stack);
}

int height(node* nd) {
    int height = 0;
    while (nd->parent) {
        height++;
        nd = nd->parent;
    }
    return height;
}

int iter_tree_depth(binary_tree* tree) {
    if (!tree) 
        return 0;

    int max = 0;
    stack* stack = create_stack();
    push(stack, tree->root);
    while (stack_size(stack)) {
        int ht;
        node* result = pop(stack);
        if ( (ht = height(result)) > max) 
            max = ht;

        if (result->left)
            push(stack, result->left);
        if (result->right)
            push(stack, result->right);
    }
    return max;
}

// Write an algorithm that gets an array of numbers and returns a 
//Binary Tree whose InOrder traversal is this sequence.
// There might be more than one such tree.

// if start > end || start < 0 || end >= size ||
// [ 1 2 3 4 5]
// [1 2]
// [4 5]
// [4]
// [1]
// I do not know where to transfer following node for func call


/**
 * @brief Create the root node and attaches left and right
 * 
 * @param start 
 * @param end 
 * @param size 
 * @return node* 
 */
node* inorder_from_array(int *arr, int start, int end, int size) {
    // check that is valid, if not return
    if (start > end || start < 0 || end >= size)
    {
        return NULL;
    }

    int root = (end - start + 1) / 2;

    // I know root index is the root
    node *root_node = create_node(arr[start + root]);

    root_node->left = inorder_from_array(arr, start, start + root - 1, size);
    root_node->right = inorder_from_array(arr, start + root + 1, end, size);

    return root_node;
}

// check middle of the array. make that element the root.
// repeat on the left and right subtrees, giving the correct function
// helper function: take a node, an array, a function, and a set of stop/start
// indices. 
// stop: if start index > stop index || start < 0, return
// else: calculate midpoint of points given. add that to start index and 
// then add to node using function passed. repeat on vals to the left and right of
// midpoint. adjust start/stop to reflect this. 
// if start = stop, add then do nothing
/**
 * @brief takes an array, and returns a binary tree such that traversing it in order 
 * gives the values of the array
 * 
 * @param arr the array
 * @param length size of the array
 * @return binary_tree* the tree filled with the values of the array in inorder positioning
 */
binary_tree* arr_to_tree(int* arr, int length) {
    if (!arr) 
        return NULL;

    node *root = inorder_from_array(arr, 0, length - 1, length);
    return create_tree_from_node(root);
}

// ejercisios:
// arbol binario: 1, 3, 5, 7
// bsts:5 6