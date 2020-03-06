#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./queue/queue.h"
#include "./stack/stack.h"
#include "./vector/vector.h"
#include "./linked-list-generic/linked-list-generic.h"
#include "./linked-list/linked-list.h"


typedef struct{
 int a;
 int* b;
 char c;
 char* d;
 int e[3];
 void* f;
} tt;

int num = 10;
char* txt = "abcde-!@#$^&*()+zxc";
tt* strtt;

void allocStruct(){
    strtt = malloc(sizeof(tt));
    strtt->a = 5;
    strtt->b = malloc(sizeof(int));
    memcpy(strtt->b, &(strtt->a), sizeof(int));
    strtt->c = 'a';
    strtt->d = malloc(sizeof(char));
    strtt->e[0] = 1;
    strtt->e[1] = 2;
    strtt->e[2] = 3;
}

int structCmp(tt* tt1, tt* tt2){
    if(tt1->a != tt2->a  || tt1->c != tt2->c){
        return -1;
    }
    for(int i=0; i<3; i++){
        if(tt1->e[i] != tt2->e[i]) return -1;
    }
    return 0;
}

int structCmpFn(const void* vp1, const void* vp2){
    int a = *(int*)vp1;
    int b = *(int*)vp2;
    return a-b;
}

int intCmpFn(const void* vp1, const void* vp2){
    return *(int*)vp1 - *(int*)vp2;
}

void StructFreeFn(void* elem){
    tt* t = (tt*)elem;
    free(t->b);
    free(t->d);
}


void testStack();

void testStackInt();
void testStackChar();
void testStackStruct();


void testQueue();

void testQueueInt();
void testQueueChar();
void testQueueStruct();


void testVector();

void testVectorInt();
void testVectorChar();
void testVectorStruct();


void testLinkedListGeneric();

void testLinkedListGenericInt();
void testLinkedListGenericChar();
void testLinkedListGenericStruct();


void testLinkedList();

void testLinkedListInt();
void testLinkedListChar();
void testLinkedListStruct();


int main(){
    // testStack();
    // testQueue();
    // testVector();
    // testLinkedListGeneric();
    testLinkedList();
    return 0;
}


void testStack() {
    testStackInt();
    testStackChar();
    testStackStruct();
}

void testQueue() {
    testQueueInt();
    testQueueChar();
    testQueueStruct();
}

void testVector(){
    testVectorInt();
    testVectorChar();
    testVectorStruct();
}

void testLinkedListGeneric(){
    testLinkedListGenericInt();
    testLinkedListGenericChar();
    testLinkedListGenericStruct();
}

void testLinkedList(){
    testLinkedListInt();
    testLinkedListChar();
    testLinkedListStruct();
}

// Stacks
void testStackInt(){
    Stack* s = malloc(sizeof(Stack));
    StackNew(s, sizeof(int), NULL);
    if(StackSize(s) == 0 && StackIsEmpty(s)) printf("StackInt ---size--- |Good|\n");
    else printf("StackInt ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        StackPush(s, &i);
        if(StackSize(s) == i+1) printf("StackInt ---size--- |Good|\n");
        else printf("StackInt ---size--- |Bad|\n");
        if(*(int*)StackTop(s) == i) printf("StackInt ---top--- |Good|\n");
        else printf("StackInt ---top--- |Bad|\n");
    }
    printf("StackInt ---stackcapacity--- %d\n", StackCapacity(s));
    for(int i=0; i<num; i++){
        if(StackSize(s) == num-i) printf("StackInt ---size--- |Good|\n");
        else printf("StackInt ---size--- |Bad|\n");
        if(*(int*)StackTop(s) == num-i-1) printf("StackInt ---top--- |Good|\n");
        else printf("StackInt ---top--- |Bad|\n");
        if(*(int*)StackPop(s) == num-1-i) printf("StackInt ---pop--- |Good|\n");
        else printf("StackInt ---pop--- |Bad|\n");
    }
    StackDestroy(s);
    free(s);
}

