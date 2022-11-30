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

void sort_mountain_test() {
    int arr1[] = {1, 4, 5, 6, 7, 3, 1};
    sort_mountain(arr1, 7, find_peak(arr1, 7));

    int correct[] = {1, 1, 3, 4, 5, 6, 7};
    if (compare_arrays(arr1, correct, 7)) {
        printf("mountain sorting works on arrs with peak in middle\n");
    } else {
        printf("mountain sorting works on arrs with peak in middle\n");
    }

    int arr2[] = {1, 4, 5, 6, 7};
    sort_mountain(arr2, 7, find_peak(arr2, 5));

    int correct2[] = {1, 4, 5, 6, 7};
    if (compare_arrays(arr2, correct2, 5)) {
        printf("mountain sorting works on arrs with peak at the end\n");
    } else {
        printf("mountain sorting works on arrs with peak at the end\n");
    }

    int arr3[] = {9, 8, 7, 0};
    sort_mountain(arr3, 4, find_peak(arr3, 4));

    int correct3[] = {0, 7, 8, 9};
    if (compare_arrays(arr3, correct3, 4)) {
        printf("mountain sorting works on arrs with peak at the beginning\n");
    } else {
        printf("mountain sorting works on arrs with peak at the beginning\n");
    }

}

int main() {
    good_pwd_test();
    find_peak_test();
    sort_mountain_test();
    return 0;
}
