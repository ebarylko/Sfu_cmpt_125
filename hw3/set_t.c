#include "set_t.h"

set_t* set_create_empty() {
  // create the set to return
  set_t* aset = (set_t*) malloc(sizeof(set_t));
  // initialize the values of the set
  aset->data = (int*) malloc(100 * sizeof(int));
  return aset;
}

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

void set_remove(set_t* A, int x) {
  // implement me
}

/**
 * @brief Takes a set and a number, and returns true if element is 
 * in set. otherwise, returns false
 * 
 * @param A 
 * @param x 
 * @return true 
 * @return false 
 */
// go over entire set checking if num is there.
// if it is, short circuit and return, else return false
// if in array, index of num < set_size. if not, index-num 
// == set_size
bool set_contains(set_t* A, int x) {
    int pos;
    for (pos = 0; pos < A->size && x != A->data[pos]; pos++);
    if (pos == A->size) {
      return false;
    }
    return true;
}

int set_map(set_t* A, int (*f)(int)) {
  // implement me
  return -1;
}

void set_free(set_t* A) {
  // implement me
}
