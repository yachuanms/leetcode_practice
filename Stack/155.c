#include <stdio.h>
#include <stdlib.h>

typedef struct {
    // you define fields
    int capacity;
    int* data;
    int* minData;

    int top;
    int minTop;

} MinStack;

static void ensureCapacity(MinStack* obj){
    if(obj->top+1 < obj->capacity){
        return;
    }

    int newCapa = obj->capacity *2;
    int* newData = realloc(obj-> data, sizeof(int)*newCapa);
    int* newMin = realloc(obj->minData, sizeof(int)*newCapa);

    obj->data = newData;
    obj->minData = newMin;
    obj->capacity = newCapa;
}

MinStack* minStackCreate(){
    MinStack* stack = malloc(sizeof(MinStack));

    stack -> capacity = 20;
    stack -> top = -1;
    stack -> minTop = -1;

    stack -> data = malloc(sizeof(int)*stack ->capacity);
    stack -> minData = malloc(sizeof(int)* stack->capacity);

    return stack;
}
void minStackPush(MinStack* obj, int val){
    ensureCapacity(obj);

    obj->data[++obj->top] = val;
    if(obj->minTop == -1){
        obj->minData[++obj->minTop] = val;
    }
    else{
        int preMin = obj->minData[obj->minTop];
        obj->minData[++obj->minTop] = (val < preMin)?val:preMin;
    }
    
}

void minStackPop(MinStack* obj){
    //if (obj->top < 0) return;
    obj->top--;
    obj->minTop--;
}

int minStackTop(MinStack* obj){
    //if (obj->top < 0) return 0;
    return obj->data[obj->top];
}
int minStackGetMin(MinStack* obj){
    //if (obj->top < 0) return 0;
    return obj->minData[obj->minTop];
}
void minStackFree(MinStack* obj){
    free(obj->data);
    free(obj->minData);
    free(obj);
}

int main() {
    MinStack* st = minStackCreate();

    minStackPush(st, -2);
    minStackPush(st, 0);
    minStackPush(st, -3);
    printf("getMin: %d\n", minStackGetMin(st)); // 預期 -3

    minStackPop(st);
    printf("top: %d\n", minStackTop(st));       // 預期 0
    printf("getMin: %d\n", minStackGetMin(st)); // 預期 -2

    minStackFree(st);
    return 0;
}
