#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// invarient: for every i of the iteration all elements to the left of i are sorted
// steps: check smallest element by passing through entire array, swap with current i. repeat withj
// i that follows. ends when i = end b/c smallest element is already found
// set smallest index, check to see if there is something smaller. if it is, change index.
// at end, swap if min index is different from i.
//while j !> than length - 1, continue checking
// if min_index != i, means smaller value was found
void selection_sort(int arr[], int length) {
    int min_index;
    int j;
    int temp;
    for (int start = 0; start < length - 1; start++) {
        min_index = start;
        j = start + 1;
        while (j <= length - 1) {
            if (arr[min_index] > arr[j]) {
                min_index = j;
            }
            j++;
        }
        if (min_index != start) {
            temp = arr[start];
            arr[start] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

// takes a list of unsorted ints, and sorts them.
// checks from 1 to n - 1, seeing if element before it is smaller
// for every i, all elements before i will be smallerr than it.
// if element before i is not bigger than it, means value is in its proper place
// inner loop stoops when we go further then start or find something smaller.
// if element before i is bigger than it, swap elements
// if element gets swapped, must check with element befo
void insertion_sort(int arr[], int length) {
    int comp;
    int temp;
    int end;
    for (int start = 1; start < length; start++) {
        comp = start - 1;
        end = start;
        // end when we pass the beginning or when element is in right place
        while (comp >= 0 && arr[comp] > arr[end]) {
           temp = arr[end];
           arr[end] = arr[comp];
           arr[comp] = temp;
           comp--;
           end--;
        }
    }
}


//implement reverse-string using a loop
// "12345": midpoint = 2, "1234": midpoint = 2, "123456": midpoint = 3, "1234567": midpoint = 3
// go to up til midpoint, and swap all the characters
void reverse_string(char* str) {
    int length = strlen(str);
    int midpoint = length / 2;
    char temp_char;
    // go only up to midpoint so characters to both sides of it get changed
    for (int i = 0; i < midpoint; i++) {
        temp_char = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp_char;
    }
}

//go up to midpoint, but now must check if length is even or odd
// if odd, midpoint is middle character, if even midpoint is first char of last half of string
// if odd, midpoint - dist and midpoint + dist swap
// if even, go to midpoint, if not only up to it
// if even, midpoint - dist and midpoint + dist - 1
void reverse_recur(char* str, int start, int mid, int even) {
    if (start == mid) {
        return;
    }
    char temp = str[start];
    int dist = mid - start;
    int end;
    if (even) {
        end = mid + dist - 1;
    } else {
        end = mid + dist; 
    }
    str[start] = str[end];
    str[end] = temp;
    reverse_recur(str, start + 1, mid, even);
}

void reverse_string_recur(char* str) {
    int midpoint = strlen(str) / 2;
    int even = strlen(str) % 2? 0: 1;
    reverse_recur(str, 0, midpoint, even);
}


typedef struct {
char* courseID; // courseID, e.g. “CMPT125”
int grade; // numerical grade
} course_grade;


typedef struct {
unsigned int ID;
char* name;
course_grade* grades; // array of grades
unsigned int grades_len; // length of the array grades
} student;    

/// Write a function that gets a name and an id of a student and returns a pointer to a
//new student with the given name and ID. The grades of the new student will be initialized to
//NULL, and grades_len set to 0.

student* create_student(int id, char* name) {
    student* new_student = (student*)malloc(sizeof(student));
    new_student->ID = id;
    new_student->name = name;
    new_student->grades = NULL;
    new_student->grades_len = 0;
    return new_student;
}

// . Write a function that gets a pointer to a student and a course ID, and returns the
//grade of the student for this course. If the array of grades is NULL or the course is not in the
//array of grades, the function returns -1.

int find_grade(student* s, char* courseID) {
    course_grade* exists = s->grades;
    int grade = -1;
    if (exists) {
        int class = s->grades->courseID == courseID;
        grade = class? s->grades->grade: -1;
    }
    return grade;
}

void swap(int arr[], int start, int end) {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
}

/**
 * @brief takes an array, a beginning and an end. picks the midpoint based on start and end, and sorts
 * array according to pivot. after, swaps pivot with low, and repeat.
 * 
 * @param arr 
 * @param start 
 * @param end 
 */

void sort_rec(int arr[], int start, int end) {
    printf("--Start: %d , end: %d\n", start, end);
    for (int i = start; i <= end; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    if (start == end)
        return;
    int pivot = arr[start];
    int new_pivot = start + 1;
    int left = start + 1;
    int right = end;
    while (left <= end && arr[left] <= pivot)
        left++;
    while (right >= start && arr[right] >= pivot)
        right--;
    printf("Left: %d, Right: %d\n", left, right);
    if (left <= end && right >= start) {
        if (left > right) {
            swap(arr, right, start);
            new_pivot = right;
        } else {
        swap(arr, left, right); 
        swap(arr, left, start);
        }
    } else if (right >= start) {
        swap(arr, start, right);
        new_pivot = right;
    } else if (left <= end) {
        new_pivot = left;
    }
    sort_rec(arr, start, new_pivot - 1);
    sort_rec(arr, new_pivot, end);

}

// pivot is chosen from middle, 
// repeat on start to pivot, and pivot + 1 to end
// check from pivot + 1 and from end. if low > pivot and high < pivot, swap low and high.
// at end, swap low with pivot. repeat
// low goes until it is higher than pivot, high goes util it is smaller than pivot.
void quicksort(int arr[], int length) {
    sort_rec(arr, 0, length - 1);
}

void print_array(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d,", arr[i]);
    }
    printf("\n");
}


int main() {
    int arr1[] = {9, 4, 3, 9, 9, 9, -1, -10, 2, 1};
    int arr[] = {4, 2, 1, -2, 5};
    // quicksort(arr1, 10);
    quicksort(arr, 5);
    // print_array(arr1, 10);
    print_array(arr, 5);


    // // selection_sort(arr, 7);
    // insertion_sort(arr, 5);
    // for (int i = 0; i < 5; i++) {
    //     printf("Element %d of array is %d\n", i, arr[i]);
    // }
    // char str_ex[] = "hello";
    // char str_ex1[] = "racecar";
    // char str_ex2[] = "  234 456  ";
    // reverse_string_recur(str_ex);
    // reverse_string_recur(str_ex1);
    // reverse_string_recur(str_ex2);
    // printf("reversed strings: \n str1: %s\n str2: %s\n str3: %s\n", str_ex, str_ex1, str_ex2);
    // student* james = create_student(12, "James");
    // course_grade info;
    // info.courseID = "CMPT125";
    // info.grade = 88;
    // james->grades = &info; 
    // int grade = find_grade(james, "CMPT125");
    // printf("Grade is %d\n", grade);
    // printf("ID: %d, name: %s, grades_len: %d", james->ID, james->name, james->grades_len);
    return 0;
}