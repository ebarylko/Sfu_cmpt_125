#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>


#include "final_practice.h"

bool is_lowercase(char c) {
    return c >= 'a' && c <= 'z';
}

bool is_uppercase(char c) {
    return c >= 'A' && c <= 'Z';
}

bool is_symbol(char c) {
    return c == '!' ||  c == '#' || c == '@';
}

bool valid_pwd(const char* str) {
    int digits = 0;
    int lower_case = 0;
    int upper_case = 0;
    int symbols = 0;

    while (*str) {
        if (isdigit(*str))
            digits++;

        if (is_lowercase(*str))
            lower_case++;

        if (is_uppercase(*str))
            upper_case++;

        if (is_symbol(*str))
            symbols++;

        str++;
    }

    return digits && lower_case && upper_case && symbols;
}

bool is_good_password(const char* str) {
    if (!str || strlen(str) < 8 ) 
        return false;

    return valid_pwd(str);
}

// if pos == length, I can't check to the right. must check to the left and see
// that left value is smaller than val at pos
// if pos == start, same issue as above but cant check to the right
// if pos - 1 > pos, return true. else, false
// must check if val to the left bigger than val at pos.
// if pos == start, return false. else, return the check
bool right_of_mountain(const int* arr, int pos, int start, int end) {
    if (pos == start)
        return false;

    return arr[pos] < arr[pos - 1];
}

bool left_of_mountain(const int* arr, int pos, int start, int end) {
    if (pos == end)
        return false;

    return arr[pos] < arr[pos + 1];
}

//  [1, 4, 5, 6, 7, 3, 1]
// check if midpoint is right or left of mountain,
// if left of mountain go from mid + 1 to end
// if right of mountain go from start to mid - 1
// if not left or right of mountain, point is the mountain. return val
int peak(const int* arr, int start, int end) {
    int mid = (end - start + 1) / 2;

    if (right_of_mountain(arr, start + mid, start, end)) 
        return peak(arr, start, start + mid - 1);
    
    if (left_of_mountain(arr, start + mid, start, end)) 
        return peak(arr, start + mid + 1, end);

    return start + mid;
}

// [1 3 5 2 0]
// [10, 4]
// [-1 0 3 4 5 8]
// return 0 if !A or n = 1
// if at index 0 val is greater than right found peak
// if at index n - 1 val greater than left found peak
// 
int find_peak(const int* A, int n)  {
    if (!A || n == 1)
      return 0;

    return peak(A, 0, n - 1);
}


//Write a function that gets a mountain array of length n, and the index k
//representing the peak, and sorts the array in the increasing order in O(n) time.
// if !A, return.


