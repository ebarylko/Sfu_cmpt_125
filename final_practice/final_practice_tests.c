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

    // order arr interval: 1 elem, 1+ elem, sorted, unsorted

    int arr3[] = {1};
    int* new_arr3 = order_arr_interval(arr3, 0, 0, 0);
    if (compare_arrays(arr3, new_arr3, 1)) {
        printf("arr ordering works on one elem--\n");
    } else {
        printf("arr ordering does not work on one elem--\n");
    }
    free(new_arr3);

    int arr4[] = {1, 2, 4, 9};
    int* new_arr4 = order_arr_interval(arr4, 0, 3, 2);
    if (compare_arrays(arr4, new_arr4, 4)) {
        printf("arr ordering works on sorted elems--\n");
    } else {
        printf("arr ordering does not work on sorted elems--\n");
    }
    free(new_arr4);

    int arr5[] = {9, 8, 7, 6};
    int* new_arr5 = order_arr_interval(arr5, 1, 2, 2);
    int expected5[] = {7, 8};
    if (compare_arrays(expected5, new_arr5, 2)) {
        printf("arr ordering works on unsorted elems--\n");
    } else {
        printf("arr ordering does not work on unsorted elems--\n");
    }
    free(new_arr5);

    // overwrite_arr_interval

    int target[] = {1, 2, 3, 4};
    int write_over[] = {9, 0, -1, 3};

    overwrite_arr_interval(target, write_over, 0, 4);
    if (compare_arrays(target, write_over, 4)) {
        printf("write over works\n");
    } else {
        printf("write over does not work\n");
    }

    int target2[] = {1, 2, 3, 4};
    int write_over2[] = {7, 8};
    int expected_arr[] = {1, 2, 7, 8};

    overwrite_arr_interval(target2, write_over2, 2, 2);
    if (compare_arrays(target2, expected_arr, 4)) {
        printf("write over works in an interval\n");
    } else {
        printf("write over does not work in an interval\n");
    }

    // copy_elems to arr test

}

void merge_sort_scenario(int arr[], int expected[], int size, char* title) {
    merge_sort(arr, size);

    if (compare_arrays(arr, expected, size)) {
        printf("\033[0;32m"); 
        printf("%s \xE2\x9C\x93 PASS\n", title);
    } else {
        printf("\033[0;31m"); 
        printf("%s FAIL\n", title);
        print_arr(arr, size);
    }
    printf("\033[0m");

}

void merge_sort_test() {
    merge_sort_scenario(
        (int[1]){1},
        (int[1]){1},
        1,
        "Arr with one elem"
    );

    // [ 1 2 3 7 9]
    // [ 1 2 8 9 -1 0] -> [-1 2 8 9 1 0] -> [-1 0 2 8 9 1] -> [-1 0 1 2 8 9]
// [- 8 1 2]
// [1 -2]
    merge_sort_scenario(
        (int[6]){9, 8, 2, 1, 0, -1},
        (int[6]){-1, 0, 1, 2, 8, 9},
        6,
        "Arr with unsorted elems"
    );

    merge_sort_scenario(
        (int[3]){ -8, 1, 2},
        (int[3]){ -8, 1, 2},
        3,
        "Arr with sorted elems"
    );

    merge_sort_scenario(
        (int[5]){20, 11, 5, 4, 2},
        (int[5]){2, 4, 5, 11, 20},
        5,
        "Arr with all elems unsorted"
    );

    merge_sort_scenario(
        (int[7]){20, 11, 5, 4, 2, 3, 4},
        (int[7]){2, 3, 4, 4, 5, 11, 20},
        7,
        "Arr with duplicate elems"
    );

    merge_sort_scenario(
        (int[6]){1, 1, 1, 1, 1, 1},
        (int[6]){1, 1, 1, 1, 1, 1},
        6,
        "Arr with all elems being duplicates"
    );
}

void quick_sort_scenario(int arr[], int expected[], int size, char* title) {
    quick_sort(arr, size);

    if (compare_arrays(arr, expected, size)) {
        printf("\033[0;32m"); 
        printf("%s \xE2\x9C\x93 PASS\n", title);
    } else {
        printf("\033[0;31m"); 
        printf("%s FAIL\n", title);
        print_arr(arr, size);
    }
    printf("\033[0m");

}

