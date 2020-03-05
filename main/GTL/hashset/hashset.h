#ifndef _hashset_
#define _hashset_

typedef void (*HashSetFreeFunction)(void *elem);

typedef struct{
    int elem_size;
    int length;
    HashSetFreeFunction freeFn;
    LinkedListGeneric* base;
} HashSet;

void HashSetNew(HashSet* hs, int elem_size, HashSetFreeFunction freeFn);

int HashSetIsEmpty(HashSet* hs);

int HashSetSize(HashSet* hs);

void HashSetAdd(HashSet* hs, void* elem);

int HashSetHas(HashSet* hs, void* elem);

void HashSetRemove(HashSet* hs, void* elem);

void HashSetClear(HashSet* hs);

void HashSetDestroy(HashSet* hs);

#endif