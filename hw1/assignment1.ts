#include <stdio.h>
#include "assignment1.h"

#suite HW 1

#tcase Count even numbers

static const int samples[4][3] = {
    {1, 4, 2},
    {10, 3, 4},
    {7, -8, 8},
    {-11, -11, 0},
};

#test-loop(0, 4) count_even_table
    int start = samples[_i][0];
    int end = samples[_i][1];
    int expected = samples[_i][2];
    ck_assert_int_eq(count_even(start, end), expected);

#test count_even_4
    ck_assert_int_eq(count_even(-11, -11), 0);

