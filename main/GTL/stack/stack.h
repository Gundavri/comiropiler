#ifndef _stack_
#define _stack_

typedef struct {
    void* base;
    int logLen;
    int allocLen;
    int elem_size;
} Stack;


void StackNew(Stack* stack, int elem_size);

int StackIsEmpty(Stack* stack);

int StackSize(Stack* stack);

int StackCapacity(Stack* stack);

void* StackTop(Stack* stack);

void StackPush(Stack* stack, void* elem);

void* StackPop(Stack* stack);

void StackDestroy(Stack* stack);

#endif