void quick_sort_test() {
    quick_sort_scenario(
        (int[1]){1},
        (int[1]){1},
        1,
        "Arr with one elem"
    );

    quick_sort_scenario(
        (int[5]){1, 2, 3, 4, 5},
        (int[5]){1, 2, 3, 4, 5},
        5,
        "Arr with sorted elems"
    );

    quick_sort_scenario(
        (int[5]){1, -1, 5, -1, -1},
        (int[5]){-1, -1, -1, 1, 5},
        5,
        "Arr with duplicate + unsorted elems"
    );

    quick_sort_scenario(
        (int[10]){1, 0, -3, -2, -6, -4, 3, 1, 0, -44,} ,
        (int[10]){-44, -6, -4, -3, -2, 0, 0, 1, 1, 3},
        10,
        "Arr with 10 elems"
    );

    quick_sort_scenario(
        (int[4]){1, 0, -3, -2} ,
        (int[4]){-3, -2, 0, 1},
        4,
        "Arr with unsorted elems"
    );
}

void dll_component_test() {
    doubly_linked_list* list = create_dll();
    if (list) {
        printf("dll creation works\n");
    } else {
        printf("dll creation does not work\n");
    }
}

doubly_linked_list* create_dll_from_arr(int arr[], int size) {
    doubly_linked_list* list = create_dll();
    for (int pos = 0; pos < size; pos++) {
        add_to_head(list, arr[pos]);
    }
    return list;
}

bool compare_list_arr(doubly_linked_list* list, int arr[], int size) {
    dl_node* nd = list->head;
    for (int pos = 0; pos < size; pos++) {
        if (arr[pos] != nd->val) {
            return false;
        }
        nd = nd->next;
    }
    return true;
}

void print_list(doubly_linked_list* list) {
    dl_node* nd = list->head;
    while (nd) {
        printf("Node val: %d\n", nd->val);
        nd = nd->next;
    }
}

void dll_add_scenario(int arr[], int expected[], int size, char* title) {
    doubly_linked_list* list = create_dll_from_arr(arr, size);

    if (compare_list_arr(list, expected, size)) {
        printf("\033[0;32m"); 
        printf("%s \xE2\x9C\x93 PASS\n", title);
    } else {
        printf("\033[0;31m"); 
        printf("%s FAIL\n", title);
    }
    printf("\033[0m");

}

void dl_add_test() {
    dll_add_scenario(NULL, NULL, 0, "Empty arr");

    dll_add_scenario(
        (int[1]){3},
        (int[1]){3},
        1,
        "Arr with one elem");

    dll_add_scenario(
        (int[3]){1, 2, 3},
        (int[3]){3, 2, 1},
        3,
        "Arr with three elems");
}

void repeated_rest(doubly_linked_list* list, int repetitions) {
    for (int i = 0; i < repetitions; i++) {
        rest_dll(list);
    }
}

void dll_rest_scenario(int arr[], int expected[], int size, int removal, char* title) {
    doubly_linked_list* list = create_dll_from_arr(arr, size);
    repeated_rest(list, removal);

    if (compare_list_arr(list, expected, size - removal)) {
        printf("\033[0;32m"); 
        printf("%s \xE2\x9C\x93 PASS\n", title);
    } else {
        printf("\033[0;31m"); 
        printf("%s FAIL\n", title);
    }
    printf("\033[0m");

}

void dll_rest_test() {
    dll_rest_scenario(NULL, NULL, 0, 0, "Empty arr");

    dll_rest_scenario(
        (int[1]){1}, 
        NULL,
        1,
        1,
        "list with one elem");

    dll_rest_scenario(
        (int[3]){1, 2, 2}, 
        (int[1]){1},
        3,
        2,
        "list with three elem");

    dll_rest_scenario(
        (int[3]){1, 2, 2}, 
        NULL,
        3,
        3,
        "list with three elems, full removal of all elems");
}

void remove_node_scenario(doubly_linked_list* list, int expected[], int size, dl_node* target, char* title) {

    remove_node(list, target);

    if (compare_list_arr(list, expected, size - 1)) {
        printf("\033[0;32m"); 
        printf("%s \xE2\x9C\x93 PASS\n", title);
    } else {
        printf("\033[0;31m"); 
        printf("%s FAIL\n", title);
    }
    printf("\033[0m");
}

