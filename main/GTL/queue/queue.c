#include "queue.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>



void QueueNew(Queue* q, int elem_size){
    q->logLen = 0;
    q->allocLen = 1;
    q->elem_size = elem_size;
    q->base = malloc(q->elem_size);
    assert(q->base != NULL);
}


int QueueIsEmpty(Queue* q){
    return q->logLen == 0;
}

int QueueSize(Queue* q){
    return q->logLen;
}

int QueueCapacity(Queue* q){
    return q->allocLen;
}

void* QueueFront(Queue* q){
    return q->logLen == 0 ? NULL : q->base;
}

void* QueueBack(Queue* q){
    return q->logLen == 0 ? NULL : (char*)q->base + q->elem_size * (q->logLen - 1);
}

void QueueEnqueue(Queue* q, void* elem){
    if(q->logLen >= q->allocLen){
        q->allocLen *= 2;
        q->base = realloc(q->base, q->elem_size * q->allocLen);
        assert(q->base != NULL);
    }
    memcpy((char*)q->base + q->logLen * q->elem_size, elem, q->elem_size);
    q->logLen++;
}

void* QueueDequeue(Queue* q){
    void* elem = malloc(q->elem_size);
    assert(elem != NULL);
    memcpy(elem, QueueFront(q), q->elem_size);
    if(elem == NULL) return NULL;
    q->base = realloc((char*)q->base + q->elem_size, q->elem_size * q->allocLen);
    q->logLen--;
    return elem;
}

void QueueDestroy(Queue* q){
    free(q->base);
}

int main(){
    return 0;
}