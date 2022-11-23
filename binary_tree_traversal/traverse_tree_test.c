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

void mirror_tree_test() { 
binary_tree* tree = create_tree(1);

add_left_child(tree->root, 2);
add_right_child(tree->root, 3);

add_left_child(tree->root->left, 4);
add_right_child(tree->root->left, 5);

add_left_child(tree->root->right, 6);
add_right_child(tree->root->right, 7);

binary_tree* tree2 = create_tree(1);

add_left_child(tree2->root, 2);
add_right_child(tree2->root, 3);

add_left_child(tree2->root->left, 4);
add_right_child(tree2->root->left, 5);

add_left_child(tree2->root->right, 6);
add_right_child(tree2->root->right, 7);

// binary_tree* mirror = create_tree(1);

// add_right_child(mirror->root, 2);
// add_left_child(mirror->root, 3);

// add_right_child(mirror->root->right, 4);
// add_left_child(mirror->root->right, 5);

// add_right_child(mirror->root->left, 6);
// add_left_child(mirror->root->left, 7);

mirror_tree(tree2);
mirror_tree(tree2);


if (equal_trees(tree, tree2)) {
    printf("\n Mirroring trees worked--");
} else 
    printf("\n Mirroring trees failed--");
}

void tree_depth_test()
{
    binary_tree *tree2 = create_tree(1);

    add_left_child(tree2->root, 2);
    add_right_child(tree2->root, 3);

    add_left_child(tree2->root->left, 4);
    add_right_child(tree2->root->left, 5);

    add_left_child(tree2->root->right, 6);
    add_right_child(tree2->root->right, 7);

    int depth = tree_depth(tree2);

    if (depth == 1)
    {
        printf("\nrecursive Depth checking worked");
    }
    else
        printf("\nrecursive Depth checking failed, %d", depth);

    binary_tree *tree1 = create_tree(1);

    // add_left_child(tree1->root, 2);
    // add_left_child(tree1->root->left, 3);

    // add_left_child(tree1->root->left->left, 4);
    // add_left_child(tree1->root->left->left->left, 5);

    // add_right_child(tree1->root, 6);
    // add_right_child(tree2->root->right, 7);

    int iter_depth = iter_tree_depth(tree1);
    if (iter_depth == 2)
    {
        printf("\niterative Depth checking worked");
    }
    else
        printf("\niterative Depth checking failed, %d", iter_depth);
}

void arr_to_tree_test() {
    int expected[] = {1, 2, 3, 4, 5};
    binary_tree* tree = arr_to_tree(expected, 5);
    int actual[5];
    inorder_traverse(tree, actual, 5);

    if (compare_arrays(actual, expected, 5)) {
        printf("\nConverting array to inorder tree worked");
    } else  {
        printf("\nConverting array to inorder tree failed");
    }
   destroy_tree(tree); 
}

void create_bst_test() {
    binary_search_tree* bst = create_bst(5);
    if (bst) {
        printf("\nBst creation worked\n");
    } else {
        printf("\nBst creation failed\n");
    }
    destroy_bst(bst);
}

void bst_insertion_test() {
    binary_search_tree* bst = create_bst(5);
    insert(bst, 4);
    insert(bst, 9);
    insert(bst, 3);
    insert(bst, 7);
    insert(bst, 10);

    node* right = bst->root->right;
    node* left = bst->root->left;
    int smallest = left->left->val;
    int largest = right->right->val;
    int third_largest = right->left->val;

    if (right->val == 9 && left->val == 4) {
        printf("Bst insertion worked for first level\n");
    } else {
        printf("Bst insertion failed for first level\n");
    }

    if (smallest == 3 && largest == 10 && third_largest == 7) {
        printf("Bst insertion worked for second level\n");
    } else {
        printf("Bst insertion failed for second level\n");
    }

    destroy_bst(bst);
}

void find_node_test() {
    binary_search_tree* bst = create_bst(5);
    insert(bst, 4);
    insert(bst, 9);
    insert(bst, 3);
    insert(bst, 7);
    insert(bst, 10);

    if (!find(NULL, 8)) {
        printf("Find works on an empty tree\n");
    } else {
        printf("Find does not work on an empty tree\n");
    }

    node* found = find(bst, 3);
    node* not_found = find(bst, -1);

    if (found && found->val == 3 && !not_found) {
        printf("Find works on an filled tree\n");
    } else {
        printf("Find does not work on a filled tree\n");
    }

    destroy_bst(bst);
}


void delete_node_test() {
    binary_search_tree* bst = create_bst(5);
    insert(bst, 4);
    insert(bst, 9);


    delete_node(bst, bst->root->right);
    if (!bst->root->right) {
        printf("deletion works for nodes which are leaves\n");
    } else {
        printf("deletion does not work for nodes which are leaves\n");
    }


    binary_search_tree* bst2 = create_bst(5);
    insert(bst2, 4);
    insert(bst2, 9);
    insert(bst2, 10);

    // delete_node(bst, bst->root);
    delete_node(bst2, bst2->root->right);

    if (bst2->root->right->val == 10) {
        printf("node deletion works on a node with one child\n");
    } else {
        printf("node deletion does not work on a node with one child\n");
        printf("%d, %d\n", bst2->root->right->val, bst2->root->val);
    }
}

int main() {
    create_tree_test();
    add_children_test();
    equal_trees_test();
    mirror_tree_test();
    tree_depth_test();
    arr_to_tree_test();
    create_bst_test();
    bst_insertion_test();
    find_node_test();
    delete_node_test();
    return 0;
}
