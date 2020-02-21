#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./queue/queue.h"
#include "./stack/stack.h"
#include "./vector/vector.h"
#include "./linked-list/linked-list.h"


typedef struct{
 int a;
 int* b;
 char c;
 char* d;
 int e[3];
 void* f;
} tt;

int num = 10000;
char* txt = "abcde-!@#$^&*()+zxc";
tt* strtt;

void allocStruct(){
    strtt = malloc(sizeof(tt));
    strtt->a = 5;
    strtt->b = malloc(sizeof(int));
    strtt->b = &(strtt->a);
    strtt->c = 'a';
    strtt->d = malloc(sizeof(char));
    strtt->d = &(strtt->c);
    strtt->e[0] = 1;
    strtt->e[1] = 2;
    strtt->e[2] = 3;
}

int structCmp(tt* tt1, tt* tt2){
    if(tt1->a != tt2->a || tt1->b != tt2->b || tt1->c != tt2->c || tt1->d != tt2->d){
        return -1;
    }
    for(int i=0; i<3; i++){
        if(tt1->e[i] != tt2->e[i]) return -1;
    }
    return 0;
}

int compareFn(const void* vp1, const void* vp2){
    int a = *(int*)vp1;
    int b = *(int*)vp2;
    return a-b;
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


void testLinkedList();

void testLinkedListInt();
void testLinkedListChar();
void testLinkedListStruct();


int main(){
    allocStruct();
    // testStack();
    // testQueue();
    testVector();
    // testLinkedList();
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
    // testVectorChar();
    // testVectorStruct();
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
        if(*(int*)StackPop(s) == num-1-i) printf("StackInt ---pop--- |Good|\n");
        else printf("StackInt ---pop--- |Bad|\n");
        if(StackSize(s) == num-1-i) printf("StackInt ---size--- |Good|\n");
        else printf("StackInt ---size--- |Bad|\n");
        if(StackTop(s) == NULL || *(int*)StackTop(s) == num-i-2) printf("StackInt ---top--- |Good|\n");
        else printf("StackInt ---top--- |Bad|\n");
    }
    StackDestroy(s);
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
        if(strcmp(*(char**)StackPop(s), txt) == 0) printf("StackChar ---pop--- |Good|\n");
        else printf("StackChar ---pop--- |Bad|\n");
        if(StackSize(s) == num-1-i) printf("StackChar ---size--- |Good|\n");
        else printf("StackChar ---size--- |Bad|\n");
        if(StackTop(s) == NULL || strcmp(*(char**)StackTop(s), txt) == 0) printf("StackChar ---top--- |Good|\n");
        else printf("StackChar ---top--- |Bad|\n");
    }
    StackDestroy(s);
}

