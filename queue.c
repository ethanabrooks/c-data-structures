#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

queue_t* create_queue() {
  queue_t* new_queue = calloc(1, sizeof(queue_t));
  if (!new_queue) {
    perror("calloc failed");
    exit(-1);
  }
  new_queue->size = 0;
  new_queue->front = NULL;
  new_queue->back = NULL;
  return new_queue;
}

void enqueue(queue_t* queue, double value) {
  queue->size++;
  add_to_top(&(queue->back), value);
  if (queue->size == 1) {
    queue->front = queue->back;
  }
}

list* dequeue(queue_t* queue) {
  queue->size--;
  list* front = queue->front;
  queue->front = front->prev; // update queue->front
  return pop_node(&(queue->back), front); // pop old queue->front
}

void print_queue(queue_t* queue){
  print_list(queue->back);
}

void delete_queue(queue_t* queue){
  delete_list(queue->back);
  free(queue);
}
