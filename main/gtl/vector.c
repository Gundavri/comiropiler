#include <stdlib.h>
#include <string.h>

typedef struct {
    void* base;
    int logLen;
    int allocLen;
    int elem_size;
} Vector;


void VectorNew(Vector* vec, int elem_size){
    vec->logLen = 0;
    vec->allocLen = elem_size;
    vec->elem_size = elem_size;
    vec->base = malloc(vec->allocLen);
}


int VectorIsEmpty(Vector* vec){
    return vec->logLen == 0;
}

int VectorSize(Vector* vec){
    return vec->logLen;
}

int VectorCapacity(Vector* vec){
    return vec->allocLen;
}

void* VectorGet(Vector* vec, int index){
    return (index < 0 || index >= vec->logLen) ? NULL : (char*)vec->base + index * vec->elem_size;
}

void VectorInsert(Vector* vec, void* elem, int index){
    if(index < 0 || index > vec->logLen) return; 

    if(vec->logLen >= vec->allocLen) {
        vec->allocLen *= 2;
        vec->base = realloc(vec->base, vec->allocLen);
    }

    memmove((char*)vec->base + vec->elem_size * (index + 1), (char*)vec->base + vec->elem_size * index, vec->elem_size * (vec->logLen - index));
    memcpy((char*)vec->base + vec->elem_size * index, elem, vec->elem_size);
}

void VectorRemove(Vector* vec, int index){
    if(index < 0 || index > vec->logLen) return;
    
}
