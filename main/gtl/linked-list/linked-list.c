#include "linked-list.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void LinkedListNew(LinkedList* ll){
    ll->head = NULL;
    ll->length = 0;
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
    return res->base;
}

void LinkedListInsert(LinkedList* ll, void* elem, int elem_size, CellFreeFunction freeFn, int index){
    if(index < 0 || index > ll->length) return;

    Cell* newCell = malloc(sizeof(Cell));
    newCell->base = malloc(elem_size);
    assert(newCell != NULL && newCell->base != NULL);
    memcpy(newCell->base, elem, elem_size);
    newCell->elem_size = elem_size;
    newCell->freeFn = freeFn;

    if(index == 0){
        newCell->next = ll->head;
        ll->head = newCell;
    } else {
        Cell* temp = ll->head;
        for(int i=1; i<index; i++){
            temp = temp->next;
        }
        newCell->next = temp->next;
        temp->next = newCell->next;
    }
    ll->length++;
}