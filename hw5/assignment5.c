#include "assignment5.h"


/* Question 1 */
/**
 * @brief takes a string and a position, and returns the amount
 * of characters consumed to find the delimiter. if null char 
 * is found, returns -1
 * 
 * @param str the string passed
 * @param pos the position to search from
 * @return int the amount of chars consumed to find delim, or 
 * -1 is null char is encountered
 */
int find_delim(const char* str, int pos, char delim) {
  if (!str[pos]) 
    return -1;

  int consumed = 0;
  while ( str[pos] && str[pos++] != delim) {
    consumed++;
  }

  return consumed;
}

int next_non_delim(const char* str, int pos, char delim) {
  while (str[pos] == delim) {
    pos++;
  }
  return pos;
}

/**
 * @brief takes a string, and a delimiter, and returns the number
 * of substrings seperated by the delimiter
 * 
 * @param str the string given
 * @param delim the delimeter passed
 * @return int the number of substrings seperated by the delimiter
 */
// go until the delimiter is found. if the amount of
// chars to reach delim is zero, go until next non-delim char
// if amount of chars consumed is non-zero, increment count.
// stop when null character is reached. -indicates no more delimiters or characters
//
//"HELLO WORLD dot  c" 
int count_tokens(const char* str, char delim) {
 if (!str) 
  return 0;

 int pos = 0;
 int consumed;
 int count = 0;

  // while null char has not been reached
 while ((consumed = find_delim(str, pos, delim)) != -1) {
  // if non-delim characters have been consumed
    count += consumed > 0 ? 1: 0;
    pos = next_non_delim(str, pos + consumed, delim);
 }

 return count;
}

/**
 * @brief takes a string and a delimiter, and returns all the
 * substrings seperated by the delimiter
 * 
 * @param str the string being passed
 * @param delim  the delimiter passed
 * @return char** the array of substrings seperated by the delimiter
 * in the original string
 */
char** get_tokens(const char* str, char delim) {
  if (!str) 
    return NULL;
  // implement me
  return NULL;
}


/* Question 2 */

char** append_chars(const char* str, int n, char* chars) {
  // implement me
  return NULL;
}


/* Question 3 */

int count_words(const char* phone_number) {
  // implement me
  return -1;
}


char** get_words(const char* phone_number) {
  // implement me
  return NULL;
}


/* Question 4 */

int get_max(BST_t* tree) {
  // implement me
  return -1;
}

int get_median(BST_t* tree) {
  // implement me
  return -1;
}
