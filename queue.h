#include "linked_list.h"

typedef struct Queue {
  list* front;
  list* back;
  int size;
} queue_t;

queue_t* create_queue();
void enqueue(queue_t* queue, double value);
list* dequeue(queue_t* queue);
void print_queue(queue_t* queue);
void delete_queue(queue_t* queue);
int size_queue(queue_t* queue);
