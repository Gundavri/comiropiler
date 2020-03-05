#ifndef _LinkedList_
#define _LinkedList_

typedef void (*CellFreeFunction)(void *elem);

typedef struct tCell{
    void* base;
    struct tCell* next;
} Cell;

typedef struct {
    Cell* head;
    CellFreeFunction freeFn;
    int elem_size;
    int length;
} LinkedList;


// void LinkedListNew(LinkedList* ll, int elem_size, CellFreeFunction freeFn);

// int LinkedListIsEmpty(LinkedList* ll);

// int LinkedListSize(LinkedList* ll);

// void* LinkedListGet(LinkedList* ll, int index);

// void LinkedListInsert(LinkedList* ll, void* elem, int index);

// void LinkedListRemove(LinkedList* ll, int index);

// void LinkedListPush(LinkedList* ll, void* elem, int elem_size, CellFreeFunction freeFn);

// void LinkedListPop(LinkedList* ll);

// void LinkedListShift(LinkedList* ll);

// void LinkedListUnshift(LinkedList* ll, void* elem, int elem_size, CellFreeFunction freeFn);

// void LinkedListDestroy(LinkedList* ll);

#endif