void testStackStruct(){
    Stack* s = malloc(sizeof(Stack));
    StackNew(s, sizeof(tt), NULL);
    if(StackSize(s) == 0 && StackIsEmpty(s)) printf("StackStruct ---size--- |Good|\n");
    else printf("StackStruct ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        StackPush(s, strtt);
        if(StackSize(s) == i+1) printf("StackStruct ---size--- |Good|\n");
        else printf("StackStruct ---size--- |Bad|\n");
        if(structCmp(StackTop(s), strtt) == 0) printf("StackStruct ---top--- |Good|\n");
        else printf("StackStruct ---top--- |Bad|\n");
    }
    printf("StackStruct ---stackcapacity--- %d\n", StackCapacity(s));
    for(int i=0; i<num; i++){
        if(structCmp(StackPop(s), strtt) == 0) printf("StackStruct ---pop--- |Good|\n");
        else printf("StackStruct ---pop--- |Bad|\n");
        if(StackSize(s) == num-1-i) printf("StackStruct ---size--- |Good|\n");
        else printf("StackStruct ---size--- |Bad|\n");
        if(StackTop(s) == NULL || structCmp(StackTop(s), strtt) == 0) printf("StackStruct ---top--- |Good|\n");
        else printf("StackStruct ---top--- |Bad|\n");
    }
    StackDestroy(s);
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
        if(*(int*)QueueDequeue(q) == i) printf("QueueInt ---dequeue--- |Good|\n");
        else printf("QueueInt ---dequeue--- |Bad|\n");
        if(QueueSize(q) == num-1-i) printf("QueueInt ---size--- |Good|\n");
        else printf("QueueInt ---size--- |Bad|\n");
        if(QueueBack(q) == NULL || *(int*)QueueBack(q) == num-1) printf("QueueInt ---back--- |Good|\n");
        else printf("QueueInt ---back--- |Bad|\n");
        if(QueueFront(q) == NULL || *(int*)QueueFront(q) == i+1) printf("QueueInt ---front--- |Good|\n");
        else printf("QueueInt ---front--- |Bad|\n");
    }
    QueueDestroy(q);
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
        if(strcmp(*(char**)QueueDequeue(q), txt) == 0) printf("QueueChar ---dequeue--- |Good|\n");
        else printf("QueueChar ---dequeue--- |Bad|\n");
        if(QueueSize(q) == num-1-i) printf("QueueChar ---size--- |Good|\n");
        else printf("QueueChar ---size--- |Bad|\n");
        if(QueueBack(q) == NULL || strcmp(*(char**)QueueBack(q), txt) == 0) printf("QueueChar ---back--- |Good|\n");
        else printf("QueueChar ---back--- |Bad|\n");
        if(QueueFront(q) == NULL || strcmp(*(char**)QueueFront(q), txt) == 0) printf("QueueChar ---front--- |Good|\n");
        else printf("QueueChar ---front--- |Bad|\n");
    }
    QueueDestroy(q);
}

void testQueueStruct(){
    Queue* q = malloc(sizeof(Queue));
    QueueNew(q, sizeof(tt), NULL);
    if(QueueSize(q) == 0 && QueueIsEmpty(q)) printf("QueueStruct ---size--- |Good|\n");
    else printf("QueueStruct ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
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
        if(structCmp(QueueDequeue(q), strtt) == 0) printf("QueueStruct ---dequeue--- |Good|\n");
        else printf("QueueStruct ---dequeue--- |Bad|\n");
        if(QueueSize(q) == num-1-i) printf("QueueStruct ---size--- |Good|\n");
        else printf("QueueStruct ---size--- |Bad|\n");
        if(QueueBack(q) == NULL || structCmp(QueueBack(q), strtt) == 0) printf("QueueStruct ---back--- |Good|\n");
        else printf("QueueStruct ---back--- |Bad|\n");
        if(QueueFront(q) == NULL || structCmp(QueueFront(q), strtt) == 0) printf("QueueStruct ---front--- |Good|\n");
        else printf("QueueStruct ---front--- |Bad|\n");
    }
    QueueDestroy(q);
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
    }
    printf("VectorInt ---vectorcapacity--- %d\n", VectorCapacity(v));
    for(int i=0; i<num; i++){
        VectorPop(v);
        if(VectorSize(v) == num-1-i) printf("VectorInt ---size--- |Good|\n");
        else printf("VectorInt ---size--- |Bad|\n");
        if(VectorGet(v, VectorSize(v)-1) == NULL || *(int*)VectorGet(v, VectorSize(v)-1) == num-i-2) printf("VectorInt ---top--- |Good|\n");
        else printf("VectorInt ---top--- |Bad|\n");
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
        VectorShift(v);
        if(VectorSize(v) == num-1-i) printf("VectorInt ---size--- |Good|\n");
        else printf("VectorInt ---size--- |Bad|\n");
        if(VectorGet(v, 0) == NULL || *(int*)VectorGet(v, 0) == num-i-2) printf("VectorInt ---top--- |Good|\n");
        else printf("VectorInt ---top--- |Bad|\n");
    }
    for(int i=0; i<num; i++){
        VectorUnshift(v, &i);
    }
    VectorSort(v, compareFn);
    int isSorted = 1;
    for(int i=0; i<num; i++){
        if(*(int*)VectorGet(v, i) != i){
            isSorted = 0;
            break;
        }
    }
    if(isSorted) printf("VectorInt ---sorted--- |Good|\n");
    else printf("VectorInt ---sorted--- |Bad|\n");
    VectorDestroy(v);
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
        VectorPop(v);
        if(VectorSize(v) == num-1-i) printf("VectorChar ---size--- |Good|\n");
        else printf("VectorChar ---size--- |Bad|\n");
        if(VectorGet(v, VectorSize(v)-1) == NULL || strcmp(*(char**)VectorGet(v, VectorSize(v)-1), txt) == 0) printf("VectorChar ---top--- |Good|\n");
        else printf("VectorChar ---top--- |Bad|\n");
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
        VectorShift(v);
        if(VectorSize(v) == num-1-i) printf("VectorChar ---size--- |Good|\n");
        else printf("VectorChar ---size--- |Bad|\n");
        if(VectorGet(v, 0) == NULL || strcmp(*(char**)VectorGet(v, 0), txt) == 0) printf("VectorChar ---top--- |Good|\n");
        else printf("VectorChar ---top--- |Bad|\n");
    }
    VectorDestroy(v);
}

