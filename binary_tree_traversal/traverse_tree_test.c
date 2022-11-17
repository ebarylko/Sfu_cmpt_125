#include "traverse_tree.h"
#include <stdio.h>
#include <stdbool.h>



void create_tree_test() {
    binary_tree* tree = create_tree(1);
    if (tree && tree->root->val == 1) {
        printf("\nTree creation worked");
    } else {
        printf("\nTree creation failed");
    }
}

bool compare_arrays(int arr1[], int arr2[], int size) {
    for (int pos = 0; pos < size; pos++) {
        if (arr1[pos] != arr2[pos])
            return false;
    }
    return true;
}
//       1
//      2 3
//2: 4  5  6 7
//3:     
void add_children_test() {
    binary_tree* tree = create_tree(1);

    add_left_child(tree->root, 2);
    add_right_child(tree->root, 3);

    add_left_child(tree->root->left, 4);
    add_right_child(tree->root->left, 5);

    add_left_child(tree->root->right, 6);
    add_right_child(tree->root->right, 7);

    int expected[] = {4, 2, 5, 1, 6, 3, 7};
    int actual[7];

    int counted = inorder_traverse(tree, actual, 7);

    if (compare_arrays(expected, actual, 7)) {
        printf("\nadding children worked");
    } else {
        printf("\nadding children failed");
    }

    // int expected_post[] = {4, 5, 2, 6, 7, 3, 1};
    int actual_post[7];
    int counted_post = postorder_traverse(tree, actual_post, 7);

    if (compare_arrays(expected, actual_post, 7)) {
        printf("\nadding children worked--");
    } else {
        printf("\nadding children failed--");
    }
}

void equal_trees_test() {
    binary_tree* tree = create_tree(1);
    add_left_child(tree->root, 2);
    add_right_child(tree->root, 3);

    binary_tree* tree2 = create_tree(1);
    add_left_child(tree2->root, 2);
    add_right_child(tree2->root, 9);


    if (!equal_trees(tree, NULL)) {
        printf("\n Equal tree check worked");
    } else 
        printf("\n Equal tree check failed");

    if (equal_trees(tree, tree2)) {
        printf("\n Equal tree check worked--");
    } else 
        printf("\n Equal tree check failed--");

    if (equal_trees(NULL, NULL)) {
        printf("\n Equal tree check worked-x");
    } else 
        printf("\n Equal tree check failed-x");


}



int main() {
    create_tree_test();
    add_children_test();
    equal_trees_test();
    return 0;
}
