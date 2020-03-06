#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>



void StackNew(Stack* stack, int elem_size, StackFreeFunction freeFn){
    stack->logLen = 0;
    stack->allocLen = 1;
    stack->elem_size = elem_size;
    stack->base = malloc(stack->elem_size);
    assert(stack->base != NULL);
    stack->freeFn = freeFn;
}

int StackIsEmpty(Stack* stack){
    return stack->logLen == 0;
}

int StackSize(Stack* stack){
    return stack->logLen;
}

int StackCapacity(Stack* stack){
    return stack->allocLen;
}

void* StackTop(Stack* stack){
    assert(stack->logLen != 0);
    void* elem = malloc(stack->elem_size);
    assert(elem != NULL);
    memcpy(elem, (char*)stack->base + (stack->logLen - 1)*stack->elem_size, stack->elem_size);
    return elem;
}

void StackPush(Stack* stack, void* elem){
    if(stack->logLen >= stack->allocLen){
        stack->allocLen *= 2;
        stack->base = realloc(stack->base, stack->elem_size * stack->allocLen);
        assert(stack->base != NULL);
    }
    memcpy((char*)stack->base + stack->logLen * stack->elem_size, elem, stack->elem_size);
    stack->logLen++;
}

void* StackPop(Stack* stack){
    void* elem = StackTop(stack);
    if(stack->freeFn != NULL) stack->freeFn((char*)stack->base + (stack->logLen - 1)*stack->elem_size);
    stack->logLen--;
    return elem;
} 

void StackDestroy(Stack* stack){
    if(stack->freeFn != NULL){
        for(int i=0; i<stack->logLen; i++){
            stack->freeFn((char*)stack->base + i * stack->elem_size);
        }
    }
    free(stack->base);
}