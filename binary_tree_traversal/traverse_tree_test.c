#include "traverse_tree.h"
#include <stdio.h>



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
