#include "assignment4.h"

int transfer_queue(queue_str_t* q1, queue_str_t* q2) {
  int size = 0;
  while (!(queue_is_empty(q1))) {
    enqueue(q2, dequeue(q1));
    size++;
  }
  return size;
}

/* Question 1 */
/**
 * @brief takes a queue, and returns the number of elements inside
 * 
 * @param q the queue being passed
 * @return int the number of elements inside
 */ 
int queue_size(queue_str_t* q) {
  queue_str_t* copy = queue_create();
  //get size of queue
  int size = transfer_queue(q, copy);
  //return queue back
  transfer_queue(copy, q);

  queue_free(copy);
  return size;
}



/**
 * @brief takes two queues, and returns true if both have the 
 * same strings in the same order. false otherwise
 * 
 * @param q1 the first queue
 * @param q2 the second queue
 * @return true if both queues are equal
 * @return false if thhey are different
 */
bool queue_equal(queue_str_t* q1, queue_str_t* q2) {
  if (queue_size(q1) != queue_size(q2))
    return false;

queue_str_t* q1_copy = queue_create();
queue_str_t* q2_copy = queue_create();
int match = 1;
char* str1;
char* str2;

// checking the strings from both queues
while ( !(queue_is_empty(q1)) && !(queue_is_empty(q2)) && match) {
// storing strings
str1 = dequeue(q1);
str2 = dequeue(q2);

enqueue(q1_copy, str1);
enqueue(q2_copy, str2);

// if strings don't match
if (strcmp(str1, str2)) 
  match = 0;
}
// if not equal before end, transfer remaining elements
transfer_queue(q1, q1_copy);
transfer_queue(q2, q2_copy);
// return elements in coorrect order back to queues
transfer_queue(q1_copy, q1);
transfer_queue(q2_copy, q2);

queue_free(q1_copy);
queue_free(q2_copy);
return match;

}
/**
 * @brief takes a queue, and returns a string containing
 * all the strings in the queues
 * 
 * @param q the queue being passed
 * @return char* the string which contains all the strings
 * in the queue
 */ //use strcat
// go over every string in the queue, then realloc more memory
// to accomodate the string(include null char)
// copy string over, repeat until
// queue is empty. need soome way to keep count of amount of
// memory used for current consumption before usage
//add more memory for null character
// make a new queue to store strings
// amount of memory = strlen(str) + 1 for null
// before repetition, allocate for first string plus one,
// make additional queue to store strings.
// transfer at end
char* queue_str_to_string(queue_str_t* q) {
  queue_str_t* copy_queue = queue_create();
  char* str;

  // no strings to concatenate
  if (queue_is_empty(q)) 
    return NULL;

  str = dequeue(q);
  enqueue(copy_queue, str);
  // keeping track of how much memory to allocate for later
  int total_chars = strlen(str) + 1;

  // add additional piece of memory so null char is accounted for
  char* full_str = (char*)malloc(total_chars * sizeof(char));
  strcat(full_str, str);


  // grab all strings from queue and concatenate them.
  while (!(queue_is_empty(q))) {
  str = dequeue(q);
  enqueue(copy_queue, str);
  total_chars += strlen(str);
  full_str = (char*)realloc(full_str, total_chars * sizeof(char));
  strcat(full_str, str);
  }
  // // restore original queue
  transfer_queue(copy_queue, q);
  queue_free(copy_queue);
  return full_str;
}


/* Question 2 */

/**
 * @brief takes the root of a tree, and a predicate that takes 
 * a number. returns the first node whose data passes the predicate,
 * else returns null.
 * 
 * @param root the root of the tree
 * @param pred the predicate given
 * @return BTnode_t* the first node of the tree which passes 
 * the predicate, otherwise null.
 */
// check first if root is valid. if not, return null.
// else, go through tree looking for node which passes pred.
// if found, return node. else, return null
// stop when all nodes have been checked.
// else, recur on follwing nodes
BTnode_t* find(BTnode_t* root, bool (*pred)(int)) {
  // checking for a valid node
  if (!root)
    return NULL;

  printf("\n%d", root->value);
  // if node is valid
  if (pred(root->value)) {
    printf("Found a valid value");
    return root;
  }
  // check in children
  return (find(root->left, pred) || find(root->right, pred));
}  

/**
 * @brief takes a tree, and a function which takes a number.
 * applies the function to every node in the tree
 * 
 * @param root the tree being passed
 * @param f a function which takes a number and returns a number
 */
// stop when node is null. else, apply function on the value.
// repeat on the children
void map(BTnode_t* root, int (*f)(int)) {
 // checks for valid node
 if (!root) 
  return;
 
  // applies function, then repeats on children
  root->value = f(root->value);
  map(root->left, f);
  map(root->right, f);
}

/**
 * @brief takes a tree, and returns the sum of all the leaves
 * 
 * @param root the tree given
 * @return int the sum of all the leaves
 */
// only add the value of node when it has no children.
// stop when reaching there. else, continue until that point
// is reached.
// if passed a null pointer, return 0
int sum_of_leaves(const BTnode_t* root) {
  // checking if the node is valid
  if (!root)
    return 0;

  const BTnode_t* right = root->right;
  const BTnode_t* left = root->left;

  // seeing if node is a leaf
  if (!right && !left) {
    return root->value;
  }

  return sum_of_leaves(left) + sum_of_leaves(right);
}


/* Question 3 */

BTnode_t* next_preorder(BTnode_t* node) {
  // implement me;
  return NULL;
}

