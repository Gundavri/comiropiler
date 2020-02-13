#include <stdlib.h>
#include <string.h>

typedef struct {
    void* base;
    int logLen;
    int allocLen;
    int elem_size;
} Stack;

void StackNew(Stack* stack, int elem_size){
    stack->logLen = 0;
    stack->allocLen = elem_size;
    stack->elem_size = elem_size;
    stack->base = malloc(stack->allocLen);
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
    return stack->logLen == 0 ? NULL : (char*)stack->base + (stack->logLen - 1)*stack->elem_size;
}

void StackPush(Stack* stack, void* elem){
    if(stack->logLen >= stack->allocLen){
        stack->allocLen *= 2;
        stack->base = realloc(stack->base, stack->elem_size * stack->allocLen);
    }
    memcpy((char*)stack->base + stack->logLen * stack->elem_size, elem, stack->elem_size);
    stack->logLen++;
}

void* StackPop(Stack* stack){
    void* elem = StackTop(stack);
    if(elem == NULL) return NULL;
    stack->logLen--;
    return elem;
} 

void StackDestroy(Stack* stack){
    free(stack->base);
}

int main(){
    return 0;
}