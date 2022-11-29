#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


#include "final_practice.h"

// create counters for each trait required. when predicate for trait matches, increment
// at end of string return all the counters
bool check_pwd(const char* str) {
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
    }

    return digits && lower_case && upper_case && symbols;
}

//its length is at least 8
//- contains at least one digit
//- contains at least one lower case letter
//- contains at least one upper case letter
//- contains at least one of these three symbols: !@#
// if length not >= 8, return false.
// iterate through array checking if string contains all required traits.
// when reaching the end return the counters
bool is_good_password(const char* str) {
    if (!str) 
        return false;

    return strlen(str) < 8 ? false : check_pwd(str);
}
