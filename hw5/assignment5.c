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
int find_delim(const char* str, int pos, char delim, int length) {
  if (!str[pos]) 
    return -1;

  int consumed = 0;
  while ( str[pos] && str[pos++] != delim) {
    consumed++;
  }

  return consumed == length ? -1 : consumed;
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
 int length = strlen(str);

  // while null char has not been reached
 while ((consumed = find_delim(str, pos, delim, length)) != -1) {
  // if non-delim characters have been consumed
    count += consumed > 0 ? 1: 0;
    pos = next_non_delim(str, pos + consumed, delim);
 }

 return count;
}

/**
 * @brief takes a string, a start position, and end position. 
 * returns a string filled with the characters from start to 
 * end inclusive
 * 
 * @param str the string passed
 * @param start the position of where to start taaking chars
 * @param end where to stop taking chars
 * @return char* a string which is the collection of chars 
 * from start to end - 1
 */

// alloc memory for consumed + 1, +1 for \0
// go from start to start + chars -   1, fill up string with
// chars from the string.
// fill at temp_str[char] = \0
// return temo_str
char* fill_str(const char* str, int start, int chars) {
  char* temp_str = (char*)malloc(sizeof(char) * chars + 1);
  int new_pos = 0;
  for (int i = start; i < start + chars; i++) {
    temp_str[new_pos++] = str[i];
  }
  temp_str[new_pos] = 0;
  return temp_str;
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
// can't modify the string.
// go through the array grabbing all the substrings split by
// the delimiter and put them in an array.
// go through the array, and check if chars have been consumed to
// reach delim. if so, allocate a string with the 
// memory for that amount of consumed chars, and fill string 
// with chars from the indices pos - pos + consumed - 1.
// put the string in array. return array at the end
char** get_tokens(const char* str, char delim) {
  if (!str || !count_tokens(str, delim)) 
    return NULL;

  char** strings = (char**)malloc(sizeof(char*) * count_tokens(str, delim));
  int consumed;
  int pos = 0;
  int new_str_pos = 0;
  int length = strlen(str);

 while ((consumed = find_delim(str, pos, delim, length)) != -1) {
  // if non-delim characters have been consumed
    if (consumed) {
      printf("consumed: %d\n", consumed);
      strings[new_str_pos++] = fill_str(str, pos, consumed);
    }
    pos = next_non_delim(str, pos + consumed, delim);
}
return strings;
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