void testStackChar(){
    Stack* s = malloc(sizeof(Stack));
    StackNew(s, sizeof(char*), NULL);
    if(StackSize(s) == 0 && StackIsEmpty(s)) printf("StackChar ---size--- |Good|\n");
    else printf("StackChar ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        StackPush(s, &txt);
        if(StackSize(s) == i+1) printf("StackChar ---size--- |Good|\n");
        else printf("StackChar ---size--- |Bad|\n");
        if(strcmp(*(char**)StackTop(s), txt) == 0) printf("StackChar ---top--- |Good|\n");
        else printf("StackChar ---top--- |Bad|\n");
    }
    printf("StackChar ---stackcapacity--- %d\n", StackCapacity(s));
    for(int i=0; i<num; i++){
        if(StackSize(s) == num-i) printf("StackChar ---size--- |Good|\n");
        else printf("StackChar ---size--- |Bad|\n");
        if(strcmp(*(char**)StackTop(s), txt) == 0) printf("StackChar ---top--- |Good|\n");
        else printf("StackChar ---top--- |Bad|\n");
        if(strcmp(*(char**)StackPop(s), txt) == 0) printf("StackChar ---pop--- |Good|\n");
        else printf("StackChar ---pop--- |Bad|\n");
    }
    StackDestroy(s);
    free(s);
}

void testStackStruct(){
    Stack* s = malloc(sizeof(Stack));
    StackNew(s, sizeof(tt), StructFreeFn);
    if(StackSize(s) == 0 && StackIsEmpty(s)) printf("StackStruct ---size--- |Good|\n");
    else printf("StackStruct ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        allocStruct();
        StackPush(s, strtt);
        if(StackSize(s) == i+1) printf("StackStruct ---size--- |Good|\n");
        else printf("StackStruct ---size--- |Bad|\n");
        if(structCmp(StackTop(s), strtt) == 0) printf("StackStruct ---top--- |Good|\n");
        else printf("StackStruct ---top--- |Bad|\n");
    }
    printf("StackStruct ---stackcapacity--- %d\n", StackCapacity(s));
    for(int i=0; i<num; i++){
        if(StackSize(s) == num-i) printf("StackStruct ---size--- |Good|\n");
        else printf("StackStruct ---size--- |Bad|\n");
        if(structCmp(StackTop(s), strtt) == 0) printf("StackStruct ---top--- |Good|\n");
        else printf("StackStruct ---top--- |Bad|\n");
        if(structCmp(StackPop(s), strtt) == 0) printf("StackStruct ---pop--- |Good|\n");
        else printf("StackStruct ---pop--- |Bad|\n");
    }
    StackDestroy(s);
    free(s);
}


// Queues
void testQueueInt(){
    Queue* q = malloc(sizeof(Queue));
    QueueNew(q, sizeof(int), NULL);
    if(QueueSize(q) == 0 && QueueIsEmpty(q)) printf("QueueInt ---size--- |Good|\n");
    else printf("QueueInt ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        QueueEnqueue(q, &i);
        if(QueueSize(q) == i+1) printf("QueueInt ---size--- |Good|\n");
        else printf("QueueInt ---size--- |Bad|\n");
        if(*(int*)QueueBack(q) == i) printf("QueueInt ---back--- |Good|\n");
        else printf("QueueInt ---back--- |Bad|\n");
        if(*(int*)QueueFront(q) == 0) printf("QueueInt ---front--- |Good|\n");
        else printf("QueueInt ---front--- |Bad|\n");
    }
    printf("QueueInt ---queuecapacity--- %d\n", QueueCapacity(q));
    for(int i=0; i<num; i++){
        if(QueueSize(q) == num-i) printf("QueueInt ---size--- |Good|\n");
        else printf("QueueInt ---size--- |Bad|\n");
        if(*(int*)QueueBack(q) == num-1) printf("QueueInt ---back--- |Good|\n");
        else printf("QueueInt ---back--- |Bad|\n");
        if(*(int*)QueueFront(q) == i) printf("QueueInt ---front--- |Good|\n");
        else printf("QueueInt ---front--- |Bad|\n");
        if(*(int*)QueueDequeue(q) == i) printf("QueueInt ---dequeue--- |Good|\n");
        else printf("QueueInt ---dequeue--- |Bad|\n");
    }
    QueueDestroy(q);
    free(q);
}

