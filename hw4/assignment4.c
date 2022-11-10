#include "assignment4.h"


/* Question 1 */
/**
 * @brief takes a queue, and returns the number of elements inside
 * 
 * @param q the queue being passed
 * @return int the number of elements inside
 */ 
//make a copy of a queue,then move all elements over.
// count how many times you removed from the queue.
// move back contents into original queue. free copy.
// return val
int queue_size(queue_str_t* q) {
  queue_str_t* copy = queue_create();
  int size = 0;
  // move elements over to get the size
  while (!(queue_is_empty(q))) {
    enqueue(copy, dequeue(q));
    size++;
  }
  //return elements back to original queeue
  while (!(queue_is_empty(copy))) 
    enqueue(q, dequeue(copy));

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
// check to see they have the same size. if not, stop.
// stopping condition: both/one queue is empty, or a rejection occured
// create two queues, one for q1(cq1) and one for q2(cq2).
// store dequeues of both queues into a variable, then compare.
// if they match, do nothing. if not, change flag.
// after check, send content of queues back into their origiinal position
// if one queue is empty and the other is not, flag = false
// if both are empty, return the flag
bool queue_equal(queue_str_t* q1, queue_str_t* q2) {
  if (queue_size(q1) != queue_size(q2))
    return false;

}

char* queue_str_to_string(queue_str_t* q) {
  // implement me;
  return NULL;
}


/* Question 2 */

BTnode_t* find(BTnode_t* root, bool (*pred)(int)) {
  // implement me;
  return NULL;
}  


void map(BTnode_t* root, int (*f)(int)) {
  // implement me;
}


int sum_of_leaves(const BTnode_t* root) {
  // implement me;
  return -1;
}


/* Question 3 */

BTnode_t* next_preorder(BTnode_t* node) {
  // implement me;
  return NULL;
}

