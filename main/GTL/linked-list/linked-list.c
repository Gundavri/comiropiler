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

void LinkedListRemove(LinkedList* ll, int index){
    if(index < 0 || index >= ll->length) return;

    if(index == 0){
        if(ll->head->freeFn != NULL) ll->head->freeFn(ll->head->base);
        Cell* temp = ll->head->next;
        free(ll->head);
        ll->head = temp;
    } else {
        Cell* temp = ll->head;
        for(int i=1; i<index; i++){
            temp = temp->next;
        }
        Cell* t = temp->next;
        if(t->freeFn != NULL) t->freeFn(temp->next->base);
        temp->next = temp->next->next;
        free(t);
    }
    ll->length--;
}

void LinkedListPush(LinkedList* ll, void* elem, int elem_size, CellFreeFunction freeFn){
    LinkedListInsert(ll, elem, elem_size, freeFn, ll->length);
}

void LinkedListPop(LinkedList* ll){
    LinkedListRemove(ll, ll->length-1);
}

void LinkedListShift(LinkedList* ll){
    LinkedListRemove(ll, 0);
}

void LinkedListUnshift(LinkedList* ll, void* elem, int elem_size, CellFreeFunction freeFn){
    LinkedListInsert(ll, elem, elem_size, freeFn, 0);
}


void LinkedListDestroy(LinkedList* ll){
    for(int i=0; i<ll->length; i++){
        Cell* t = ll->head->next;
        if(ll->head->freeFn != NULL) ll->head->freeFn(ll->head->base);
        free(ll->head);
        ll->head = t;
    }
}

int main(){
    return 0;
}