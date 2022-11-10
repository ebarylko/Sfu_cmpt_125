#ifndef QUEUE_H
#define QUEUE_H

#include "LL.h"

typedef struct {
  LL_t* list;
} queue_t; 


// creates a new queue
queue_t* queue_create();

// enqueue a given item to the queue
void enqueue(queue_t* q, int item);

// dequeue from the queue
// Pre condition: queue is not empty
int dequeue(queue_t* q);

// returns 1 if the queue is empty, and returns 0 otherwise
int queue_is_empty(queue_t* q);

// free queue
void queue_free(queue_t* q);


#endif