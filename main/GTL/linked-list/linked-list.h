#ifndef _linkedlist_
#define _linkedlist_

typedef void (*CellFreeFunction)(void *elem);

typedef struct {
    void* base;
    int elem_size;
    CellFreeFunction freeFn;
    void* next;
} Cell;

typedef struct {
    Cell* head;
    int length;
} LinkedList;


void LinkedListNew(LinkedList* ll);

int LinkedListIsEmpty(LinkedList* ll);

int LinkedListSize(LinkedList* ll);

void* LinkedListGet(LinkedList* ll, int index);

void LinkedListInsert(LinkedList* ll, void* elem, int elem_size, CellFreeFunction freeFn, int index);

void LinkedListRemove(LinkedList* ll, int index);

void LinkedListPush(LinkedList* ll, void* elem, int elem_size, CellFreeFunction freeFn);

void LinkedListPop(LinkedList* ll);

void LinkedListShift(LinkedList* ll);

void LinkedListUnshift(LinkedList* ll, void* elem, int elem_size, CellFreeFunction freeFn);

void LinkedListDestroy(LinkedList* ll);

#endif