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
} tt;

int num = 100;
char* txt = "abcde-!@#$^&*()+zxc";
tt* strtt;

void allocStruct(){
    strtt = malloc(sizeof(tt));
    strtt->a = 5;
    strtt->b = &(strtt->a);
    strtt->c = 'a';
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
    testStack();
    // testQueue();
    // testVector();
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
    testVectorChar();
    testVectorStruct();
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
        StackPop(s);
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
        StackPop(s);
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
        StackPop(s);
        if(StackSize(s) == num-1-i) printf("StackStruct ---size--- |Good|\n");
        else printf("StackStruct ---size--- |Bad|\n");
        if(StackTop(s) == NULL || structCmp(StackTop(s), strtt) == 0) printf("StackStruct ---top--- |Good|\n");
        else printf("StackStruct ---top--- |Bad|\n");
    }
    StackDestroy(s);
}


// Queues
void testQueueInt(){

}

void testQueueChar(){

}

void testQueueStruct(){

}


// Vectors
void testVectorInt(){

}

void testVectorChar(){

}

void testVectorStruct(){

}


// Linked-Lists
void testLinkedListInt(){

}

void testLinkedListChar(){

}

void testLinkedListStruct(){

}