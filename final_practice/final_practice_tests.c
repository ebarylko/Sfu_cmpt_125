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

int main() {
    good_pwd_test();
    find_peak_test();
    return 0;
}