void testQueueChar(){
    Queue* q = malloc(sizeof(Queue));
    QueueNew(q, sizeof(char*), NULL);
    if(QueueSize(q) == 0 && QueueIsEmpty(q)) printf("QueueChar ---size--- |Good|\n");
    else printf("QueueChar ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        QueueEnqueue(q, &txt);
        if(QueueSize(q) == i+1) printf("QueueChar ---size--- |Good|\n");
        else printf("QueueChar ---size--- |Bad|\n");
        if(strcmp(*(char**)QueueBack(q), txt) == 0) printf("QueueChar ---back--- |Good|\n");
        else printf("QueueChar ---back--- |Bad|\n");
        if(strcmp(*(char**)QueueFront(q), txt) == 0) printf("QueueChar ---front--- |Good|\n");
        else printf("QueueChar ---front--- |Bad|\n");
    }
    printf("QueueChar ---queuecapacity--- %d\n", QueueCapacity(q));
    for(int i=0; i<num; i++){
        if(QueueSize(q) == num-i) printf("QueueChar ---size--- |Good|\n");
        else printf("QueueChar ---size--- |Bad|\n");
        if(strcmp(*(char**)QueueBack(q), txt) == 0) printf("QueueChar ---back--- |Good|\n");
        else printf("QueueChar ---back--- |Bad|\n");
        if(strcmp(*(char**)QueueFront(q), txt) == 0) printf("QueueChar ---front--- |Good|\n");
        else printf("QueueChar ---front--- |Bad|\n");
        if(strcmp(*(char**)QueueDequeue(q), txt) == 0) printf("QueueChar ---dequeue--- |Good|\n");
        else printf("QueueChar ---dequeue--- |Bad|\n");
    }
    QueueDestroy(q);
    free(q);
}

void testQueueStruct(){
    Queue* q = malloc(sizeof(Queue));
    QueueNew(q, sizeof(tt), StructFreeFn);
    if(QueueSize(q) == 0 && QueueIsEmpty(q)) printf("QueueStruct ---size--- |Good|\n");
    else printf("QueueStruct ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        allocStruct();
        QueueEnqueue(q, strtt);
        if(QueueSize(q) == i+1) printf("QueueStruct ---size--- |Good|\n");
        else printf("QueueStruct ---size--- |Bad|\n");
        if(structCmp(QueueBack(q), strtt) == 0) printf("QueueStruct ---back--- |Good|\n");
        else printf("QueueStruct ---back--- |Bad|\n");
        if(structCmp(QueueFront(q), strtt) == 0) printf("QueueStruct ---front--- |Good|\n");
        else printf("QueueStruct ---front--- |Bad|\n");
    }
    printf("QueueStruct ---queuecapacity--- %d\n", QueueCapacity(q));
    for(int i=0; i<num; i++){
        if(QueueSize(q) == num-i) printf("QueueStruct ---size--- |Good|\n");
        else printf("QueueStruct ---size--- |Bad|\n");
        if(structCmp(QueueBack(q), strtt) == 0) printf("QueueStruct ---back--- |Good|\n");
        else printf("QueueStruct ---back--- |Bad|\n");
        if(structCmp(QueueFront(q), strtt) == 0) printf("QueueStruct ---front--- |Good|\n");
        else printf("QueueStruct ---front--- |Bad|\n");
        if(structCmp(QueueDequeue(q), strtt) == 0) printf("QueueStruct ---dequeue--- |Good|\n");
        else printf("QueueStruct ---dequeue--- |Bad|\n");
    }
    QueueDestroy(q);
    free(q);
}


