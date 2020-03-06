#include "linked-list.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>


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
    assert(index >= 0 || index < ll->length);

    Cell* res = ll->head;
    for(int i=0; i<index; i++){
        res = res->next;
    }
    // printf("%d\n", ll->elem_size);
    void* elem = malloc(ll->elem_size);
    // printf("movedi aqamde\n");
    assert(elem != NULL);
    memcpy(elem, res->base, ll->elem_size);
    return elem;
}

void LinkedListInsert(LinkedList* ll, void* elem, int index){
    assert(index >= 0 || index <= ll->length);
    Cell* temp = malloc(sizeof(Cell));
    temp->base = malloc(sizeof(ll->elem_size));
    assert(temp != NULL && temp->base != NULL);
    memcpy(temp->base, elem, ll->elem_size);

    if(index == 0){
        temp->next = ll->head;
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

void LinkedListRemove(LinkedList* ll, int index){
    assert(index >= 0 || index < ll->length);

    if(index == 0){
        if(ll->freeFn != NULL) ll->freeFn(ll->head->base);
        Cell* temp = ll->head->next;
        free(ll->head);
        ll->head = temp;
    } else {
        Cell* temp = ll->head;
        for(int i=1; i<index; i++){
            temp = temp->next;
        }
        Cell* t = temp->next;
        temp->next = temp->next->next;
        if(ll->freeFn != NULL) ll->freeFn(t->base);
        free(t);
    }
    ll->length--;
}

void LinkedListPush(LinkedList* ll, void* elem){
    LinkedListInsert(ll, elem, ll->length);
}

void LinkedListPop(LinkedList* ll){
    LinkedListRemove(ll, ll->length-1);
}

void LinkedListShift(LinkedList* ll){
    LinkedListRemove(ll, 0);
}

void LinkedListUnshift(LinkedList* ll, void* elem){
    LinkedListInsert(ll, elem, 0);
}

void LinkedListDestroy(LinkedList* ll){
    Cell* temp = ll->head;
    while(ll->head != NULL){
        ll->head = ll->head->next;
        if(ll->freeFn != NULL) ll->freeFn(temp->base);
        free(temp);
        temp = ll->head;
    }
}
