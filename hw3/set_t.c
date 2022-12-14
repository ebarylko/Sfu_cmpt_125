#include "set_t.h"
#define MAX_SIZE 100

/**
 * @brief Creates an empty set, and returns it
 * 
 * @return set_t* a pointer to an empty set
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
 * @brief takes a set, and returns the number of elements within it
 * 
 * @param A the set being passed
 * @return int the amount of elements in the set
 */
int set_size(set_t* A) {
  return A->size;
}

int index_of(set_t* set, int num) {
    int pos;
    for (pos = 0; pos < set->size && num != set->data[pos]; pos++);
    return pos == set->size ? -1 : pos;
}

/**
 * @brief takes a set and a number N,  and inserts N in the
 * set if it is not present. otherwise, does nothing 
 * 
 * @param A the set
 * @param x the number to insert
 */
void set_insert(set_t* A, int x) {
    int set_size = A->size;
    // checking if set is full
    if (set_size == MAX_SIZE) 
      return;
    // checks over set seeing if element is within
    int pos = index_of(A, x);
    // check if element not in set
    if (pos == -1) {
      A->data[set_size] = x;
      A->size++;
    }
    return;
}

/**
 * @brief takes a set and a number, and removes the number 
 * from the set
 * @param A the set being passed
 * @param x the number to remove from the set
 */
void set_remove(set_t* A, int x) {
  int* set_vals = A->data;
  // gets the position of the element to remove
  int pos = index_of(A, x);
  // swaps value of removed element with last element in set, 
  // avoids bubbling all values to reorder set
  if (pos != -1){
    set_vals[pos] = set_vals[A->size - 1];
    A->size--;
  }
}

/**
 * @brief Takes a set and a number, and returns true if the number
 *  is in the set. Otherwise, returns false
 * 
 * @param A the set to check
 * @param x the number to check for within the set
 * @return true if x is in the set
 * @return false if x is not in the set
 */
bool set_contains(set_t* A, int x) {
    // // seeing whether the element is in the set
    return index_of(A, x) != -1; 
}

/**
 * @brief takes two int pointers, and returns the difference 
 * between them 
 * @param num1 the first pointer
 * @param num2 the second pointer
 * @return int the difference between *num1 and *num2
 */
int int_comp(const void* num1, const void* num2) {
  return *(int*)num1 - *(int*)num2;
}


/**
 * @brief 
 * @param set 
 * @param pos 
 * @param length 
 * @return int 
 */
int occurences(int* set, int pos, int length) {
  int val = set[pos];
  int occurs = 0;
  while (pos < length && val == set[pos]) {
    pos++;
    occurs++;
  }
  return occurs;
}

int remove_duplicates(int set_values[], int set_size) {
  int start = 0;
  int new_pos = 0;
  while (start < set_size) {
    set_values[new_pos] = set_values[start];
    start += occurences(set_values, start, set_size);
    new_pos++;
  }
  return new_pos;

}

/**
 * @brief takes a set and a function, and applies the function
 * to every element of the set. returns the amount of elements
 * remaining in the set after removing duplicates
 * 
 * @param A the set being passed
 * @param f a function that receives an int and returns an int
 * @return int the number of elements remaining in the set
 * after mapping the function over the set and removing duplicates
 */
int set_map(set_t* A, int (*f)(int)) {
  int *set_values = A->data;
  int set_size = A->size;

  // maps function to every element
  for (int pos = 0; pos < set_size; pos++) {
    set_values[pos] = f(set_values[pos]);
  }

  // order set so duplicates are grouped together
  qsort((void *)set_values, set_size, sizeof(int), int_comp);

  A->size = remove_duplicates(set_values, set_size);
  return A->size;
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
