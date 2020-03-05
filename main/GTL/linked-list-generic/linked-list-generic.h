#ifndef _LinkedListGeneric_
#define _LinkedListGeneric_

typedef void (*CellFreeFunction)(void *elem);

typedef struct nCell {
    void* base;
    int elem_size;
    CellFreeFunction freeFn;
    struct nCell* next;
} Cell;

typedef struct {
    Cell* head;
    int length;
} LinkedListGeneric;


void LinkedListGenericNew(LinkedListGeneric* ll);

int LinkedListGenericIsEmpty(LinkedListGeneric* ll);

int LinkedListGenericSize(LinkedListGeneric* ll);

void* LinkedListGenericGet(LinkedListGeneric* ll, int index);

void LinkedListGenericInsert(LinkedListGeneric* ll, void* elem, int elem_size, CellFreeFunction freeFn, int index);

void LinkedListGenericRemove(LinkedListGeneric* ll, int index);

void LinkedListGenericPush(LinkedListGeneric* ll, void* elem, int elem_size, CellFreeFunction freeFn);

void LinkedListGenericPop(LinkedListGeneric* ll);

void LinkedListGenericShift(LinkedListGeneric* ll);

void LinkedListGenericUnshift(LinkedListGeneric* ll, void* elem, int elem_size, CellFreeFunction freeFn);

void LinkedListGenericDestroy(LinkedListGeneric* ll);

#endif