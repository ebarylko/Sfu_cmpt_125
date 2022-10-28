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

void set_insert(set_t* A, int x) {
  // implement me
}

void set_remove(set_t* A, int x) {
  // implement me
}

bool set_contains(set_t* A, int x) {
  // implement me
  return -1;
}

int set_map(set_t* A, int (*f)(int)) {
  // implement me
  return -1;
}

void set_free(set_t* A) {
  // implement me
}