// Vectors
void testVectorInt(){
    Vector* v = malloc(sizeof(Vector));
    VectorNew(v, sizeof(int), NULL);
    if(VectorSize(v) == 0 && VectorIsEmpty(v)) printf("VectorInt ---size--- |Good|\n");
    else printf("VectorInt ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        VectorPush(v, &i);
        if(VectorSize(v) == i+1) printf("VectorInt ---size--- |Good|\n");
        else printf("VectorInt ---size--- |Bad|\n");
        if(*(int*)VectorGet(v, VectorSize(v)-1) == i) printf("VectorInt ---get--- |Good|\n");
        else printf("VectorInt ---get--- |Bad|\n");
        if(VectorFind(v, intCmpFn, &i, i>1 ? i-1 : 0, 0) == i) printf("VectorInt ---find--- |Good|\n");
        else printf("VectorInt ---find--- |Bad|\n");
    }
    printf("VectorInt ---vectorcapacity--- %d\n", VectorCapacity(v));
    for(int i=0; i<num; i++){
        if(VectorSize(v) == num-i) printf("VectorInt ---size--- |Good|\n");
        else printf("VectorInt ---size--- |Bad|\n");
        if(*(int*)VectorGet(v, VectorSize(v)-1) == num-i-1) printf("VectorInt ---top--- |Good|\n");
        else printf("VectorInt ---top--- |Bad|\n");
        VectorPop(v);
    }
    if(VectorSize(v) == 0) printf("VectorInt ---size--- |Good|\n");
    else printf("VectorInt ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        VectorUnshift(v, &i);
        if(VectorSize(v) == i+1) printf("VectorInt ---size--- |Good|\n");
        else printf("VectorInt ---size--- |Bad|\n");
        if(*(int*)VectorGet(v, 0) == i) printf("VectorInt ---get--- |Good|\n");
        else printf("VectorInt ---get--- |Bad|\n");
    }
    printf("VectorInt ---vectorcapacity--- %d\n", VectorCapacity(v));
    for(int i=0; i<num; i++){
        if(VectorSize(v) == num-i) printf("VectorInt ---size--- |Good|\n");
        else printf("VectorInt ---size--- |Bad|\n");
        if(*(int*)VectorGet(v, 0) == num-i-1) printf("VectorInt ---top--- |Good|\n");
        else printf("VectorInt ---top--- |Bad|\n");
        VectorShift(v);
    }
    for(int i=0; i<num; i++){
        VectorUnshift(v, &i);
    }
    VectorSort(v, structCmpFn);
    int isSorted = 1;
    for(int i=0; i<num; i++){
        if(*(int*)VectorGet(v, i) != i){
            isSorted = 0;
            break;
        }
    }
    if(isSorted) printf("VectorInt ---sorted--- |Good|\n");
    else printf("VectorInt ---sorted--- |Bad|\n");
    for(int i=0; i<num; i++){
        if(VectorFind(v, intCmpFn, &i, i/2, 1) == i) printf("VectorInt ---find--- |Good|\n");
        else printf("VectorInt ---find--- |Bad|\n");
    }
    VectorDestroy(v);
    free(v);
}

void testVectorChar(){
    Vector* v = malloc(sizeof(Vector));
    VectorNew(v, sizeof(char*), NULL);
    if(VectorSize(v) == 0 && VectorIsEmpty(v)) printf("VectorChar ---size--- |Good|\n");
    else printf("VectorChar ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        VectorPush(v, &txt);
        if(VectorSize(v) == i+1) printf("VectorChar ---size--- |Good|\n");
        else printf("VectorChar ---size--- |Bad|\n");
        if(strcmp(*(char**)VectorGet(v, VectorSize(v)-1), txt) == 0) printf("VectorChar ---get--- |Good|\n");
        else printf("VectorChar ---get--- |Bad|\n");
    }
    printf("VectorChar ---vectorcapacity--- %d\n", VectorCapacity(v));
    for(int i=0; i<num; i++){
        if(VectorSize(v) == num-i) printf("VectorChar ---size--- |Good|\n");
        else printf("VectorChar ---size--- |Bad|\n");
        if(strcmp(*(char**)VectorGet(v, VectorSize(v)-1), txt) == 0) printf("VectorChar ---top--- |Good|\n");
        else printf("VectorChar ---top--- |Bad|\n");
        VectorPop(v);
    }
    if(VectorSize(v) == 0) printf("VectorChar ---size--- |Good|\n");
    else printf("VectorChar ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        VectorUnshift(v, &txt);
        if(VectorSize(v) == i+1) printf("VectorChar ---size--- |Good|\n");
        else printf("VectorChar ---size--- |Bad|\n");
        if(strcmp(*(char**)VectorGet(v, 0), txt) == 0) printf("VectorChar ---get--- |Good|\n");
        else printf("VectorChar ---get--- |Bad|\n");
    }
    printf("VectorChar ---vectorcapacity--- %d\n", VectorCapacity(v));
    for(int i=0; i<num; i++){
        if(VectorSize(v) == num-i) printf("VectorChar ---size--- |Good|\n");
        else printf("VectorChar ---size--- |Bad|\n");
        if(strcmp(*(char**)VectorGet(v, 0), txt) == 0) printf("VectorChar ---top--- |Good|\n");
        else printf("VectorChar ---top--- |Bad|\n");
        VectorShift(v);
    }
    VectorDestroy(v);
    free(v);
}

