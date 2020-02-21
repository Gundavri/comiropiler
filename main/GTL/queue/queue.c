#include "queue.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>


void QueueNew(Queue* q, int elem_size, QueueFreeFunction freeFn){
    q->logLen = 0;
    q->allocLen = 1;
    q->elem_size = elem_size;
    q->base = malloc(q->elem_size);
    assert(q->base != NULL);
    q->freeFn = freeFn;
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
    if(q->logLen == 0) return NULL;
    void* elem = malloc(q->elem_size);
    memcpy(elem, q->base, q->elem_size);
    return elem;
}

void* QueueBack(Queue* q){
    if(q->logLen == 0) return NULL;
    void* elem = malloc(q->elem_size);
    memcpy(elem, (char*)q->base + q->elem_size * (q->logLen - 1), q->elem_size);
    return elem;
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
    void* elem = QueueFront(q);
    if(elem == NULL) return NULL;
    if(q->freeFn != NULL) q->freeFn(q->base);
    q->logLen--;
    void* newBase = malloc(q->elem_size * q->logLen);
    memcpy(newBase, (char*)q->base + q->elem_size, q->elem_size * q->logLen);
    free(q->base);
    q->base = newBase;
    return elem;
}

void QueueDestroy(Queue* q){
    if(q->freeFn != NULL){
        for(int i=0; i<q->logLen; i++){
            q->freeFn((char*)q->base + i * q->elem_size);
        }
    }
    free(q->base);
}
