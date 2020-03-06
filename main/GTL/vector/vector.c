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
    assert(index >= 0 || index < vec->logLen);
    void* elem = malloc(vec->elem_size);
    assert(elem != NULL);
    memcpy(elem, (char*)vec->base + index * vec->elem_size, vec->elem_size);
    return elem;
}

void VectorInsert(Vector* vec, void* elem, int index){
    assert(index >= 0 || index <= vec->logLen); 

    if(vec->logLen >= vec->allocLen) {
        vec->allocLen *= 2;
        vec->base = realloc(vec->base, vec->allocLen * vec->elem_size);
        assert(vec->base != NULL);
    }
    memmove((char*)vec->base + vec->elem_size * (index + 1), (char*)vec->base + vec->elem_size * index, vec->elem_size * (vec->logLen - index));
    memcpy((char*)vec->base + vec->elem_size * index, elem, vec->elem_size);
    vec->logLen++;
}

void VectorRemove(Vector* vec, int index){
    assert(index >= 0 || index < vec->logLen);
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

int VectorFind(Vector* vec, VectorCompareFunction cmpFn, const void* elem, int startIndex, int isSorted){
    if(isSorted) {
        void* res = bsearch(elem, (char*)vec->base + startIndex * vec->elem_size, vec->logLen - startIndex, vec->elem_size, cmpFn);
        return res == NULL ? -1 : (res - vec->base) / vec->elem_size;
    }
    for(int i=startIndex; i<vec->logLen; i++){
        void* temp = (char*)vec->base + i*vec->elem_size;
        if(cmpFn(elem, temp) == 0) return i;
    }
    return -1;
}


void VectorDestroy(Vector* vec){
    if(vec->freeFn != NULL){
        for(int i=0; i<vec->logLen; i++){
            vec->freeFn((char*)vec->base + i * vec->elem_size);   
        }
    }
    free(vec->base);
}