void testVectorStruct(){
    Vector* v = malloc(sizeof(Vector));
    VectorNew(v, sizeof(tt), StructFreeFn);
    if(VectorSize(v) == 0 && VectorIsEmpty(v)) printf("VectorStruct ---size--- |Good|\n");
    else printf("VectorStruct ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        allocStruct();
        VectorPush(v, strtt);
        if(VectorSize(v) == i+1) printf("VectorStruct ---size--- |Good|\n");
        else printf("VectorStruct ---size--- |Bad|\n");
        if(structCmp(VectorGet(v, VectorSize(v)-1), strtt) == 0) printf("VectorStruct ---get--- |Good|\n");
        else printf("VectorStruct ---get--- |Bad|\n");
    }
    printf("VectorStruct ---vectorcapacity--- %d\n", VectorCapacity(v));
    for(int i=0; i<num; i++){
        if(VectorSize(v) == num-i) printf("VectorStruct ---size--- |Good|\n");
        else printf("VectorStruct ---size--- |Bad|\n");
        if(structCmp(VectorGet(v, VectorSize(v)-1), strtt) == 0) printf("VectorStruct ---top--- |Good|\n");
        else printf("VectorStruct ---top--- |Bad|\n");
        VectorPop(v);
    }
    if(VectorSize(v) == 0) printf("VectorStruct ---size--- |Good|\n");
    else printf("VectorStruct ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        allocStruct();
        VectorUnshift(v, strtt);
        if(VectorSize(v) == i+1) printf("VectorStruct ---size--- |Good|\n");
        else printf("VectorStruct ---size--- |Bad|\n");
        if(structCmp(VectorGet(v, 0), strtt) == 0) printf("VectorStruct ---get--- |Good|\n");
        else printf("VectorStruct ---get--- |Bad|\n");
    }
    printf("VectorStruct ---vectorcapacity--- %d\n", VectorCapacity(v));
    for(int i=0; i<num; i++){
        if(VectorSize(v) == num-i) printf("VectorStruct ---size--- |Good|\n");
        else printf("VectorStruct ---size--- |Bad|\n");
        if(structCmp(VectorGet(v, 0), strtt) == 0) printf("VectorStruct ---top--- |Good|\n");
        else printf("VectorStruct ---top--- |Bad|\n");
        VectorShift(v);
    }
    VectorDestroy(v);
    free(v);
}


// linked-list-generics
void testLinkedListGenericInt(){
    LinkedListGeneric* ll = malloc(sizeof(ll));
    LinkedListGenericNew(ll);
    if(LinkedListGenericSize(ll) == 0 && LinkedListGenericIsEmpty(ll)) printf("LinkedListGenericInt ---size--- |Good|\n");
    else printf("LinkedListGenericInt ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        LinkedListGenericPush(ll, &i, sizeof(int), NULL);
        if(LinkedListGenericSize(ll) == i+1) printf("LinkedListGenericInt ---size--- |Good|\n");
        else printf("LinkedListGenericInt ---size--- |Bad|\n");
        if(*(int*)LinkedListGenericGet(ll, LinkedListGenericSize(ll)-1) == i) printf("LinkedListGenericInt ---get--- |Good|\n");
        else printf("LinkedListGenericInt ---get--- |Bad|\n");
        if(LinkedListGenericFind(ll, &i, intCmpFn, i>1 ? i-1 : 0, NULL) == i) printf("LinkedListGenericInt ---find--- |Good|\n");
        else printf("LinkedListGenericInt ---find--- |Bad|\n");
    }
    for(int i=0; i<num; i++){
        if(LinkedListGenericSize(ll) == num-i) printf("LinkedListGenericInt ---size--- |Good|\n");
        else printf("LinkedListGenericInt ---size--- |Bad|\n");
        if(*(int*)LinkedListGenericGet(ll, LinkedListGenericSize(ll)-1) == num-i-1) printf("LinkedListGenericInt ---top--- |Good|\n");
        else printf("LinkedListGenericInt ---top--- |Bad|\n");
        LinkedListGenericPop(ll);
    }
    if(LinkedListGenericSize(ll) == 0) printf("LinkedListGenericInt ---size--- |Good|\n");
    else printf("LinkedListGenericInt ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        LinkedListGenericUnshift(ll, &i, sizeof(int), NULL);
        if(LinkedListGenericSize(ll) == i+1) printf("LinkedListGenericInt ---size--- |Good|\n");
        else printf("LinkedListGenericInt ---size--- |Bad|\n");
        if(*(int*)LinkedListGenericGet(ll, 0) == i) printf("LinkedListGenericInt ---get--- |Good|\n");
        else printf("LinkedListGenericInt ---get--- |Bad|\n");
    }
    for(int i=0; i<num; i++){
        if(LinkedListGenericSize(ll) == num-i) printf("LinkedListGenericInt ---size--- |Good|\n");
        else printf("LinkedListGenericInt ---size--- |Bad|\n");
        if(*(int*)LinkedListGenericGet(ll, 0) == num-i-1) printf("LinkedListGenericInt ---top--- |Good|\n");
        else printf("LinkedListGenericInt ---top--- |Bad|\n");
        LinkedListGenericShift(ll);
    }
    LinkedListGenericDestroy(ll);
    free(ll);
}

