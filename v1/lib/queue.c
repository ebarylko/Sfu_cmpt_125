#include <stdio.h>
#include <stdlib.h>

#include "queue.h"


queue_t* queue_create() {
  queue_t* q = (queue_t*) malloc(sizeof(queue_t));
  if (q==NULL)
    return NULL;

  q->list = LL_create();
  if (q->list==NULL)
    return NULL;
  
  return q;
}

void enqueue(queue_t* q, int item) {
    LL_add_to_tail(q->list, item);
}

int dequeue(queue_t* q) {
    return LL_remove_from_head(q->list);
}

int queue_is_empty(queue_t* q) {
    return (q->list->head==NULL);
}

void queue_free(queue_t* q) {
    LL_free(q->list);
    free(q);
}
