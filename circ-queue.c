#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

queue_t* new_queue(int size) {
  queue_t* q = malloc(sizeof(queue_t));
  q->array = calloc(size, sizeof(void*));
  q->ptr = q -> array;
  q->size = size;
  return q;
}

void shift_ptr(queue_t* q, int amount) {
  int i = q->ptr - q->array;
  int j = (i + amount) % q->size;
  q->ptr = q->array + j; 
}

void delete_queue(queue_t* q) {
  free(q->array);
  free(q);
}

void enqueue(queue_t* q, void* value) {
  q->ptr[0] = value;
  shift_ptr(q, 1);
}

void* dequeue(queue_t* q) {
  shift_ptr(q, -1);
  return q->ptr[0];
}


void get_extrema(queue_t* q,
                 int (*compare)(void*, void*),
                 void** min_ptr,
                 void** max_ptr) {
  void* min = NULL;
  void* max = NULL;
  for (int i = 0; i < q->size; i++) {
    void* ptr = q->array[i];
    if (!max || compare(ptr, max) > 0) {
      max = ptr;
    }
    if (!min || compare(ptr, min) < 0 ) {
      min = ptr;
    }
  }
  *min_ptr = min;
  *max_ptr = max;
}

void print_queue(queue_t* q, void(*print)(void*)) {
  for (int i = 0; i < q->size; i++) {
    print(q->array[i]);
  }
  printf("\n");
}
