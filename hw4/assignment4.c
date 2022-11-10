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
//make a copy of a queue,then move all elements over.
// count how many times you removed from the queue.
// move back contents into original queue. free copy.
// return val
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

