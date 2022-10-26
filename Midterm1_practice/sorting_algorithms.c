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
    if (left <= end && right >= start) {
        swap(arr, right, start);
        if (left > right) {
            new_pivot = right;
        } else {
        swap(arr, left, right); 
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
    new_student->grades_len = 0;
    new_student->grades = NULL;
    return new_student;
}

// . Write a function that gets a pointer to a student and a course ID, and returns the
//grade of the student for this course. If the array of grades is NULL or the course is not in the
//array of grades, the function returns -1.

int find_grade(student* s, char* courseID) {
    int exists = s->grades_len;
    int student_grade = -1;
    for (int i = 0; i < exists; i++) {
        if (strcmp(s->grades[i].courseID, courseID) == 0)
            student_grade = s->grades[i].grade;
    }
    return student_grade;
}

// new memory = initial memory + memoery for one class
// sizeof(student) + grades_len * sizeof(course_grade)
int add_grade(student* student, course_grade new_grade) {
    int grade = find_grade(student, new_grade.courseID);
    if (grade != -1) {
        return 0;
    }
    int classes = student->grades_len;
    student->grades = (course_grade*)realloc(student->grades,  sizeof(course_grade) * (classes + 1));
    if (student->grades) {
        student->grades_len++;
        student->grades[classes] = new_grade;
        return 1;
    }
    return 0;
}


/**
 *Write a function that gets a pointer to a student and a course grade, and adds
the grade to the student's array of grades.
If student->grades already contains a course with this courseID, the function does nothing.
If student->grades==NULL, you need to create an array of length 1 and add the new grade into
the array.
If student->grades!=NULL, you need to increase the size of the array by one, and add
new_grade into the new entry in the array of grades.
If a grade is added the function returns 1. Otherwise the function returns 0; this can be
because the course is already there or malloc fails. @brief 
**/

course_grade new_class(char* class_name, int grade) {
    course_grade class;
    class.courseID = class_name;
    class.grade = grade;
    return class;
}


void add_course_test() {
    student* paul = create_student(14, "Paul");
    course_grade class = new_class("CRIM140", 97);
    int add_req = add_grade(paul, class);
    if (add_req) {
        printf("success with adding a class\n");
        printf("new class: %s\n", paul->grades[0].courseID);
    } else  {
        printf("faliure adding a class\n");
        return;
    }
    class = new_class("MACM1010", 78);
    add_req = add_grade(paul, class);
    if (add_req) {
        printf("success with adding a class\n");
        printf("new class: %s\n", paul->grades[1].courseID);
    } else  {
        printf("faliure adding a class");
        return;
}
    add_req = add_grade(paul, class);
    if (add_req) {
        printf("success with adding a class\n");
        printf("new class: %s\n", paul->grades[1].courseID);
    } else  {
        printf("faliure adding a class\n");
        return;
}
}


// bool is_sorted(int* A, int n){ 
//     for (int i = 0; i < n - 1; i++) {
//         if (A[i] > A[i + 1])
//             return 0;
//     }
//     return 1;
// }


int compiles() {
char str[10] ={'a','b','c',0,'1','2'};
char* ptr = str;
printf("%s\n", ptr+1);
return 0;
}





/**
 * Write a function that gets two strings and computes the length of their longest
common prefix. For example,
- longest_common_prefix(“abcd”, “ab12”) is 2 - the prefix is “ab”
- longest_common_prefix(“abcd”, “cd”) is 0 - the prefix is empty
- longest_common_prefix(“abcd”, “abcdefg”) is 4 - the prefix is “abcd”@brief 
 * 
 * @return int 
 */
// go until one of the characters do not match, or i exceeds length of one of the 
//string
// outside: n elements checked for strlen, o(1) for assignment
// loop: O(1) * prefix times, worst case prefix is all of string = n
// total, O(N) in total
int longest_common_prefix(const char* str1, const char* str2) {
    int pos = 0;
    int prefix = 0;
    while (str1[pos] != 0 && str2[pos != 0]) {
        prefix++;
        pos++;
    }
    return prefix;
}


/**
//  Write a function that gets a parameter n. It reads n ints from the user (using
scanf), and prints the numbers in the reverse order.
 * 
 */
void read_and_print_reverse(int n) {
    int* reverse_nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Enter a number:");
        scanf("%d", &reverse_nums[n - 1 - i]);
    }
    for(int i = n - 1; i >= 0; i--) {
        printf("%d-", reverse_nums[i]);
    }
    free(reverse_nums);
}

