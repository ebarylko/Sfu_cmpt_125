#include "assignment4.h"
/**
 * @brief takes two queues, and moves the contents of the first queue into the second
 * 
 * @param q1 the queue to take elements from
 * @param q2 the queue to fill
 * @return int the amount of elements taken from queue 1
 */
int transfer_queue(queue_str_t* q1, queue_str_t* q2) {
  int size = 0;
  // move contents of q1 to q2
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
 * @return false if they are different
 */
bool queue_equal(queue_str_t* q1, queue_str_t* q2) {
  // check both are same size
  if (queue_size(q1) != queue_size(q2))
    return false;

queue_str_t* q1_copy = queue_create();
queue_str_t* q2_copy = queue_create();
int match = 1;
char* str1;
char* str2;

// checking the strings from both queues
while ( !queue_is_empty(q1) && match) {
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
// return elements in correct order back to queues
transfer_queue(q1_copy, q1);
transfer_queue(q2_copy, q2);

queue_free(q1_copy);
queue_free(q2_copy);
return match;

}
/**
 * @brief takes a queue q1 and a string, and returns the concatenation 
 * of all the strings in q1.
 * 
 * @param q the queue being passed
 * @param str an empty string
 * @return char* the concatenation of all the strings in the queue
 */
char* concat_str_queue(queue_str_t* q, char* str) {
  queue_str_t* copy = queue_create();
  int total_chars = 1;
  char* temp_str;
  while (!queue_is_empty(q)) {
    temp_str = dequeue(q);
    enqueue(copy, temp_str);
    total_chars += strlen(temp_str);
    str = (char *)realloc(str, total_chars * sizeof(char));
    strcat(str, temp_str);
  }
  transfer_queue(copy, q);
  queue_free(copy);

  return str;
}

/**
 * @brief takes a queue, and returns a string containing
 * all the strings in the queues
 * 
 * @param q the queue being passed
 * @return char* the string which contains all the strings
 * in the queue
 */
char* queue_str_to_string(queue_str_t* q) {
  // no strings to concatenate
  if (queue_is_empty(q)) 
    return NULL;

  // queue_str_t* copy_queue = queue_create();

  // initialize string containing all strings of queue
  char* full_str = (char*)malloc(sizeof(char));
  full_str[0] = 0;

  // grab all strings from queue and concatenate them.
  full_str = concat_str_queue(q, full_str);
   // restore original queue
  // transfer_queue(copy_queue, q);
  // queue_free(copy_queue);
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
BTnode_t* find(BTnode_t* root, bool (*pred)(int)) {
  // checking for a valid node
  if (!root)
    return NULL;

  // if node is valid
  if (pred(root->value)) {
    return root;
  }
  // check in children
  BTnode_t* result = find(root->left, pred);
  return result == NULL ? find(root->right, pred) : result;
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
int sum_of_leaves(const BTnode_t* root) {
  // checking if the node is valid
  if (!root)
    return 0;

  const BTnode_t* right = root->right;
  const BTnode_t* left = root->left;

  // seeing if node is a leaf
  if (!right && !left) 
    return root->value;
  

  return sum_of_leaves(left) + sum_of_leaves(right);
}


/* Question 3 */
/**
 * @brief Takes a node of the tree, and returns the node that
 * follows in preorder traversal. if no node follows, returns null
 * 
 * @param node  the node to start searching from
 * @return BTnode_t* the following node in preorder traversal
 */
BTnode_t* next_preorder(BTnode_t* node) {
  if (!node)
    return NULL;

  BTnode_t* left = node->left;
  BTnode_t* right = node->right;

  if (left)
    return left;

  if (right)
    return right;

// go up to node
  while (node && node->parent && (node != node->parent->left || !node->parent->right)) {
    node = node->parent;
  }

  if (!node || !node->parent) 
    return NULL;

  return node->parent->right;
}