void testVectorStruct(){
    Vector* v = malloc(sizeof(Vector));
    VectorNew(v, sizeof(tt), NULL);
    if(VectorSize(v) == 0 && VectorIsEmpty(v)) printf("VectorStruct ---size--- |Good|\n");
    else printf("VectorStruct ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        VectorPush(v, strtt);
        if(VectorSize(v) == i+1) printf("VectorStruct ---size--- |Good|\n");
        else printf("VectorStruct ---size--- |Bad|\n");
        if(structCmp(VectorGet(v, VectorSize(v)-1), strtt) == 0) printf("VectorStruct ---get--- |Good|\n");
        else printf("VectorStruct ---get--- |Bad|\n");
    }
    printf("VectorStruct ---vectorcapacity--- %d\n", VectorCapacity(v));
    for(int i=0; i<num; i++){
        VectorPop(v);
        if(VectorSize(v) == num-1-i) printf("VectorStruct ---size--- |Good|\n");
        else printf("VectorStruct ---size--- |Bad|\n");
        if(VectorGet(v, VectorSize(v)-1) == NULL || structCmp(VectorGet(v, VectorSize(v)-1), strtt) == 0) printf("VectorStruct ---top--- |Good|\n");
        else printf("VectorStruct ---top--- |Bad|\n");
    }
    if(VectorSize(v) == 0) printf("VectorStruct ---size--- |Good|\n");
    else printf("VectorStruct ---size--- |Bad|\n");
    for(int i=0; i<num; i++){
        VectorUnshift(v, strtt);
        if(VectorSize(v) == i+1) printf("VectorStruct ---size--- |Good|\n");
        else printf("VectorStruct ---size--- |Bad|\n");
        if(structCmp(VectorGet(v, 0), strtt) == 0) printf("VectorStruct ---get--- |Good|\n");
        else printf("VectorStruct ---get--- |Bad|\n");
    }
    printf("VectorStruct ---vectorcapacity--- %d\n", VectorCapacity(v));
    for(int i=0; i<num; i++){
        VectorShift(v);
        if(VectorSize(v) == num-1-i) printf("VectorStruct ---size--- |Good|\n");
        else printf("VectorStruct ---size--- |Bad|\n");
        if(VectorGet(v, 0) == NULL || structCmp(VectorGet(v, 0), strtt) == 0) printf("VectorStruct ---top--- |Good|\n");
        else printf("VectorStruct ---top--- |Bad|\n");
    }
    VectorDestroy(v);
}


// Linked-Lists
void testLinkedListInt(){

}

void testLinkedListChar(){

}

void testLinkedListStruct(){

}