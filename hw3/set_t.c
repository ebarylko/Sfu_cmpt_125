#include "set_t.h"

/**
 * @brief Creates an empty set, and returns it
 * 
 * @return set_t* an empty set
 */
set_t* set_create_empty() {
  // create the set to return
  set_t* aset = (set_t*) malloc(sizeof(set_t));
  // initialize the values of the set
  aset->data = (int*) malloc(100 * sizeof(int));
  aset->size = 0;
  return aset;
}
/**
 * @brief takes a set, and returns the number of elements within
 * 
 * @param A the set being passed
 * @return int the amount of elements in the set
 */
int set_size(set_t* A) {
  return A->size;
}

/**
 * @brief takes a set and a number, and inserts the number in the
 * set if it is not there. otherwise, does nothing
 * 
 * @param A the pointer to the set
 * @param x the number to insert
 */
void set_insert(set_t* A, int x) {
    int set_size = A->size;
    int pos;
    for (pos = 0; pos < set_size && x != A->data[pos]; pos++);
    // element not in set
    if (pos == set_size) {
      A->data[set_size] = x;
      A->size++;
    }
    return;
}
/**
 * @brief takes a set and an element, and removes the
 *  element from set
 * 
 * @param A the set being passed
 * @param x the element to remove within the set
 */
// pass over set looking for element. when found, change 
// set[pos] = set[size -1], replace removed element with last 
// element and shrink size
// remove(1, [1]
void set_remove(set_t* A, int x) {
  int pos;
  for (pos = 0; A->data[pos] != x; pos++);
  A->data[pos] = A->data[A->size - 1];
  A->size--;
}

/**
 * @brief Takes a set and a number, and returns true if element is 
 * in set. otherwise, returns false
 * 
 * @param A the set to check
 * @param x the integer to check for within the set
 * @return true if x is in the set
 * @return false if x is not in the set
 */
bool set_contains(set_t* A, int x) {
    int pos;
    for (pos = 0; pos < A->size && x != A->data[pos]; pos++);
    if (pos == A->size) {
      return false;
    }
    return true;
}


int int_comp(const void* str1, const void* str2) {
  return *(int*)str1 - *(int*)str2;
}


// counts number of occurences of a number in an array
// stop counting when no more matches or we pass array
int occurences(int* set, int pos, int length) {
  int val = set[pos];
  int occurs = 0;
  while (pos < length && val == set[pos]) {
    pos++;
    occurs++;
  }
  return occurs;
}

/**
 * @brief takes a set, and a function, and applies the function
 * to every element of the set. returns the amount of elements
 * in the set after removing duplicates
 * 
 * @param A the set being passed
 * @param f a function that receives an int and returns an int
 * @return int the number of elements remaining in the set
 * after applying the function to all elements and
 * removing duplicates
 */
int set_map(set_t* A, int (*f)(int)) {
  // maps function to every element
    for (int pos = 0; pos < A->size; pos++) {
      A->data[pos] = f(A->data[pos]);
    }
    // order set so duplicates can be checked for
    qsort((void*)A->data, A->size, sizeof(int), int_comp);
    int new_pos = 0;
    int start = 0;
    // grabs unique elements and puts them at the front of the
    // set
    while (start < A->size) {
     A->data[new_pos] = A->data[start]; 
     start += occurences(A->data, start, A->size);
     new_pos++;
    }
    A->size = new_pos;
    return new_pos;
}
/**
 * @brief takes the set, and frees the memory associated with it
 * 
 * @param A the set to free
 */
void set_free(set_t* A) {
 free(A->data);
 free(A);
}
