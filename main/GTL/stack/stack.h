#ifndef _stack_
#define _stack_

typedef void (*StackFreeFunction)(void *elem);
typedef struct {
    void* base;
    int logLen;
    int allocLen;
    int elem_size;
    StackFreeFunction freeFn;
} Stack;


void StackNew(Stack* stack, int elem_size, StackFreeFunction freeFn);

int StackIsEmpty(Stack* stack);

int StackSize(Stack* stack);

int StackCapacity(Stack* stack);

void* StackTop(Stack* stack);

void StackPush(Stack* stack, void* elem);

void* StackPop(Stack* stack);

void StackDestroy(Stack* stack);

#endif