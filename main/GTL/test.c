#include <stdio.h>
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
    testStack();
    testQueue();
    testVector();
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

void testLinkedList(){
    testLinkedListInt();
    testLinkedListChar();
    testLinkedListStruct();
}

// Stacks
void testStackInt(){
    Stack* s;
    StackNew(&s, sizeof(int));
    if(StackSize(s) == 0 && StackIsEmpty(s)) printf("StackInt ---size--- |Good|\n");
    else printf("StackInt ---size--- |Bad|\n");
    for(int i=0; i<10000; i++){
        StackPush(s, &i);
        if(StackSize(s) == i+1) printf("StackInt ---size--- |Good|\n");
        else printf("StackInt ---size--- |Bad|\n");
        if(*(int*)StackTop(s) == i) printf("StackInt ---top--- |Good|\n");
        else printf("StackInt ---top--- |Bad|\n");
    }
    printf("StackInt ---stackcapacity--- %d\n", StackCapacity(s));
    for(int i=0; i<10000; i++){
        StackPop(s);
        if(StackSize(s) == 999-i) printf("StackInt ---size--- |Good|\n");
        else printf("StackInt ---size--- |Bad|\n");
        if(*(int*)StackTop(s) == 998-i) printf("StackInt ---top--- |Good|\n");
        else printf("StackInt ---top--- |Bad|\n");
    }
    StackDestroy(s);
}

void testStackChar(){

}

void testStackStruct(){

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