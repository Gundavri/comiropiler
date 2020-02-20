#include <stdio.h>
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
    // testQueue();
    // testVector();
    // testLinkedList();
    return 0;
}


void testStack() {
    // testStackInt();
    testStackChar();
    // testStackStruct();
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
    int num = 10000;
    Stack* s;
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
        if(StackTop(s) == NULL || *(int*)StackTop(s) == num-2-i) printf("StackInt ---top--- |Good|\n");
        else printf("StackInt ---top--- |Bad|\n");
        if(StackSize(s) == num-1-i) printf("StackInt ---size--- |Good|\n");
        else printf("StackInt ---size--- |Bad|\n");
    }
    StackDestroy(s);
}

void testStackChar(){
    int num = 10;
    char* c = "blaaaa";
    printf("%s %d\n", c, sizeof(char*));
    Stack* s;
    StackNew(s, 8, NULL);
    // if(StackSize(s) == 0 && StackIsEmpty(s)) printf("StackChar ---size--- |Good|\n");
    // else printf("StackChar ---size--- |Bad|\n");
    // for(int i=0; i<num; i++){
    //     StackPush(s, &c);
    //     if(StackSize(s) == i+1) printf("StackChar ---size--- |Good|\n");
    //     else printf("StackChar ---size--- |Bad|\n");
    //     if(strcmp(*(char**)StackTop(s),c) == 0) printf("StackChar ---top--- |Good|\n");
    //     else printf("StackChar ---top--- |Bad|\n");
    // }
    // printf("StackChar ---stackcapacity--- %d\n", StackCapacity(s));
    // for(int i=0; i<num; i++){
    //     StackPop(s);
    //     if(strcmp(*(char**)StackTop(s),c) == 0) printf("StackChar ---top--- |Good|\n");
    //     else printf("StackChar ---top--- |Bad|\n");
    //     if(StackSize(s) == num-1-i) printf("StackChar ---size--- |Good|\n");
    //     else printf("StackChar ---size--- |Bad|\n");
    // }
    // StackDestroy(s);
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