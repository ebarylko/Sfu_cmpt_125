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

binary_tree* create_tree(int val) {
    binary_tree* tree = (binary_tree*)malloc(sizeof(binary_tree));
    node* root = create_node(val);
    tree->root = root;
    return tree;
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
