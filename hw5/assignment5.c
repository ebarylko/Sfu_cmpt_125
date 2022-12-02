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
      count += consumed > 0 ? 1 : 0;
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
  if (!str)
    return NULL;

  char **strings = NULL;
  int consumed;
  int pos = 0;
  int new_str_pos = 0;
  int length = strlen(str);

  while ((consumed = find_delim(str, pos, delim, length)) != -1) {
    // if non-delim characters have been consumed
    if (consumed) {
      strings = (char**)realloc(strings, sizeof(char*) * (new_str_pos + 1));
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
char* str_append(const char* str, char c) {
  int length = strlen(str);
  char *new_string = (char *)malloc((length + 2) * sizeof(char));
  strcpy(new_string, str);
  new_string[length] = c;
  new_string[length + 1] = 0;
  return new_string;
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

  char** strings = (char**)malloc(n * sizeof(char*));

  for (int pos = 0; pos < n; pos++) {
    strings[pos] = str_append(str, chars[pos]);
  }

  return strings;
}


/* Question 3 */

bool is_seven_or_nine(char c) {
  return c == '7' || c == '9';
}

const char* PHONE_LETTERS[8] = {"abc", "def",  "ghi", "jkl",
                                "mno", "pqrs", "tuv", "wxyz"};

const char* phone_letters(char c) {
  return PHONE_LETTERS[c - '2'];
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

  int words = 1;

  while (*phone_number) {
    words *= strlen(phone_letters(*phone_number));
    phone_number++;
  }
  return words;
}


typedef struct {
  char** strings;
  int size;
} str_arr;


str_arr empty_str_arr() {
  char** prod = (char**)malloc(sizeof(char*) * 1);
  prod[0] = (char*)malloc(sizeof(char*));
  prod[0][0] = 0;
  return (str_arr) {.strings = prod, .size = 1};
}


str_arr init_str_arr(int size) {

  char** prod = (char**)malloc(sizeof(char*) * size);
  return (str_arr) {.strings = prod, .size = size};
}

void free_str_arr(str_arr curr) {
  for (int i = 0; i < curr.size; i++) {
    free(curr.strings[i]);
  }
  free(curr.strings);
}

void append_str(str_arr target, int pos, char* str) {
  target.strings[pos] = str;
}

/**
 * @brief takes the collection of strings so far, and does
 * the cartesian product between the collection and the letters
 *  corresponding to the digit.
 * 
 * @param curr 
 * @param digits 
 * @return char** 
 */
str_arr cartesian_prod(str_arr curr, const char digit) {
  const char* letters = phone_letters(digit);

  str_arr new = init_str_arr(strlen(letters) * curr.size);

  int new_pos = 0;

  for (int pos = 0; pos < curr.size; pos++) {
    for (int start = 0; start < strlen(letters); start++) {
      char* new_combo = str_append(curr.strings[pos], letters[start]); 
      append_str(new, new_pos++, new_combo);
    }
  }

  free_str_arr(curr);
  return new;
}

str_arr gen_words(str_arr curr, const char* digits) {
  while (*digits) {
    curr = cartesian_prod(curr, *digits);
    digits++;
  }
  return curr;
}

/**
 * @brief takes a phone number, and returns the collection 
 * of all possible words that can be formed from the number
 * 
 * @param phone_number the number given
 * @return char** the collection of all the possible phone numbers
 */
char** get_words(const char* phone_number) {
  if (!phone_number || !strlen(phone_number))
    return NULL;

  str_arr init = empty_str_arr();
  return gen_words(init, phone_number).strings;
}


/* Question 4 */


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

  while (nd->right) 
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

// need a stack that can take nodes of a tree, and pops out
// nodes
// for stack: push, pop, get_size
// to make stack: must make linked list that can take nodes
// LL: must be able to add to head, remove from head, get size
// create/ destroy list

typedef struct new_node{
    BTnode_t* data;
    struct new_node *next;
} new_node;

typedef struct {
    new_node* head;
    new_node* tail;
    int elems;
} linked_list;

typedef new_node* linked_list_iterator;


linked_list* create_list() {
    linked_list* list = (linked_list*)malloc(sizeof(linked_list));
    list->head = NULL;
    list->tail = NULL;
    list->elems = 0;
    return list;
}

new_node* make_node(BTnode_t* val) {
    new_node* new_nd = (new_node*)malloc(sizeof(new_node));
    new_nd->data = val;
    new_nd->next = NULL;
    return new_nd;
}

linked_list_iterator create_iterator(linked_list* list) {
return list->head;
}

bool has_next(linked_list_iterator iter) {
return iter;
}

BTnode_t* get_elem(linked_list_iterator iter) {
return iter->data;
}

linked_list_iterator next(linked_list_iterator iter) {
return iter->next;
}

// get size of list
int get_size(linked_list* list) {
    int size = 0;
    linked_list_iterator iter = create_iterator(list);
    while (has_next(iter)) {
        size++;
        iter = next(iter);
    }
    return size;
}

// adds to head
void add_to_head(linked_list* list, BTnode_t* val) {
    new_node* node = make_node(val);
    node->next = list->head;
    list->head = node;
    if (!(list->elems)) {
        list->tail = node;
    }
    (list->elems)++;
}


// gives all elements after head, returns taken element
BTnode_t* rest(linked_list* list) {
    if (!list->elems)
        return NULL;

    new_node* old_head = list->head;
    BTnode_t* val = old_head->data;
    if (list->elems == 1) {
        list->tail = NULL;
    }

    list->head = list->head->next;
    free(old_head);
    list->elems--;
    return val;
}

void free_list(linked_list* list) {
    while (list->head)
        rest(list);
    free(list);
}

typedef linked_list stack;

stack* create_stack() {
    stack* new_stack = create_list();
    return new_stack;
}

void free_stack(stack* stack) {
    free_list(stack);
}

int stack_size(stack* stack) {
    return get_size(stack);
}

bool is_stack_empty(stack* stack) {
  return !stack_size(stack);
}

void push(stack* stack, BTnode_t* val) {
    add_to_head(stack, val);
}

BTnode_t* pop(stack* stack) {
    return rest(stack);
}    


bool is_right_child(BTnode_t* child, BTnode_t* parent) {
  if (!parent)
    return false;

  return parent->right == child;
}

bool is_left_child(BTnode_t* child, BTnode_t* parent) {
  if (!parent)
    return false;

  return parent->left == child;
}

bool has_right(BTnode_t* nd) {
  return nd->right;
}

void inorder_traverse(BST_t* tree, int arr[], int size) {
  if (!tree)
    return;

  stack* st = create_stack();
  push(st, tree->root);

  BTnode_t* prev = NULL;
  int pos = 0;

  while (!is_stack_empty(st)) {
    BTnode_t* curr = pop(st);

    if (curr->left == NULL) {
      arr[pos++] = curr->value;
      prev = is_right_child(curr, curr->parent) ? curr->parent : curr;
      if (curr->right) {
        push(st, curr->right);
      }

    } else if (is_left_child(prev, curr)) {
      arr[pos++] = curr->value;
      prev = curr;

    } else if (has_right(curr)) {
      push(st, curr->right);
      push(st, curr);
      push(st, curr->left);

    } else {
      push(st, curr);
      push(st, curr->left);
    }
  }
}

int count_nodes(BTnode_t* nd) {
  if (!nd) 
    return 0;

  stack* st = create_stack();
  push(st, nd);
  int count = 0;

  while (!is_stack_empty(st)) {
    BTnode_t* temp = pop(st);

    count++;
    if (temp->left) {
      push(st, temp->left);
    }

    if (temp->right) {
      push(st, temp->right);
    }
  }

  free_stack(st);

  return count;
}

int Tree_size(BST_t* tree) {
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
int get_median(BST_t* tree) {
  if (!tree || !tree->root)
    return 0;

  int tree_size = Tree_size(tree);
  int* tree_vals = (int*)malloc(tree_size * sizeof(int));


  inorder_traverse(tree, tree_vals, tree_size);

  int median_val = tree_vals[tree_size / 2];
  free(tree_vals);
  return median_val;
}
