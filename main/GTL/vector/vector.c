#include "vector.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>


void VectorNew(Vector* vec, int elem_size, VectorFreeFunction freeFn){
    vec->logLen = 0;
    vec->allocLen = 1;
    vec->elem_size = elem_size;
    vec->base = malloc(vec->elem_size);
    assert(vec->base != NULL);
    vec->freeFn = freeFn;
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
    if(index < 0 || index >= vec->logLen) return NULL;
    void* elem = malloc(vec->elem_size);
    memcpy(elem, (char*)vec->base + index * vec->elem_size, vec->elem_size);
    return elem;
}

void VectorInsert(Vector* vec, void* elem, int index){
    if(index < 0 || index > vec->logLen) return; 

    if(vec->logLen >= vec->allocLen) {
        vec->allocLen *= 2;
        vec->base = realloc(vec->base, vec->allocLen * vec->elem_size);
    }
    memmove((char*)vec->base + vec->elem_size * (index + 1), (char*)vec->base + vec->elem_size * index, vec->elem_size * (vec->logLen - index));
    memcpy((char*)vec->base + vec->elem_size * index, elem, vec->elem_size);
    vec->logLen++;
}

void VectorRemove(Vector* vec, int index){
    if(index < 0 || index >= vec->logLen) return;
    if(vec->freeFn != NULL) vec->freeFn((char*)vec->base + vec->elem_size * index);
    memmove((char*)vec->base + vec->elem_size * index, (char*)vec->base + vec->elem_size * (index + 1), vec->elem_size * (vec->logLen - index - 1));
    vec->logLen--;
}


void VectorPush(Vector* vec, void* elem){
    VectorInsert(vec, elem, vec->logLen);
}

void VectorPop(Vector* vec){
    VectorRemove(vec, vec->logLen - 1);
}

void VectorShift(Vector* vec){
    VectorRemove(vec, 0);
}

void VectorUnshift(Vector* vec, void* elem){
    VectorInsert(vec, elem, 0);
}

void VectorSort(Vector* vec, VectorCompareFunction cmpFn){
    assert(vec->base != NULL);
    qsort(vec->base, vec->logLen, vec->elem_size, cmpFn);
}

void VectorDestroy(Vector* vec){
    if(vec->freeFn != NULL){
        for(int i=0; i<vec->logLen; i++){
            vec->freeFn((char*)vec->base + i * vec->elem_size);   
        }
    }
    free(vec->base);
}