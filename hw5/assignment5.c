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
char** get_tokens(const char* str, char delim) {
  if (!str || !count_tokens(str, delim))
    return NULL;

  char **strings = (char **)malloc(sizeof(char *) * count_tokens(str, delim));
  int consumed;
  int pos = 0;
  int new_str_pos = 0;
  int length = strlen(str);

  while ((consumed = find_delim(str, pos, delim, length)) != -1) {
    // if non-delim characters have been consumed
    if (consumed) {
      strings[new_str_pos++] = fill_str(str, pos, consumed);
    }
    pos = next_non_delim(str, pos + consumed, delim);
}
  return strings;
}


/* Question 2 */
/**
 * @brief takes a string and a character, and returns the 
 * concatenation of the character to the string
 * 
 * @param str the string being passed
 * @param c the character being passed
 * @return char* the concatenation of the string with the 
 * character
 */
char* concat_str(const char* str, char c) {
int length = strlen(str);
char* new_string = (char*)malloc( (length + 2) * sizeof(char));
strcpy(new_string, str);
new_string[length] = c;
new_string[length + 1] = 0;
return new_string;
}

/**
 * @brief takes a string, collection of characters, the number
 * of characters in the collection, and returns the
 * concatenation of the string with every character in the 
 * collection
 * 
 * @param str 
 * @param elems 
 * @param chars 
 * @return char** 
 */
char** map_concat(const char* str, int elems, char* chars) {
char** strings = (char**)malloc(elems * sizeof(char*));

for (int pos = 0; pos < elems; pos++) {
  strings[pos] = concat_str(str, chars[pos]);
}

return strings;
}

/**
 * @brief takes a string, a collection of chars, and the number
 * of chars in the collection N, and returns N amount of
 * strings being the concatenation of the string with each 
 * unique character in the collection
 * 
 * 
 * @param str the string being passed
 * @param n the amount of characters
 * @param chars the collection of characters
 * @return char** the collection of the concatenation of 
 * str with every char in chars
 */
char** append_chars(const char* str, int n, char* chars) {
  if (!str || !n)
    return NULL;

  return map_concat(str, n, chars);
}


/* Question 3 */

bool seven_or_nine(char c) {
  return c - 48 == 7 || c - 48 == 9;
}

int num_of_words(const char* str) {
  int words = 1;
  int pos = 0;

  while (str[pos]) {
    if (seven_or_nine(str[pos])) {
      words *= 4;

  } else {
      words *= 3;
    }

    pos++;
  }
  return words;
}

/**
 * @brief takes a phone number, and returns the amount of 
 * words that can be constructed from the number 
 * 
 * @param phone_number the number being passed
 * @return int the amount of words that can be constructed from 
 * this number
 */
int count_words(const char* phone_number) {
  if (!phone_number || !strlen(phone_number))
    return 0;

  return num_of_words(phone_number);
}

/**
 * @brief takes a phone number, and returns the collection 
 * of all possible words that can be formed from the number
 * 
 * @param phone_number the number given
 * @return char** the collection of all the possible phone numbers
 */
// if !number or !length(number), return null.
// [a b c] [a b c] [a b c]
// grab first collection, concat all possible chars onto first 
// char then repeat with others.
// repeat operation, but with the result of the concatenation of
// first two collections and the third collection
// need memory = to count_words * siizeof(char*)
// need to find a way to change num to char possibilities
// 
char** get_words(const char* phone_number) {
  if (!phone_number || !strlen(phone_number))
    return NULL;

  return NULL;
}


/* Question 4 */

bool right_child(BTnode_t* nd) {
  return nd->right;
}

/**
 * @brief takes a binary search tree, and returns the biggest
 * element within
 * 
 * @param tree the bst being passed
 * @return int the largest element in the tree
 */
int get_max(BST_t* tree) {
  if (!tree || !tree->root) 
    return 0;

  BTnode_t* nd = tree->root;

  while (right_child(nd)) 
    nd = nd->right;

  return nd->value;
}

int inorder_node(BTnode_t* target, int arr[], int size, int index) {
    if (!target) 
        return 0;
    int left = inorder_node(target->left, arr, size, index);
    if (index + left >= size)
        return left;
    arr[index + left] = target->value;
    int right = inorder_node(target->right, arr, size, index + left + 1);
    return left + right + 1;
}

int inorder_traverse(BST_t* tree, int arr[], int size) {
    if (!tree)
        return 0;
    return inorder_node(tree->root, arr, size, 0);
}

int count_nodes(BTnode_t* nd) {
  if (!nd) 
    return 0;
  return 1 + count_nodes(nd->left) + count_nodes(nd->right);
}

int get_size(BST_t* tree) {
  if (!tree || !tree->root)
    return 0;

  return count_nodes(tree->root);
}

/**
 * @brief Takes a binary search tree, and returns the median
 * element of the tree
 * 
 * @param tree the tree being passed
 * @return int the median value of the tree
 */
// if invalid_tree or empty_tree, return 0;
// for bst, the values returned are inorder traversal.
// grab all values of the bst and put them in inorder traversal in
// an array. then grab element of size / 2
int get_median(BST_t* tree) {
  if (!tree || !tree->root)
    return 0;

  int tree_size = get_size(tree);
  int* tree_vals = (int*)malloc(tree_size * sizeof(int));
  inorder_traverse(tree, tree_vals, tree_size);
  return tree_vals[tree_size / 2];
}
