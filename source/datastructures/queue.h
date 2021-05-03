#include "list.h"
struct queue{
    struct node *front;
    struct node *rear;
};

void init_queue(struct queue *q, void *data);
void dealloc_queue(struct queue *q);
void enqueue(struct queue *q, void *data);
void dequeue(struct queue *q, void *data);