void swap(int* arr, int pos1, int pos2) {
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

void reverse_mountain(int* arr, int length) {
    int mid = length / 2;
    int end = length - 1;
    for (int pos = 0; pos < mid; pos++) {
        swap(arr, pos, end - pos);
    }
}

void overwrite_arr(int* arr1, int* arr2, int size) {
    for (int pos = 0; pos < size; pos++) {
        arr1[pos] = arr2[pos];
    }
}

void order_mountain(int* arr, int length) {
    int* new_arr = (int*)malloc(sizeof(int) * length);

    int start = 0;
    int end = length - 1;
    int new_pos = 0;

    while (start <= end) {
        int val = arr[start] > arr[end] ? arr[end--] : arr[start++];
        new_arr[new_pos++] = val;
    }

    overwrite_arr(arr, new_arr, length);
    free(new_arr);
}

void sort_mountain(int* A, int n, int k) {
    if (!A || n <= 1 || k == n - 1)
        return;

    order_mountain(A, n);
}

node* create_node(int val) {
    node* nd = (node*)malloc(sizeof(node));
    nd->val = val;
    nd->next = NULL;
    return nd;
}

linked_list* create_list() {
    linked_list* list = (linked_list*)malloc(sizeof(linked_list));
    list->head = NULL;
    list->tail = NULL;
    list->elems = 0;
    return list;
}


bool is_empty_list(linked_list* list) {
    return list->elems == 0;
}

void add_to_tail(linked_list* list, int val) {
    if (!list) 
        return;

    node* nd = create_node(val);

    if (is_empty_list(list)) {
        list->head = nd;
    } else {
      list->tail->next = nd;
    }

    list->tail = nd;
    list->elems++;
}

int rest(linked_list* list) {
    if (!list || is_empty_list(list)) 
        return 0;

    node* old_head = list->head;
    int val = old_head->val;
    list->head = old_head->next;
    free(old_head);
    list->elems--;

    if (is_empty_list(list)) {
        list->tail = NULL;
    }

    return val;
}

void free_list(linked_list* list) {
    while (list->head)
        rest(list);
    free(list);
}

bool pos_before_neg(node* nd) {
    return nd->val >= 0 && nd->next->val < 0;
}

bool is_ordered_list(linked_list* list) {
    if (!list || is_empty_list(list))
      return true;

    node* nd = list->head;
    while (nd->next && !pos_before_neg(nd)) {
        nd = nd->next;
    }
    
    return !nd->next ;//? false : true;
}

binary_tree* create_tree_from_node(bt_node* root) {
    binary_tree* tree = (binary_tree*)malloc(sizeof(binary_tree));
    tree->root = root;
    return tree;
}

bt_node* create_bt_node(int val) {
    bt_node* nd = (bt_node*)malloc(sizeof(bt_node));
    nd->val = val;
    nd->parent = NULL;
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

binary_tree* create_tree(int val) {
    bt_node* root = create_bt_node(val);
    return create_tree_from_node(root);
}

void destroy_subtree(bt_node* target) {
    if (!target) 
        return;
    destroy_subtree(target->left);
    destroy_subtree(target->right);
    free(target);
}

void destroy_tree(binary_tree* tree) {
    if (!tree) 
        return;
    destroy_subtree(tree->root);
    free(tree);
}

bt_node* inorder_from_array(int *arr, int start, int end, int size) {
    // check that is valid, if not return
    if (start > end || start < 0 || end >= size)
    {
        return NULL;
    }

    int root = (end - start + 1) / 2;
    // I know root index is the root
    bt_node *root_node = create_bt_node(arr[start + root]);
// {2, 8, 9, 0, -1, -2}
    root_node->left = inorder_from_array(arr, start, start + root - 1, size);

    if (root_node->left)
        root_node->left->parent = root_node;

    root_node->right = inorder_from_array(arr, start + root + 1, end, size);

    if (root_node->right)
        root_node->right->parent = root_node;


    return root_node;
}

binary_tree* arr_to_tree(int* arr, int length) {
    if (!arr) 
        return NULL;

    bt_node *root = inorder_from_array(arr, 0, length - 1, length);
    return create_tree_from_node(root);
}

bool has_right_child(bt_node* nd) {
    return nd->right;
}

bool is_left_child(bt_node* nd) {
    return nd->parent->left == nd;
}

bt_node* smallest_right_node(bt_node* nd) {
    assert(nd);
    while (nd->left) {
        nd = nd->left;
    }

    return nd;
}

bool has_parent(bt_node* nd) {
    return nd->parent;
}

bt_node* next_inorder(bt_node* nd) {
    if (!nd)
        return NULL;

    if (has_right_child(nd)) {
        return smallest_right_node(nd->right);
    }

    while (has_parent(nd) && !is_left_child(nd)) {
      nd = nd->parent;
    }

    return nd->parent;
}

// merge_sort

void print_arr(int arr[], int size) {
    for (int pos = 0; pos < size; pos++) {
        printf("%d, ", arr[pos]);
    }
    printf("\n");
}

bool invalid_arr(int arr[]) {
    return !arr;
}

bool is_invalid_interval(int start, int end) {
    return start > end;
}

bool two_elems(int start, int end) {
    return end - start == 1;
}

void order_pair(int arr[], int start, int end) {
    if (arr[start] > arr[end]) 
        swap(arr, start, end);
}

void copy_elems_to_arr(int target_arr[], int start_pos, int source_arr[], int start, int end) {
    while (start <= end) {
        target_arr[start_pos++] = source_arr[start++];
    }
}



int* order_arr_interval(int unsorted[], int start, int end, int pivot) {
    int elems = end - start + 1;
    int* sorted_arr = (int*)malloc(elems * sizeof(int));

    int temp_end = pivot + 1;

    int pos = 0;
    while (start <= pivot || temp_end <= end) {
      if (start > pivot) {
        sorted_arr[pos++] = unsorted[temp_end++];

      } else if (temp_end > end) {
        sorted_arr[pos++] = unsorted[start++];

      } else {
        sorted_arr[pos++] = unsorted[start] > unsorted[temp_end]
                                ? unsorted[temp_end++]
                                : unsorted[start++];
      }
    }


    return sorted_arr;
}

void overwrite_arr_interval(int target[], int sorted[], int start, int elems) {
    for (int pos = 0; pos < elems; pos++) {
        target[start + pos] = sorted[pos];
    }
}

void merge(int arr[], int start, int end, int pivot) {

    int* sorted_arr = order_arr_interval(arr, start, end, pivot);
    overwrite_arr_interval(arr, sorted_arr, start, end - start + 1);
    free(sorted_arr);
}


void order(int arr[], int start, int end) {
    if (is_invalid_interval(start, end) || start == end)
        return;


    if (two_elems(start, end)) {
        order_pair(arr, start, end);
        return;
    }

    int mid = (end - start + 1) / 2;

    order(arr, start, start + mid);
    order(arr, start + mid + 1, end);
    merge(arr, start, end, start + mid);
}

void merge_sort(int arr[], int size) {
    if (invalid_arr(arr) || size == 1)   
        return;

    order(arr, 0, size - 1);

}

// quicksort


bool at_pivot(int pos, int pivot) {
    return pos == pivot;
}

void quick_sort_order(int arr[], int start, int end) {
    if (is_invalid_interval(start, end) || start == end)
        return;

    int pivot_val = arr[end];
    int j = start;

    for ( int curr_pos = start; !at_pivot(curr_pos, end); curr_pos++) {
        if (arr[curr_pos] <= pivot_val) {
            swap(arr, curr_pos, j++);
        }
    }
    swap(arr, j, end);

    quick_sort_order(arr, start, j - 1);
    quick_sort_order(arr, j + 1, end);
}

void quick_sort(int arr[], int size) {
    if (invalid_arr(arr) || size == 1)   
        return;

    quick_sort_order(arr, 0, size - 1);
}

// doubly linked list
// for node: create node,destroy node
// create list, destroy list, add to head, remove from head

dl_node* create_dl_node(int val) {
    dl_node* nd = (dl_node*)malloc(sizeof(dl_node));
    nd->next = NULL;
    nd->previous = NULL;
    nd->val = val;
    return nd;
}

doubly_linked_list* create_dll() {
    doubly_linked_list* list = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
    list->elems = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void add_to_head(doubly_linked_list* list, int val) {
    dl_node* nd = create_dl_node(val);
    nd->next = list->head;
    list->head = nd;
    list->elems++;

    if (list->elems != 1) {
        nd->next->previous = nd;
    } else {
        list->tail = nd;
    }
}

bool empty_list(doubly_linked_list* list) {
    return !list->elems;
}

int rest_dll(doubly_linked_list* list) {
    if (!list || empty_list(list))
        return -1;

    dl_node* old_head = list->head;
    list->head = old_head->next;
    int val = old_head->val;
    free(old_head);

    list->elems--;
    if (empty_list(list)) {
        list->tail = NULL;
    } else {
        list->head->previous = NULL;
    }

    return val;
}

// one elem: make copy of tail, store val, make tail point to previous,
// make head point to null, reduce elements, free tail, return val
// elems+: make copy, store val, make tail point to previous, make previous
// point to null
int remove_from_tail(doubly_linked_list* list) {
    if (!list || empty_list(list))
        return -1;

    dl_node* old_tail = list->tail;
    list->tail = old_tail->previous;
    int val = old_tail->val;
    free(old_tail);

    list->elems--;
    if (empty_list(list)) {
        list->head = NULL;
    } else {
        list->tail->next = NULL;
    }

    return val;
}
// if !list || ! target, return.

bool is_head(dl_node* nd) {
    return !nd->previous;
}

bool is_tail(dl_node* nd) {
    return !nd->next;
}

// connect previous with next, and vice versa, free node
void connect_nodes(dl_node* nd) {
    nd->next->previous = nd->previous;
    nd->previous->next = nd->next;
    free(nd);
}

void remove_node(doubly_linked_list* list, dl_node* target) {
    if (!list || !target) 
        return;

    if (is_head(target)) {
        rest_dll(list);
        return;
    }

    if (is_tail(target)) {
        remove_from_tail(list);
        return;
    }

    connect_nodes(target);
}

// go through every elem in the list, if it does not comply with pred
// remove it
// if !list, return.
// if usinf the current node, when memory gets freed cannot 
// get to next node
// make a copy of next node so that I can assign 
// curr node to next node
void filter(doubly_linked_list* list, bool (*func) (int)) {
    if (!list) 
        return;

    dl_node* nd = list->head;
    while (nd) {
      dl_node* next_nd = nd->next;
      if (!func(nd->val)) {
        remove_node(list, nd);
      }
      nd = next_nd;
    }
}

// reverse

void mirror_nodes(bt_node* nd) {
    if (!nd)
        return;

    bt_node* cpy = nd->left;
    nd->left = nd->right;
    nd->right = cpy;
    mirror_nodes(nd->left);
    mirror_nodes(nd->right);
}

// if !tree, return.
// for every node, assign it the reverse of what iit has
// it null, return
void mirror_tree(binary_tree* tree) {
    if (!tree)
        return;

    mirror_nodes(tree->root);
}

// predescessor

// looking for next smallest element.
// if I have a left chhild, return that.
// if I have no left child, go up until I am the right child.
// in this case, parent will be smaller. 
// if there is no parent, there is no presecessor
// if !nd, return null

bool invalid_node(bt_node* nd) {
    return !nd;
}

bool has_left_child(bt_node* nd) {
    return nd->left;
}
// should check to make sure right child is not duplicate
bool is_right_child(bt_node* nd) {
    return nd->parent->right == nd;
}

bt_node* largest_left_node(bt_node* nd) {
    while (has_right_child(nd)) 
        nd = nd->right;

    return nd;
}

bt_node* find_predecessor(bt_node* nd) {
    if (invalid_node(nd))
        return NULL;
    
    if (has_left_child(nd)) 
        return largest_left_node(nd->left);

    while (has_parent(nd) && !is_right_child(nd))
        nd = nd->parent;

    return nd->parent;
}

// I know that I will always have length of 1,
// so length < 1 means I have reached the end.
// while pos + 1 > pos, increment count
// count subseq: ar, pos: return length of subseq.
// if !pos < size, return 0;

bool has_elem_in_front(int pos, int end) {
    return pos != end - 1;
}

bool less_than_next_elem(const int* arr, int pos) {
    return arr[pos] < arr[pos + 1];
}

int count_subseq(const int* arr, int pos, int end) {
    if (pos >= end)
        return 0;

    int count = 1;
    while (has_elem_in_front(pos, end) && less_than_next_elem(arr, pos)) {
      pos++;
      count++;
    }
    return count;
}

int longest_subseq(const int* arr, int size) {
    int max = 0;
    int pos = 0;
    int length;
    while ((length = count_subseq(arr, pos, size)) != 0) {
        max = length > max ? length : max;
        pos += length;
    }
    return max;
}

int longest_incr_subsequence(const int* arr, int size) {
    if (!arr || !size)
        return 0;

    return longest_subseq(arr, size);
}

// print_max_num


void initialize_freq(int* freq) {
    for (int pos = 0; pos < 10; pos++) {
        freq[pos] = 0;
    }
}

int* gen_freq(const int* arr, int size) {
    int* freq = (int*)malloc(10 * sizeof(int));
    initialize_freq(freq);
    for (int pos = 0; pos < size; pos++) {
        freq[arr[pos]]++;
    }
    return freq;
}

// return false if there are more than just zeroes
// true otherwise

// check over arr. it it has non-zero digit, return true
bool has_nonzero_digits(int* freq) {
    for (int pos = 1; pos < 10; pos++) {
        if (freq[pos])
            return true;
    }
    return false;
}

bool just_zeroes(int* freq, int size) {
    return freq[0] == size;//&& !has_nonzero_digits(freq);
}

void repeat_insertion(char* str, int pos, int num, int repetitions) {
    for (int start = pos; start < pos + repetitions; start++) {
        str[start] = 48 + num;
    }
}

char* fill_string(int* freq, int size) {
    char* string = (char*)malloc((size + 1) * sizeof(char));
    int insertion_pos = 0;
    for (int pos = 9; pos > -1; pos--) {
        repeat_insertion(string, insertion_pos, pos, freq[pos]);
        insertion_pos += freq[pos];
    }
    string[size] = 0;
    return string;
}

char* gen_largest_string(int* freq, int size) {
    char* largest_string;

    if (just_zeroes(freq, size)) {
        largest_string = (char*)malloc(2 * sizeof(char));
        largest_string[0] = '0';
        largest_string[1] = 0;
        // return largest_string;
    } else {
      largest_string = fill_string(freq, size);
    }

    return largest_string;
}

char* print_max_number(const int* arr, int size) {
    if (!arr || !size)
        return NULL;

    int* freq = gen_freq(arr, size);
    char* largest_num = gen_largest_string(freq, size);
    free(freq);
    return largest_num;
}