#include <stdio.h>
#include "assignment1.h"

#suite HW 1

#tcase Count even numbers

#test count_even_1
    ck_assert_int_eq(count_even(1, 4), 3);

#test count_even_2
    ck_assert_int_eq(count_even(10, 3), 4);
