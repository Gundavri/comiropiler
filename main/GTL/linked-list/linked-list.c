#include "linked-list.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stdio.h"


void LinkedListNew(LinkedList* ll, int elem_size, CellFreeFunction freeFn){
    ll->head = NULL;
    ll->length = 0;
    ll->elem_size = elem_size;
    ll->freeFn = freeFn;
}

int LinkedListIsEmpty(LinkedList* ll){
    return ll->length == 0;
}

int LinkedListSize(LinkedList* ll){
    return ll->length;
}

void* LinkedListGet(LinkedList* ll, int index){
    if(index < 0 || index >= ll->length) return NULL;

    Cell* res = ll->head;
    for(int i=0; i<index; i++){
        res = res->next;
    }

    void* elem = malloc(sizeof(ll->elem_size));
    assert(elem != NULL);
    memcpy(elem, res->base, ll->elem_size);
    return elem;
}

void LinkedListInsert(LinkedList* ll, void* elem, int index){
    if(index < 0 || index > ll->length) return;
    Cell* temp = malloc(sizeof(Cell));
    temp->base = malloc(sizeof(ll->elem_size));
    memcpy(temp->base, elem, ll->elem_size);

    if(index == 0){
        temp->next == ll->head;
        ll->head = temp;
    } else {
        Cell* t = ll->head;
        for(int i=1; i<index; i++){
            t = t->next;
        }
        temp->next = t->next;
        t->next = temp;
    }
    ll->length++;
}

// void LinkedListRemove(LinkedList* ll, int index);

// void LinkedListPush(LinkedList* ll, void* elem, int elem_size, CellFreeFunction freeFn);

// void LinkedListPop(LinkedList* ll);

// void LinkedListShift(LinkedList* ll);

// void LinkedListUnshift(LinkedList* ll, void* elem, int elem_size, CellFreeFunction freeFn);

// void LinkedListDestroy(LinkedList* ll);
