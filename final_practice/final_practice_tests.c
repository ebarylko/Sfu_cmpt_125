#include "final_practice.h"


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

void test() {


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

int main() {
    good_pwd_test();
    find_peak_test();
    sort_mountain_test();
    negative_first_test();
    return 0;
}
