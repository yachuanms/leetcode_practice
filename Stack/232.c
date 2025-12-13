#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int stack1[100];
    int stack2[100];
    int top1; //不能直接初始化-1
    int top2;
} MyQueue;

// 建立 queue
MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    q->top1 = -1;
    q->top2 = -1;
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    // TODO: push 實作
    obj->stack1[++obj->top1] = x;
}    

int myQueuePop(MyQueue* obj) {
    // TODO: pop 實作
    if(obj->top2 == -1){
        while(obj->top1 >=0){
            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
        }
    }
    return obj->stack2[obj->top2--];
    
}

int myQueuePeek(MyQueue* obj) {
    // TODO: peek 實作
    if(obj->top2 == -1){
        while(obj->top1 >=0){
            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
        }
    }
    return obj->stack2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->top1 == -1 && obj->top2 == -1);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

// 測試
int main() {
    MyQueue* q = myQueueCreate();

    myQueuePush(q, 1);
    myQueuePush(q, 2);
    myQueuePush(q, 3);

    printf("Peek: %d  (1)\n", myQueuePeek(q));
    printf("Pop: %d  (1)\n", myQueuePop(q));
    printf("Peek: %d   (2)\n", myQueuePeek(q));
    printf("Empty? %s   (false)\n", myQueueEmpty(q) ? "true" : "false");

    printf("Pop: %d   (2)\n", myQueuePop(q));
    printf("Pop: %d   (3)\n", myQueuePop(q));
    printf("Empty? %s   (true)\n", myQueueEmpty(q) ? "true" : "false");

    myQueueFree(q);
    return 0;
}
