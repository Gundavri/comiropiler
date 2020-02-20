#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>



void StackNew(Stack* stack, int elem_size, StackFreeFunction freeFn){
    printf("movedi\n");
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
    if(stack->logLen == 0) return NULL;
    void* elem = malloc(stack->elem_size);
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
    void* t = StackTop(stack);
    if(t == NULL) return NULL;
    if(stack->freeFn != NULL) stack->freeFn((char*)stack->base + stack->elem_size * (stack->logLen-1));
    stack->base = realloc(stack->base, stack->elem_size * (stack->logLen-1));
    stack->logLen--;
    return t;
} 

void StackDestroy(Stack* stack){
    free(stack->base);
}