void testLinkedListGenericChar(){
    LinkedListGeneric* ll = malloc(sizeof(ll));
    LinkedListGenericNew(ll);
    if(LinkedListGenericSize(ll) == 0 && LinkedListGenericIsEmpty(ll)) printf("LinkedListGenericChar ---size--- |Good|\n");
    else printf("LinkedListGenericChar ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        LinkedListGenericPush(ll, &txt, sizeof(char*), NULL);
        if(LinkedListGenericSize(ll) == i+1) printf("LinkedListGenericChar ---size--- |Good|\n");
        else printf("LinkedListGenericChar ---size--- |Bad|\n");
        if(strcmp(*(char**)LinkedListGenericGet(ll, LinkedListGenericSize(ll)-1), txt) == 0) printf("LinkedListGenericChar ---get--- |Good|\n");
        else printf("LinkedListGenericChar ---get--- |Bad|\n");
    }
    for(int i=0; i<num; i++){
        if(LinkedListGenericSize(ll) == num-i) printf("LinkedListGenericChar ---size--- |Good|\n");
        else printf("LinkedListGenericChar ---size--- |Bad|\n");
        if(strcmp(*(char**)LinkedListGenericGet(ll, LinkedListGenericSize(ll)-1), txt) == 0) printf("LinkedListGenericChar ---top--- |Good|\n");
        else printf("LinkedListGenericChar ---top--- |Bad|\n");
        LinkedListGenericPop(ll);
    }
    if(LinkedListGenericSize(ll) == 0) printf("LinkedListGenericChar ---size--- |Good|\n");
    else printf("LinkedListGenericChar ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        LinkedListGenericUnshift(ll, &txt, sizeof(char*), NULL);
        if(LinkedListGenericSize(ll) == i+1) printf("LinkedListGenericChar ---size--- |Good|\n");
        else printf("LinkedListGenericChar ---size--- |Bad|\n");
        if(strcmp(*(char**)LinkedListGenericGet(ll, 0), txt) == 0) printf("LinkedListGenericChar ---get--- |Good|\n");
        else printf("LinkedListGenericChar ---get--- |Bad|\n");
    }
    for(int i=0; i<num; i++){
        if(LinkedListGenericSize(ll) == num-i) printf("LinkedListGenericChar ---size--- |Good|\n");
        else printf("LinkedListGenericChar ---size--- |Bad|\n");
        if(strcmp(*(char**)LinkedListGenericGet(ll, 0), txt) == 0) printf("LinkedListGenericChar ---top--- |Good|\n");
        else printf("LinkedListGenericChar ---top--- |Bad|\n");
        LinkedListGenericShift(ll);
    }
    LinkedListGenericDestroy(ll);
    free(ll);
}

