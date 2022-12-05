#include "final_practice.h"
#include <assert.h>


// empty string, null string,
// string that has everything, string that does not have everything
void good_pwd_test() {

    if (!is_good_password(NULL) && !is_good_password("1234567")) {
        printf("pwd checking works on invalid strings\n");
    } else {
        printf("pwd checking does not work on invalid strings\n");
    }

    if (is_good_password("1eR@        ")) {
        printf("pwd checking works on good pwds \n");
    } else {
        printf("pwd checking does not work on good pwds\n");
    }

    if (!is_good_password("1eRreiuhr34ru34J")) {
        printf("pwd checking works on bad pwds \n");
    } else {
        printf("pwd checking does not work on bad pwds\n");
    }
}

void find_peak_test() {
    if (find_peak(NULL, 7) == 0) {
        printf("Peak searching works on a null arr\n");
    } else {
        printf("Peak searching does not work on a null arr\n");
    }

    int arr1[] = {1};

    if (find_peak(arr1, 1) == 0) {
        printf("Peak searching works on a arr with a single element\n");
    } else {
        printf("Peak searching does not work on a arr with a single element\n");
    }

    int arr2[] =  {1, 4, 5, 6, 7, 3, 1};
    if (find_peak(arr2, 7) == 4) {
        printf("Peak searching works on a filled arr\n");
    } else {
        printf("Peak searching does not work on a filled arr\n");
    }

    int arr3[] =  {10, 4};
    if (find_peak(arr3, 2) == 0) {
        printf("Peak searching works on a filled arr--\n");
    } else {
        printf("Peak searching does not work on a filled arr--\n");
    }

}

bool compare_arrays(int* arr1, int* arr2, int length) {
    for (int pos = 0; pos < length; pos++) {
        if (arr1[pos] != arr2[pos]) {
            return false;
        }
    }
    return true;
}

void mtn_scenario(int arr[], int length, int expected[], char* title) {
    sort_mountain(arr, length, find_peak(arr, length));

    if (compare_arrays(arr, expected, length)) {
        printf("\033[0;32m"); 
        printf("%s \xE2\x9C\x93 PASS\n", title);
    } else {
        printf("\033[0;31m"); 
        printf("%s FAIL\n", title);
    }
    printf("\033[0m");
}

void sort_mountain_test() {
    mtn_scenario(
        (int[7]){1, 4, 5, 6, 7, 3, 1}, 
        7, 
        (int[7]){1, 1, 3, 4, 5, 6, 7}, 
        "When the peak is in the middle"
    );

    mtn_scenario(
        (int[5]){1, 4, 5, 6, 7}, 
        5, 
        (int[5]){1, 4, 5, 6, 7}, 
        "When the peak is at the end"
    );

    int arr3[] = {9, 8, 7, 0};
    sort_mountain(arr3, 4, find_peak(arr3, 4));

    int correct3[] = {0, 7, 8, 9};
    if (compare_arrays(arr3, correct3, 4)) {
        printf("mountain sorting works on arrs with peak at the beginning\n");
    } else {
        printf("mountain sorting does not work on arrs with peak at the beginning\n");
    }

    int arr4[] = {8};
    sort_mountain(arr4, 1, find_peak(arr4, 1));

    int correct4[] = {8};
    if (compare_arrays(arr4, correct4, 1)) {
        printf("mountain sorting works on arrs with one elem\n");
    } else {
        printf("mountain sorting does not work on arrs with one elem\n");
    }

    int* arr5 = NULL;
    sort_mountain(arr5, 0, find_peak(arr5, 0));

    if (compare_arrays(arr5, NULL, 0)) {
        printf("mountain sorting works on null arrs\n");
    } else {
        printf("mountain sorting does not work on null arrs\n");
    }


}

linked_list* list_from_arr(int arr[], int size) {
    linked_list* list = create_list();
    for (int pos = 0; pos < size; pos++) {
        add_to_tail(list, arr[pos]);
    }
    return list;
}

void linked_list_scenario(int arr[], int size, char* title) {
    linked_list* list = list_from_arr(arr, size);

    if (is_ordered_list(list)) {
        printf("\033[0;32m"); 
        printf("%s \xE2\x9C\x93 PASS\n", title);
    } else {
        printf("\033[0;31m"); 
        printf("%s FAIL\n", title);
    }
    printf("\033[0m");

    free_list(list);
}