void remove_node_test() {
    doubly_linked_list* list1 = create_dll_from_arr(NULL, 0);
    remove_node_scenario(list1, NULL, 0, NULL, "Empty list");

    doubly_linked_list* list2 = create_dll_from_arr(
        (int[1]){1}, 1);
    remove_node_scenario(list2, NULL, 1, list2->head, "list with one elem");

    doubly_linked_list* list3 = create_dll_from_arr(
        (int[5]){1, 2, 3, 4, 5}, 5);

    remove_node_scenario(
        list3,
         (int[4]){4, 3, 2, 1},
          5,
           list3->head,
            "removing head from list");

    doubly_linked_list* list4 = create_dll_from_arr(
        (int[5]){1, 2, 3, 4, 5}, 5);

    remove_node_scenario(list4,
     (int[4]){5, 4, 3, 2},
      5,
       list4->tail,
        "removing tail from list with many elems");

    doubly_linked_list* list5 = create_dll_from_arr(
        (int[5]){1, 2, 3, 4, 5}, 5);

    remove_node_scenario(list5,
     (int[4]){5, 4, 2, 1},
      5,
       list5->head->next->next,
        "removing middle node from list with many elems");
}

// create list, apply pred, check with expected list
void filter_scenario(int arr[], int expected[], int arr_size, int expected_size, bool (*func)(int), char* title) {
    doubly_linked_list* list = create_dll_from_arr(arr, arr_size);
    filter(list, func);

    if (compare_list_arr(list, expected, expected_size)) {
        printf("\033[0;32m"); 
        printf("%s \xE2\x9C\x93 PASS\n", title);
    } else {
        printf("\033[0;31m"); 
        printf("%s FAIL\n", title);
    }
    printf("\033[0m");
}

bool is_even(int val) {
    return (val % 2) == 0;
}


void filter_test() {
    filter_scenario(
        NULL, 
        NULL, 
        0,
        0,
        is_even,
        "Empty list"
    );

    filter_scenario(
        (int[4]){1, 2, 3, 4}, 
        (int[2]){4, 2}, 
        4,
        2,
        is_even,
        "list with some elements failing predicate"
    );

    filter_scenario(
        (int[4]){1, 9, 3, 7}, 
        NULL,
        4,
        0,
        is_even,
        "list with no elements passing predicate"
    );

    filter_scenario(
        (int[4]){2, 4, 6, 8}, 
        (int[4]){8, 6, 4, 2}, 
        4,
        4,
        is_even,
        "list with all elements passing predicate"
    );
}

// after reversing, must check to see if values from tree match
// must see if after reversing twice I have the same tree
// scenario: arr with values to generate tree, size of arr
// expected arr, title
// generate first tree, mirror, and then check against second tree.
// if they match, good. if not, bad

// equal if both are null, or if both match in every node
// 
// if one node not valid, false.
// true if both null or both values match
// must check on remaining nodes

// 

bool nodes_match(bt_node* nd1, bt_node* nd2) {
    return nd1->val == nd2->val;
}

bool compare_nodes(bt_node* nd1, bt_node* nd2) {
    if (!nd1 ^ !nd2)
        return false;

    if (!nd1 && !nd2)
        return true;

    return nodes_match(nd1, nd2) &&
    compare_nodes(nd1->left, nd2->left) &&
    compare_nodes(nd1->right, nd2->right);
}

bool compare_trees(binary_tree* tree1, binary_tree* tree2) {
    if (!tree1 ^ !tree2)
        return false;

    if (!tree1 && !tree2)
        return true;

    return compare_nodes(tree1->root, tree2->root);
}

void mirror_tree_comp_test() {
    binary_tree* tree1 = arr_to_tree((int[3]){1, 2, 3}, 3);
    binary_tree* tree2 = arr_to_tree((int[3]){1, 2, 3}, 3);

    if (compare_trees(tree1, tree2)) {
        printf("Tree comparison works with two identical trees\n");
    } else {
        printf("Tree comparison does not work with two identical trees\n");
    }
    destroy_tree(tree1);
    destroy_tree(tree2);

    binary_tree* tree3 = arr_to_tree((int[3]){1, 2, 3}, 3);
    binary_tree* tree4 = arr_to_tree((int[3]){9, 2, 3}, 3);

    if (!compare_trees(tree3, tree4)) {
        printf("Tree comparison works with two different trees\n");
    } else {
        printf("Tree comparison does not work with two different trees\n");
    }
    destroy_tree(tree3);
    destroy_tree(tree4);

    binary_tree* tree5 = arr_to_tree((int[3]){1, 2, 3}, 3);
    binary_tree* tree6 = arr_to_tree((int[3]){3, 2, 1}, 3);

    mirror_tree(tree6);

    if (compare_trees(tree5, tree6)) {
        printf("Tree comparison works with two different trees--\n");
    } else {
        printf("Tree comparison does not work with two different trees--\n");
    }
    destroy_tree(tree5);
    destroy_tree(tree6);

}

