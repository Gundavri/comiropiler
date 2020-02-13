#include <stdlib.h>
#include <string.h>

typedef struct {
    void* base;
    void* fakeBase;
    int logLen;
    int allocLen;
    int elem_size;
} Queue;

void QueueNew(Queue* q, int elem_size){
    q->logLen = 0;
    q->allocLen = elem_size;
    q->elem_size = elem_size;
    q->fakeBase = malloc(q->allocLen);
    q->base = q->fakeBase;
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
    return q->logLen == 0 ? NULL : q->fakeBase;
}

void* QueueBack(Queue* q){
    return q->logLen == 0 ? NULL : (char*)q->fakeBase + q->elem_size * (q->logLen - 1);
}

void QueueEnqueue(Queue* q, void* elem){
    if(q->logLen >= q->allocLen){
        q->allocLen *= 2;
        q->fakeBase = realloc(q->fakeBase, q->elem_size * q->allocLen);
    }
    memcpy((char*)q->fakeBase + q->logLen * q->elem_size, elem, q->elem_size);
    q->logLen++;
}

void* QueueDequeue(Queue* q){
    void* elem = QueueFront(q);
    if(elem == NULL) return NULL;
    q->fakeBase = (char*)q->fakeBase + q->elem_size;
    q->logLen--;
    return elem;
}

void QueueDestroy(Queue* q){
    free(q->base);
}

int main(){
    return 0;
}