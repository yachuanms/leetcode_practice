#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int price;
    int span;
}Node;

typedef struct {
    Node* stack;
    int capacity;
    int top;
} StockSpanner;

StockSpanner* stockSpannerCreate() {
    StockSpanner* obj = malloc(sizeof(StockSpanner));
    obj->capacity = 20;
    obj->top = -1;

    obj->stack = malloc(sizeof(Node)*obj->capacity);
    return obj;
}

static void ensureCap(StockSpanner* obj){
    if(obj->top +1 < obj-> capacity){
        return;
    }

    obj->capacity *= 2;
    obj->stack = realloc(obj->stack, sizeof(Node)*obj->capacity);
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int span = 1;
    while(obj->top >= 0 && obj->stack[obj->top].price <= price){
        span += obj->stack[obj->top].span;
        obj->top --; //pop
        //不top--直接改值while迴圈會出不來
    }
    ensureCap(obj);
    obj->stack[++obj->top].price = price;
    obj->stack[obj->top].span = span;
    return span;
}


void stockSpannerFree(StockSpanner* obj) {
    free(obj->stack);
    free(obj);
}


int main() {
    StockSpanner* ss = stockSpannerCreate();
    printf("%d (expect 1)\n", stockSpannerNext(ss, 100));
    printf("%d (expect 1)\n", stockSpannerNext(ss, 80));
    printf("%d (expect 1)\n", stockSpannerNext(ss, 60));
    printf("%d (expect 2)\n", stockSpannerNext(ss, 70));
    printf("%d (expect 1)\n", stockSpannerNext(ss, 60));
    printf("%d (expect 4)\n", stockSpannerNext(ss, 75));
    printf("%d (expect 6)\n", stockSpannerNext(ss, 85));
    stockSpannerFree(ss);
    return 0;
}
