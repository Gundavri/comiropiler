#ifndef _LinkedListGeneric_
#define _LinkedListGeneric_

typedef void (*CellGFreeFunction)(void *elem);

typedef struct nCellG {
    void* base;
    int elem_size;
    CellGFreeFunction freeFn;
    struct nCellG* next;
} CellG;

typedef struct {
    CellG* head;
    int length;
} LinkedListGeneric;


void LinkedListGenericNew(LinkedListGeneric* ll);

int LinkedListGenericIsEmpty(LinkedListGeneric* ll);

int LinkedListGenericSize(LinkedListGeneric* ll);

void* LinkedListGenericGet(LinkedListGeneric* ll, int index);

void LinkedListGenericInsert(LinkedListGeneric* ll, void* elem, int elem_size, CellGFreeFunction freeFn, int index);

void LinkedListGenericRemove(LinkedListGeneric* ll, int index);

void LinkedListGenericPush(LinkedListGeneric* ll, void* elem, int elem_size, CellGFreeFunction freeFn);

void LinkedListGenericPop(LinkedListGeneric* ll);

void LinkedListGenericShift(LinkedListGeneric* ll);

void LinkedListGenericUnshift(LinkedListGeneric* ll, void* elem, int elem_size, CellGFreeFunction freeFn);

void LinkedListGenericDestroy(LinkedListGeneric* ll);

#endif