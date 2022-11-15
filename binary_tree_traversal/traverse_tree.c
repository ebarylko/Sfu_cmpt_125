#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


// contract: binary tree will have children and parent. will be a collection of
// nodes, will not be sorted and not be balanced.
// will be able to search for parents, and children
// create tree, add children, destroy tree
// should I make function for accessing children? (should not changee regardless 
// of implementation)
// if adding children, must take a node
// could have a function that creates a node

typedef struct node {
    int val;
    struct node* parent;
    struct node* left;
    struct node* right;
} node;

// should I typedef binary_tree to just be a node?
typedef struct {
    node* root;
} binary_tree;

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

binary_tree* create_tree(int val) {
    binary_tree* tree = (binary_tree*)malloc(sizeof(binary_tree));
    node* root = create_node(val);
    tree->root = root;
    return tree;
}

// void destroy_tree(binary_tree*) {

// }

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

//tests

void create_tree_test() {
    binary_tree* tree = create_tree(1);
    if (tree && tree->root->val == 1) {
        printf("\nTree creation worked");
    } else {
        printf("\nTree creation failed");
    }
}

void add_children_test() {
    binary_tree* tree = create_tree(1);

    add_left_child(tree->root, 2);
    add_right_child(tree->root, 3);

    if (tree && tree->root->left->val == 2 && tree->root->right->val == 3) {
        printf("\nadding children worked");
    } else {
        printf("\nadding children failed");
    }
}


int main() {
    create_tree_test();
    add_children_test();
    return 0;
}