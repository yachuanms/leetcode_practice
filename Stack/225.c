#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
//Implement stack using queue

typedef struct {
    int arr[100];
    int head;   // index of front element
    int size;   // current number of elements
    int cap;    // capacity (100)
} MyStack;

MyStack* myStackCreate() {
    MyStack* s = (MyStack*)malloc(sizeof(MyStack));
    s->head = 0;
    s->size = 0;
    s->cap = 100;
    return s;
}

// enqueue to the queue (at tail)
void enqueue(MyStack* obj, int x) {
    int idx = (obj->head + obj->size) % obj->cap;
    obj->arr[idx] = x;
    obj->size++;
}

// dequeue from the queue (from head)
int dequeue(MyStack* obj) {
    int val = obj->arr[obj->head];
    obj->head = (obj->head + 1) % obj->cap;
    obj->size--;
    return val;
}

void myStackPush(MyStack* obj, int x) {
    // enqueue new element
    enqueue(obj, x);
    // rotate the previous elements: move size-1 elements from front to back
    int n = obj->size - 1; // number of old elements to move
    for (int i = 0; i < n; ++i) {
        int t = dequeue(obj);
        enqueue(obj, t);
    }
}

int myStackPop(MyStack* obj) {
    // pop = dequeue (front holds the stack's top after push-rotation)
    if (obj->size == 0) return -1; // or undefined behavior per LeetCode
    return dequeue(obj);
}

int myStackTop(MyStack* obj) {
    if (obj->size == 0) return -1;
    return obj->arr[obj->head];
}

bool myStackEmpty(MyStack* obj) {
    return obj->size == 0;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/*
我寫的雖然是對的 但不是題目想要的樣子
typedef struct {
    int queue1[100];
    int head;
    int tail;
} MyStack;


MyStack* myStackCreate() {
    MyStack* s = (MyStack*)malloc(sizeof(MyStack));
    s->head = -1;
    s->tail = -1;
    return s;
}

void myStackPush(MyStack* obj, int x) {
    obj->queue1[++obj->tail] = x;  // enqueue x
    int n = obj->tail - obj->head; // 原本的元素數量
    for(int i = 0; i < n; i++){
        int temp = obj->queue1[++obj->head];   // dequeue
        obj->queue1[++obj->tail] = temp;       // enqueue 回去
    }
}
int myStackPop(MyStack* obj) {
    return obj->queue1[++obj->head]; // dequeue
}
int myStackTop(MyStack* obj) {
    return obj->queue1[obj->head+1];
}

bool myStackEmpty(MyStack* obj) {
    if(obj->head  > obj->tail || ((obj->head == -1) && obj->tail == -1)){
        return true;
    }
    return false;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

void myStackPush(MyStack* obj, int x) {
    obj->queue1[++obj->tail] = x;
    if(obj->head == -1){
        obj->head++;
    }
    
    int n = obj->tail-obj->head+1;
    for(int i = 0; i < n; i++){
        int temp = obj->queue1[obj->head++];//從頭拿出來
        obj->queue1[++obj->tail] = temp;//再放回尾巴
    }
    
}

int myStackPop(MyStack* obj) {
    int result = obj->queue1[obj->tail--];
    return result;

}

int myStackTop(MyStack* obj) {
    return obj->queue1[obj->tail];
}

bool myStackEmpty(MyStack* obj) {
    if(obj->head  > obj->tail || ((obj->head == -1) && obj->tail == -1)){
        return true;
    }
    return false;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

*/

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/

int main() {
    MyStack* st = myStackCreate();

    myStackPush(st, 1);
    myStackPush(st, 2);
    myStackPush(st, 3);

    printf("Top: %d  (3)\n", myStackTop(st));   // 應該是 3
    printf("Pop: %d  (3)\n", myStackPop(st));   // 應該是 3

    printf("Top: %d  (2)\n", myStackTop(st));   // 應該是 2
    printf("Empty? %s   (false)\n", myStackEmpty(st) ? "true" : "false"); // 應該是 false

    printf("Pop: %d  (2)\n", myStackPop(st));   // 應該是 2
    printf("Pop: %d  (1)\n", myStackPop(st));   // 應該是 1
    printf("Empty? %s   (false)\n", myStackEmpty(st) ? "true" : "false"); // 應該是 true

    myStackFree(st);
    return 0;
}