void negative_first_test() {
    linked_list_scenario(NULL,
     0,
      "Empty list");

    linked_list_scenario(
        (int[3]){4, 7, 0},
         3,
          "List with solely positive numbers");

    linked_list_scenario(
        (int[3]){-4, -7, -0},
         3,
          "List with solely negative numbers");

    linked_list_scenario(
        (int[4]){-4, -7, 1, 9},
         4,
          "List with positive and negative numbers in order");

    linked_list_scenario(
        (int[4]){-4, 7, -1, 9},
         4,
          "List with positive and negative numbers not in order");
}

bt_node* smallest_left_node(binary_tree* tree) {
    if (!tree)
        return NULL;

    bt_node* nd = tree->root;

    while (nd->left) {
        nd = nd->left;
    }

    return nd;
}

void print_node(bt_node* nd, int indent) {
    if (!nd) 
        return;
    printf("%.*s%d (%d)\n", indent, "\t\t\t\t\t\t\t\t\t\t", nd->val, nd->parent ? nd->parent->val : 999);
    print_node(nd->left, indent + 1);
    print_node(nd->right, indent + 1);
}  

void inorder_traversal_scenario(int arr[], int size, char* title) {
    binary_tree* tree = arr_to_tree(arr, size);
    assert(tree || !size);

    if (tree) 
        print_node(tree->root, 0);

    bt_node* nd = smallest_left_node(tree);
    assert(nd || !size);

    int pos = 0;

    while ( pos < size && nd && arr[pos] == nd->val) {
      printf("Inorder val: %d\n", nd->val);
      nd = next_inorder(nd);
      pos++;
    }

    if (pos == size) {
        printf("\033[0;32m"); 
        printf("%s \xE2\x9C\x93 PASS\n", title);
    } else {
        // printf("pos: %d\n", pos);
        // printf("arr: %d, node: %d\n", arr[pos], nd ? nd->val : -168);
        printf("\033[0;31m"); 
        printf("%s FAIL\n", title);
    }
    printf("\033[0m");

    destroy_tree(tree);
}

// cases: empty tree, tree with one elem, tree with nodes all to the right 
// or left, balanced tree
void inorder_traversal_test() {
    inorder_traversal_scenario(
        NULL, 0, "Empty tree");

    inorder_traversal_scenario(
        (int[1]){6}, 1, "Tree with one element");

    inorder_traversal_scenario(
        (int[6]){2, 8, 9, 0, -1, -2}, 6, "Tree with multiple elements");
    
    inorder_traversal_scenario(
        (int[2]){2, 8}, 2, "Tree with two elements");
}

// test: invalid_arr, invalid_interval, two elems, order_pair,
// order arr_interval, overwrite arr interval
void merge_sort_component_test() {
    int arr[] = {1, 2, 3};
    if (invalid_arr(NULL)) {
        printf("valid array check works for empty arrs\n");
    } else {
        printf("valid array check does not works for empty arrs\n");
    }

    if (!invalid_arr(arr)) {
        printf("valid array check works for arrs\n");
    } else {
        printf("valid array check does not works for arrs\n");
    }

    // invalid interval
    if (!is_invalid_interval(0, 0)) {
        printf("valid interval check works for interval of one elem\n");
    } else {
        printf("valid interval check does not work for interval of one elem\n");
    }

    if (!is_invalid_interval(4, 9)) {
        printf("valid interval check works for non-empty interval\n");
    } else {
        printf("valid interval check does not work for non-empty interval\n");
    }

    if (is_invalid_interval(2, 1)) {
        printf("valid interval check works for invalid interval\n");
    } else {
        printf("valid interval check does not work for invalid interval\n");
    }
    
    //two_elems test
    if (two_elems(1, 2)) {
        printf("two element check works\n");
    } else {
        printf("two element check does not work\n");
    }

    if (!two_elems(1, 9)) {
        printf("two element check works on interval of 2+ elems\n");
    } else {
        printf("two element check does not work on interval of 2+ elems\n");
    }

    // order_pair: start < end, start > end
    int actual1[] = {2, 1, 3};
    int expected1[] = {1, 2, 3};
    order_pair(actual1, 0, 1);

    if (compare_arrays(actual1, expected1, 3)) {
        printf("pair swap works\n");
    } else {
        printf("pair swap does not work\n");
    }

    int actual2[] = {3, 3};
    int expected2[] = {3, 3};
    order_pair(actual2, 0, 1);

    if (compare_arrays(actual2, expected2, 2)) {
        printf("pair swap works--\n");
    } else {
        printf("pair swap does not work--\n");
    }


}


int main() {
    good_pwd_test();
    find_peak_test();
    sort_mountain_test();
    negative_first_test();
    inorder_traversal_test();
    merge_sort_component_test();
    return 0;
}