/**
 * Write a function that gets an array of ints of length n, and returns an array of
length n, such that the output[i] is equal to the maximal element in the input subarray [0,..., i].
For example,
- input [1, 4, 3, 8, 2, 9]
- output [1, 4, 4, 8, 8, 9].@brief 
 * 
 * @param ar 
 * @param n 
 * @return int* 
 */

int* max_prefixes(int* ar, int n) {
    if (n == 0)
        return NULL;
    int* new_arr = (int*)malloc(n * sizeof(int));
    if (!new_arr) 
        return NULL;
    int max = ar[0];
    new_arr[0] = max;
    for (int pos = 1; pos < n; pos++) {
        if (ar[pos] > max) {
            max = ar[pos];
        }
        new_arr[pos] = max;
    }
    return new_arr;
}

void max_pref_test() {
    int tst_arr[] = {1, 2, 3, 5, 4, 3, 0};
    int tst_arr2[] = {};
    int tst_arr1[] = {1};
    int* max_arr = max_prefixes(tst_arr, 7);
    int* max_arr2 = max_prefixes(tst_arr1, 1);
    int* max_arr3 = max_prefixes(tst_arr2, 0);

    for (int i = 0; i < 6; i++) {
        printf("%d, ", max_arr[i]);
    }
    printf("\n");
    print_array(max_arr2, 1);
    free(max_arr);
    free(max_arr2);
    free(max_arr2);
}

void reverse_arr_test() {
    read_and_print_reverse(0);
}

void prefix_test() {
    int test_1 = longest_common_prefix("hello", "help");
    int test_2 = longest_common_prefix("hello", "");
    int test_3 = longest_common_prefix("hello", "hello");
    int test_4 = longest_common_prefix("hello", "wernekie");
    printf("\n%d, %d, %d, %d\n", test_1, test_2, test_3, test_4);
}

// func that checks for amount of white space, them shifts characters appropiate amount
// of space. if char not null char, repeats on rest of string
// takes string, where to start in string, and how many characters to shift 
// accounting for previous white spaces
void cut_space(char* str, int pos, int spaces) {
    while (str[pos] == 32) {
        spaces++;
        pos++;
    }
    while (str[pos] != 0 || str[pos] != 32) {
        str[pos - spaces] = str[pos];
        pos++;
    }
    if (str[pos] == 0) {
        str[pos - spaces] = str[pos];
        return;
    } else {
        cut_space(str, pos, spaces);
    }
}



// write a function that removes spaces from a string
// check if there is a white space or null char. if null char, stop.
// "a b x", "abc", 
// else, implement until the end of string
void rem_space(char* str) {
    int pos = 0;
    int len = strlen(str);
    // moves to end of string or first white space
    while  (str[pos] != 32 && str[pos]) 
        pos++;
        //if no white space
    if (pos == len){
        return;
    } else {
        cut_space(str, pos, 0);
    }
}

void mod_string_test() {
    char test[] = "hello";
    char test1[] = "  hello";
    char test2[] = "";
    char test3[] = "a b x";
    // rem_space(test1);
    rem_space(test2);
    // rem_space(test3);
    // printf("%s\n%s\n%s\n%s\n", test, test1, test2, test3);
    // printf("%c---", test[5]);
    printf("%s---", test2);

    // printf("%d", len);
    // printf("%c\n%c\n%c\n%c\n", test[0], test1[0], test2[0], test3[0]);

}


int main() {
    // int arr1[] = {9, 4, 3, 9, 9, 9, -1, -10, 2, 1};
    // int arr[] = {4, 2, 1, -2, 5};
    // quicksort(arr1, 10);
    // quicksort(arr, 5);
    // print_array(arr1, 10);
    // print_array(arr, 5);
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
    student* james = create_student(12, "James");
    course_grade grades[2];
    grades[0].courseID = "ARCH130";
    grades[0].grade = 23;
    grades[1].courseID = "CMPT125";
    grades[1].grade = 88;
    james->grades_len = 2;
    james->grades = grades; 
    int grade = find_grade(james, "ARCH130");
    // printf("Grade is %d\n", grade);

    add_course_test();
//    prefix_test();
//    reverse_arr_test();
//    max_pref_test();
    mod_string_test();
    return 0;
}