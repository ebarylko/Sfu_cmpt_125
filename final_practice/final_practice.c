#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


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
// if n ==1 or n < 0, return.
// if k = n - 1, return.
// if k = 0, reverse array
// create a new array of size n.
// go from both sides of the mountain, checking if left > right.
// if so put right val in new_arr, increment pos for right.
// stop when left > right

// go up to midpoint, and swap elements on both sides of the array

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

// create new array, and go from each side of the old array.
// if left > right, put right in new arr. if not put left in new arr.
// update position and counter for new_arr. 
void order_mountain(int* arr, int length) {
    int* new_arr = (int*)malloc(sizeof(int) * length);

    int start = 0;
    int end = length - 1;
    int new_pos = 0;

    while (start < end) {
        int val = arr[start] > arr[end] ? arr[end--] : arr[start++];
        new_arr[new_pos++] = val;
    }

    arr = new_arr;
}

void sort_mountain(int* A, int n, int k) {
    if (!A || n <= 1 || k == n - 1)
        return;

    if (k == 0) {
        reverse_mountain(A, n);
        return;
    }

    order_mountain(A, n);
}