void testLinkedListGenericStruct(){
    LinkedListGeneric* ll = malloc(sizeof(ll));
    LinkedListGenericNew(ll);
    if(LinkedListGenericSize(ll) == 0 && LinkedListGenericIsEmpty(ll)) printf("LinkedListGenericStruct ---size--- |Good|\n");
    else printf("LinkedListGenericStruct ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        allocStruct();
        LinkedListGenericPush(ll, strtt, sizeof(tt), StructFreeFn);
        if(LinkedListGenericSize(ll) == i+1) printf("LinkedListGenericStruct ---size--- |Good|\n");
        else printf("LinkedListGenericStruct ---size--- |Bad|\n");
        if(structCmp(LinkedListGenericGet(ll, LinkedListGenericSize(ll)-1), strtt) == 0) printf("LinkedListGenericStruct ---get--- |Good|\n");
        else printf("LinkedListGenericStruct ---get--- |Bad|\n");
    }
    for(int i=0; i<num; i++){
        if(LinkedListGenericSize(ll) == num-i) printf("LinkedListGenericStruct ---size--- |Good|\n");
        else printf("LinkedListGenericStruct ---size--- |Bad|\n");
        if(structCmp(LinkedListGenericGet(ll, LinkedListGenericSize(ll)-1), strtt) == 0) printf("LinkedListGenericStruct ---top--- |Good|\n");
        else printf("LinkedListGenericStruct ---top--- |Bad|\n");
        LinkedListGenericPop(ll);
    }
    if(LinkedListGenericSize(ll) == 0) printf("LinkedListGenericStruct ---size--- |Good|\n");
    else printf("LinkedListGenericStruct ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        allocStruct();
        LinkedListGenericUnshift(ll, strtt, sizeof(tt), StructFreeFn);
        if(LinkedListGenericSize(ll) == i+1) printf("LinkedListGenericStruct ---size--- |Good|\n");
        else printf("LinkedListGenericStruct ---size--- |Bad|\n");
        if(structCmp(LinkedListGenericGet(ll, 0), strtt) == 0) printf("LinkedListGenericStruct ---get--- |Good|\n");
        else printf("LinkedListGenericStruct ---get--- |Bad|\n");
    }
    for(int i=0; i<num; i++){
        if(LinkedListGenericSize(ll) == num-i) printf("LinkedListGenericStruct ---size--- |Good|\n");
        else printf("LinkedListGenericStruct ---size--- |Bad|\n");
        if(structCmp(LinkedListGenericGet(ll, 0), strtt) == 0) printf("LinkedListGenericStruct ---top--- |Good|\n");
        else printf("LinkedListGenericStruct ---top--- |Bad|\n");
        LinkedListGenericShift(ll);
    }
    LinkedListGenericDestroy(ll);
    free(ll);
}


// linked-list
void testLinkedListInt(){
    LinkedList* ll = malloc(sizeof(ll));
    LinkedListNew(ll, sizeof(int), NULL);
    if(LinkedListSize(ll) == 0 && LinkedListIsEmpty(ll)) printf("LinkedListInt ---size--- |Good|\n");
    else printf("LinkedListInt ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        LinkedListPush(ll, &i);
        if(LinkedListSize(ll) == i+1) printf("LinkedListInt ---size--- |Good|\n");
        else printf("LinkedListInt ---size--- |Bad|\n");
        if(*(int*)LinkedListGet(ll, LinkedListSize(ll)-1) == i) printf("LinkedListInt ---get--- |Good|\n");
        else printf("LinkedListInt ---get--- |Bad|\n");
    }
    for(int i=0; i<num; i++){
        if(LinkedListSize(ll) == num-i) printf("LinkedListInt ---size--- |Good|\n");
        else printf("LinkedListInt ---size--- |Bad|\n");
        if(*(int*)LinkedListGet(ll, LinkedListSize(ll)-1) == num-i-1) printf("LinkedListInt ---top--- |Good|\n");
        else printf("LinkedListInt ---top--- |Bad|\n");
        LinkedListPop(ll);
    }
    if(LinkedListSize(ll) == 0) printf("LinkedListInt ---size--- |Good|\n");
    else printf("LinkedListInt ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        LinkedListUnshift(ll, &i);
        if(LinkedListSize(ll) == i+1) printf("LinkedListInt ---size--- |Good|\n");
        else printf("LinkedListInt ---size--- |Bad|\n");
        if(*(int*)LinkedListGet(ll, 0) == i) printf("LinkedListInt ---get--- |Good|\n");
        else printf("LinkedListInt ---get--- |Bad|\n");
    }
    for(int i=0; i<num; i++){
        if(LinkedListSize(ll) == num-i) printf("LinkedListInt ---size--- |Good|\n");
        else printf("LinkedListInt ---size--- |Bad|\n");
        if(*(int*)LinkedListGet(ll, 0) == num-i-1) printf("LinkedListInt ---top--- |Good|\n");
        else printf("LinkedListInt ---top--- |Bad|\n");
        LinkedListShift(ll);
    }
    LinkedListDestroy(ll);
    free(ll);
}


