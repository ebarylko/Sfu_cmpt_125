#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "traverse_tree.h"
#define max(a, b) (a > b ? a : b)


node* create_node(int val) {
    node* nd = (node*)malloc(sizeof(node));
    nd->val = val;
    nd->parent = NULL;
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

void destroy_subtree(node* target) {
    if (!target) 
        return;
    destroy_subtree(target->left);
    destroy_subtree(target->right);
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
    destroy_subtree(tree->root);
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

// binary search tree:
// contract: search in log n, insert in log n, create tree, delete tree, delete node
// elements to the left of the node are smaller or =, elements to the right are bigger

binary_search_tree* create_bst(int val) {
    binary_search_tree* tree = create_tree(val);
    return tree;
}

void destroy_bst(binary_search_tree* tree) {
    destroy_tree(tree);
}


void insert(binary_search_tree* tree, int val) {
    if (!tree) 
        return;

    node* curr = tree->root;
    node* prev = NULL;

    while (curr) {
        prev = curr;
        curr = val > curr->val ? curr->right : curr->left;
    }

    if (prev) {
        if (val > prev->val) {
            add_right_child(prev, val);
        } else {
            add_left_child(prev, val);
        }
    } else {
        tree->root = create_node(val);
    }
}


node* find(binary_search_tree* tree, int val) {
    if (!tree) 
        return NULL;

    node* nd = tree->root;
    while (nd && nd->val != val) {
        nd = val > nd->val ? nd->right : nd->left;
    }

    return nd;
}

// if tree not valid, get out.
// if node is leaf, set it = null for parent
// cases: node has parent/ has no parent:
// if no parent, free node. else, free node and set parent to point to null
// if it has one child, link parent and child
// if no parent above node, mreplace nd with child
// if it has two children, find smallest val in right sub tree and replace node with it

bool leaf(node* nd) {
    return !nd->left && !nd->right;
}

bool left_child(node* child, node* parent) {
    return parent->left == child;
}


node* one_child(node* nd) {
    if (!nd->left ^ !nd->right) {
        return nd->left ? nd->left : nd->right;
    }
    return NULL;
}

node* largest_left(node* nd) {
    while (nd->right) {
        nd = nd->right;
    }
    return nd;
}

// if nd has one child: connect parent to child. free node afterwards
//if nd has parent; connect child to parent.
// if nd !parent: simply replace node with child
// always store node somewhere temporarily
// if it has two children: find the largest in the left subtree, replace node with that
//  if nd has parent: change parent to point to replacement, replacement->left points
// to nd->left and replacement->right points to nd->right
// if no parent: everything from above, except the parent change
void delete_node(binary_search_tree* tree, node* nd) {
    if (!tree) 
        return;

    // iif node is a leaf
    if (leaf(nd)) {
        if (nd->parent) {
            if (left_child(nd, nd->parent)) {
                nd->parent->left = NULL;
            } else {
                nd->parent->right = NULL;
            }
        } else {
            tree->root = NULL;
        }
        free(nd);   
        return; 
    }

    
//     // if node has a child
    node* child;
    if ((child = one_child(nd))) {
        if (nd->parent) {
            if (left_child(nd, nd->parent)) {
                nd->parent->left = child;
            } else {
                nd->parent->right = child;
            }
            child->parent = nd->parent;
        } else {
            tree->root = child;
        }
        free(nd);
        return;
    }

    // if node has two children
    node* replacement = largest_left(nd->left);
    if (left_child(replacement, replacement->parent)) {
        replacement->parent->left = NULL;
    } else {
        replacement->parent->right = NULL;
    }

    replacement->left = nd->left;
    replacement->right = nd->right;

    if (nd->parent) {
        if (left_child(nd, nd->parent)) {
            nd->parent->left = replacement;
        } else {
            nd->parent->right = replacement;
        }
    } else {
        tree->root = replacement;
    }
    free(nd);
    return;
}

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

    int mx = 0;
    stack* stack = create_stack();
    push(stack, tree->root);
    while (stack_size(stack)) {
        int ht;
        node* result = pop(stack);
        mx = max(mx, height(result));

        if (result->left)
            push(stack, result->left);
        if (result->right)
            push(stack, result->right);
    }
    return mx;
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