void mirror_tree_scenario(int arr[], int size, int expected[], int expected_size, char* title) {
    binary_tree* tree = arr_to_tree(arr, size);
    mirror_tree(tree);
    mirror_tree(tree);
    binary_tree* expected_tree = arr_to_tree(expected, expected_size);


    if (compare_trees(tree, expected_tree)) {
        printf("\033[0;32m"); 
        printf("%s \xE2\x9C\x93 PASS\n", title);
    } else {
        printf("\033[0;31m"); 
        printf("%s FAIL\n", title);
    }
    printf("\033[0m");

    destroy_tree(tree);
    destroy_tree(expected_tree);
}

void mirror_tree_test() {
    mirror_tree_scenario(
        NULL,
        0,
        NULL,
        0,
        "two empty trees"
    );

    mirror_tree_scenario(
        (int[5]){1, 2, 3, 4, 5},
        5,
        (int[5]){1, 2, 3, 4, 5},
        5,
        "Two same trees"
    );
}

//check with null node,
// check on tree with one elem,
// check with node being smallest elem,
// check on varied tree

int sum_predecessor(bt_node* nd) {
    int sum = 0;
    while ((nd = find_predecessor(nd)))
        sum += nd->val;

    return sum;
}

void find_predecessor_test() {
    if (!find_predecessor(NULL)) {
        printf("find predecessor works on null node\n");
    } else {
        printf("find predecessor does not works on null node\n");
    }

    binary_search_tree* tree = arr_to_tree((int[5]){1, 2, 3, 4, 5}, 5);
    int val_1 = sum_predecessor(tree->root);

    if (val_1 == 3) {
        printf("Predecessor check works on root\n");
    } else {
        printf("Predecessor check does not work on root\n");
    }

    int val_2 = sum_predecessor(tree->root->left->left);
    if (!val_2) {
        printf("Predecessor check works on smallest node\n");
    } else {
        printf("Predecessor check does not work on smallest node\n");
    }

    int val_3 = sum_predecessor(tree->root->right);
    if (val_3 == 10) {
        printf("Predecessor check works on largest node\n");
    } else {
        printf("Predecessor check does not work on largest node\n");
        printf("Val: %d\n", val_3);
    }

}

void longest_subseq_comp_test() {
    if (!has_elem_in_front(0, 1)) {
        printf("Elem checking in front works for single elem arr\n");
    } else {
        printf("Elem checking in front does not work for single elem arr\n");
    }

    if (has_elem_in_front(4, 9)) {
        printf("Elem checking in front works for multiple elem arr\n");
    } else {
        printf("Elem checking in front does not work for multiple elem arr\n");
    }

    const int arr1[] = {1, 2, 6, -1};

    if (less_than_next_elem(arr1, 1)) {
        printf("Checking for smaller elem works\n");
    } else {
        printf("Checking for smaller elem does not works\n");
    }

    if (!less_than_next_elem(arr1, 2)) {
        printf("Checking for smaller elem works--\n");
    } else {
        printf("Checking for smaller elem does not works--\n");
    }

    int count1 = count_subseq(arr1, 4, 4);

    if (!count1) {
        printf("Checking for subseq works at invalid pos\n");
    } else {
        printf("Checking for subseq does not work at invalid pos\n");
    }

    int count2 = count_subseq(arr1, 3, 4);

    if (count2 == 1) {
        printf("Checking for subseq works end of arr\n");
    } else {
        printf("Checking for subseq does not work at end of arr\n");
    }

    int count3 = count_subseq(arr1, 2, 4);

    if (count3 == 1) {
        printf("Checking for subseq works at end - 1 of arr\n");
    } else {
        printf("Checking for subseq does not work at end - 1 of arr\n");
    }
    
    int count4 = count_subseq(arr1, 0, 4);

    if (count4 == 3) {
        printf("Checking for subseq works at start of arr\n");
    } else {
        printf("Checking for subseq does not work at start of arr\n");
    }
}

