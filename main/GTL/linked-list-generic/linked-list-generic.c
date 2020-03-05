#include "linked-list-generic.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stdio.h"

void LinkedListGenericNew(LinkedListGeneric* ll){
    ll->head = NULL;
    ll->length = 0;
}

int LinkedListGenericIsEmpty(LinkedListGeneric* ll){
    return ll->length == 0;
}

int LinkedListGenericSize(LinkedListGeneric* ll){
    return ll->length;
}

void* LinkedListGenericGet(LinkedListGeneric* ll, int index){
    if(index < 0 || index >= ll->length) return NULL;
    
    CellG* res = ll->head;
    for(int i=0; i<index; i++){
        res = res->next;
    }
    void* elem = malloc(res->elem_size);
    memcpy(elem, res->base, res->elem_size);
    return elem;
}

void LinkedListGenericInsert(LinkedListGeneric* ll, void* elem, int elem_size, CellGFreeFunction freeFn, int index){
    if(index < 0 || index > ll->length) return;
    CellG* newCellG = malloc(sizeof(CellG));
    newCellG->base = malloc(elem_size);
    assert(newCellG != NULL && newCellG->base != NULL);
    memcpy(newCellG->base, elem, elem_size);
    newCellG->elem_size = elem_size;
    newCellG->freeFn = freeFn;

    if(index == 0){
        newCellG->next = ll->head;
        ll->head = newCellG;
    } else {
        CellG* temp = ll->head;
        for(int i=1; i<index; i++){
            temp = temp->next;
        }
        newCellG->next = temp->next;
        temp->next = newCellG;
    }
    ll->length++;
}

void LinkedListGenericRemove(LinkedListGeneric* ll, int index){
    if(index < 0 || index >= ll->length) return;

    if(index == 0){
        if(ll->head->freeFn != NULL) ll->head->freeFn(ll->head->base);
        CellG* temp = ll->head->next;
        free(ll->head);
        ll->head = temp;
    } else {
        CellG* temp = ll->head;
        for(int i=1; i<index; i++){
            temp = temp->next;
        }
        CellG* t = temp->next;
        temp->next = temp->next->next;
        if(t->freeFn != NULL) t->freeFn(t->base);
        free(t);
    }
    ll->length--;
}

void LinkedListGenericPush(LinkedListGeneric* ll, void* elem, int elem_size, CellGFreeFunction freeFn){
    LinkedListGenericInsert(ll, elem, elem_size, freeFn, ll->length);
}

void LinkedListGenericPop(LinkedListGeneric* ll){
    LinkedListGenericRemove(ll, ll->length-1);
}

void LinkedListGenericShift(LinkedListGeneric* ll){
    LinkedListGenericRemove(ll, 0);
}

void LinkedListGenericUnshift(LinkedListGeneric* ll, void* elem, int elem_size, CellGFreeFunction freeFn){
    LinkedListGenericInsert(ll, elem, elem_size, freeFn, 0);
}


void LinkedListGenericDestroy(LinkedListGeneric* ll){
    for(int i=0; i<ll->length; i++){
        CellG* t = ll->head->next;
        if(ll->head->freeFn != NULL) ll->head->freeFn(ll->head->base);
        free(ll->head);
        ll->head = t;
    }
}