void testLinkedListChar(){
    LinkedList* ll = malloc(sizeof(ll));
    LinkedListNew(ll, sizeof(char*), NULL);
    if(LinkedListSize(ll) == 0 && LinkedListIsEmpty(ll)) printf("LinkedListChar ---size--- |Good|\n");
    else printf("LinkedListChar ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        LinkedListPush(ll, &txt);
        if(LinkedListSize(ll) == i+1) printf("LinkedListChar ---size--- |Good|\n");
        else printf("LinkedListChar ---size--- |Bad|\n");
        if(strcmp(*(char**)LinkedListGet(ll, LinkedListSize(ll)-1), txt) == 0) printf("LinkedListChar ---get--- |Good|\n");
        else printf("LinkedListChar ---get--- |Bad|\n");
    }
    for(int i=0; i<num; i++){
        if(LinkedListSize(ll) == num-i) printf("LinkedListChar ---size--- |Good|\n");
        else printf("LinkedListChar ---size--- |Bad|\n");
        if(strcmp(*(char**)LinkedListGet(ll, LinkedListSize(ll)-1), txt) == 0) printf("LinkedListChar ---top--- |Good|\n");
        else printf("LinkedListChar ---top--- |Bad|\n");
        LinkedListPop(ll);
    }
    if(LinkedListSize(ll) == 0) printf("LinkedListChar ---size--- |Good|\n");
    else printf("LinkedListChar ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        LinkedListUnshift(ll, &txt);
        if(LinkedListSize(ll) == i+1) printf("LinkedListChar ---size--- |Good|\n");
        else printf("LinkedListChar ---size--- |Bad|\n");
        if(strcmp(*(char**)LinkedListGet(ll, 0), txt) == 0) printf("LinkedListChar ---get--- |Good|\n");
        else printf("LinkedListChar ---get--- |Bad|\n");
    }
    for(int i=0; i<num; i++){
        if(LinkedListSize(ll) == num-i) printf("LinkedListChar ---size--- |Good|\n");
        else printf("LinkedListChar ---size--- |Bad|\n");
        if(strcmp(*(char**)LinkedListGet(ll, 0), txt) == 0) printf("LinkedListChar ---top--- |Good|\n");
        else printf("LinkedListChar ---top--- |Bad|\n");
        LinkedListShift(ll);
    }
    LinkedListDestroy(ll);
    free(ll);
}


void testLinkedListStruct(){
    LinkedList* ll = malloc(sizeof(ll));
    LinkedListNew(ll, sizeof(tt), StructFreeFn);
    if(LinkedListSize(ll) == 0 && LinkedListIsEmpty(ll)) printf("LinkedListStruct ---size--- |Good|\n");
    else printf("LinkedListStruct ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        allocStruct();
        LinkedListPush(ll, strtt);
        if(LinkedListSize(ll) == i+1) printf("LinkedListStruct ---size--- |Good|\n");
        else printf("LinkedListStruct ---size--- |Bad|\n");
        if(structCmp(LinkedListGet(ll, LinkedListSize(ll)-1), strtt) == 0) printf("LinkedListStruct ---get--- |Good|\n");
        else printf("LinkedListStruct ---get--- |Bad|\n");
    }
    for(int i=0; i<num; i++){
        if(LinkedListSize(ll) == num-i) printf("LinkedListStruct ---size--- |Good|\n");
        else printf("LinkedListStruct ---size--- |Bad|\n");
        if(structCmp(LinkedListGet(ll, LinkedListSize(ll)-1), strtt) == 0) printf("LinkedListStruct ---top--- |Good|\n");
        else printf("LinkedListStruct ---top--- |Bad|\n");
        LinkedListPop(ll);
    }
    if(LinkedListSize(ll) == 0) printf("LinkedListStruct ---size--- |Good|\n");
    else printf("LinkedListStruct ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        allocStruct();
        LinkedListUnshift(ll, strtt);
        if(LinkedListSize(ll) == i+1) printf("LinkedListStruct ---size--- |Good|\n");
        else printf("LinkedListStruct ---size--- |Bad|\n");
        if(structCmp(LinkedListGet(ll, 0), strtt) == 0) printf("LinkedListStruct ---get--- |Good|\n");
        else printf("LinkedListStruct ---get--- |Bad|\n");
    }
    for(int i=0; i<num; i++){
        if(LinkedListSize(ll) == num-i) printf("LinkedListStruct ---size--- |Good|\n");
        else printf("LinkedListStruct ---size--- |Bad|\n");
        if(structCmp(LinkedListGet(ll, 0), strtt) == 0) printf("LinkedListStruct ---top--- |Good|\n");
        else printf("LinkedListStruct ---top--- |Bad|\n");
        LinkedListShift(ll);
    }
    LinkedListDestroy(ll);
    free(ll);
}