void longest_subseq_test() {
    const int arr1[] = {6,2,5,3,6,8,9,1};
    int count1 = longest_incr_subsequence(arr1, 8);
    if (count1 == 4) {
        printf("Subseq check works for arr of many elems\n");
    } else {
        printf("Subseq check does not work for arr of many elems\n");
    }

    const int arr2[] = {};
    int count2 = longest_incr_subsequence(arr2, 0);
    if (!count2) {
        printf("Subseq check works for empty arr\n");
    } else {
        printf("Subseq check does not work for empty arr\n");
    }

    const int arr3[] = {1, 2, 3, 4, 5};
    int count3 = longest_incr_subsequence(arr3, 5);
    if (count3 == 5) {
        printf("Subseq check works for increasing arr\n");
    } else {
        printf("Subseq check does not work for increasing arr\n");
        printf("Val: %d\n", count3);
    }

    const int arr4[] = {5, 4, 3, 2};
    int count4 = longest_incr_subsequence(arr4, 4);
    if (count4 == 1) {
        printf("Subseq check works for decreasing arr\n");
    } else {
        printf("Subseq check does not work for decreasing arr\n");
        printf("Val: %d\n", count4);
    }

    const int arr5[] = {1, 1, 1};
    int count5 = longest_incr_subsequence(arr5, 3);
    if (count5 == 1) {
        printf("Subseq check works for arr with duplicates\n");
    } else {
        printf("Subseq check does not work for arr with duplicates\n");
}
}

void print_max_comp_test() {
    const int arr1[] = {1, 2, 3, 4, 4};
    int* freq1 = gen_freq(arr1, 5);
    int expected1[] = {0, 1, 1, 1, 2, 0, 0, 0, 0, 0};
    if (compare_arrays(freq1, expected1, 10)) {
        printf("Gen-freq works on arrays with few elems\n");
    } else {
        printf("Gen-freq does not work on arrays with few elems\n");
    }
    free(freq1);

    const int arr2[] = {1, 2, 3, 4, 4, 3, 6, 7, 8, 9, 0, 7, 8};
    int* freq2 = gen_freq(arr2, 13);
    int expected2[] = {1, 1, 1, 2, 2, 0, 1, 2, 2, 1};
    if (compare_arrays(freq2, expected2, 10)) {
        printf("Gen-freq works on arrays with many elems with duplicates\n");
    } else {
        printf("Gen-freq does not work on arrays with duplicates\n");
    }
    free(freq2);

    // just_zeroes
    const int arr3[] = {1, 2, 3, 4, 4};
    int* freq3 = gen_freq(arr3, 5);
    if (!just_zeroes(freq3)) {
        printf("checks for zero works in freq devoid of zero\n");
    } else {
        printf("checks for zero does not work in freq devoid of zero\n");
    }
    free(freq3);

    const int arr4[] = {0, 0, 0, 0, 4};
    int* freq4 = gen_freq(arr4, 5);
    if (!just_zeroes(freq4)) {
        printf("checks for zero works in freq full of zeros\n");
    } else {
        printf("checks for zero does not work in freq full of zero\n");
    }
    free(freq4);

    const int arr5[] = {0, 0, 0, 0, 0};
    int* freq5 = gen_freq(arr5, 5);
    if (just_zeroes(freq5)) {
        printf("checks for zero works in freq with just zeros\n");
    } else {
        printf("checks for zero does not work in freq with just zero\n");
    }
    free(freq5);
}

int main() {
    good_pwd_test();
    find_peak_test();
    sort_mountain_test();
    negative_first_test();
    inorder_traversal_test();
    merge_sort_component_test();
    merge_sort_test();
    quick_sort_test();
    dll_component_test();
    dl_add_test();
    dll_rest_test();
    remove_node_test();
    filter_test();
    mirror_tree_comp_test();
    mirror_tree_test();
    find_predecessor_test();
    longest_subseq_comp_test();
    longest_subseq_test();
    print_max_comp_test();
    return 0;
}
