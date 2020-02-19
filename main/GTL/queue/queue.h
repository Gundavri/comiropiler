#ifndef _queue_
#define _queue_

typedef struct {
    void* base;
    int logLen;
    int allocLen;
    int elem_size;
} Queue;

void QueueNew(Queue* q, int elem_size);

int QueueIsEmpty(Queue* q);

int QueueSize(Queue* q);

int QueueCapacity(Queue* q);

void* QueueFront(Queue* q);

void* QueueBack(Queue* q);

void QueueEnqueue(Queue* q, void* elem);

void* QueueDequeue(Queue* q);

void QueueDestroy(Queue* q);

#endif