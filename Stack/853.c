#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    int speed;
} Car;

static int cmpCarByPos(const void* a, const void* b) {
    const Car* x = (const Car*)a;
    const Car* y = (const Car*)b;
    //寫排序規則（pos 由小到大）
    if(x->pos > y->pos) return 1;
    if(x->pos < y->pos) return -1;
    return 0;
}

/*
LeetCode signature:
int carFleet(int target, int* position, int positionSize, int* speed, int speedSize);
*/
int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    if(positionSize <= 0){
        return 0;
    }

    Car* line = malloc(sizeof(Car)*positionSize);
    for(int i = 0 ; i < positionSize; i++){
        line[i].pos = position[i];
        line[i].speed = speed[i];
    }
    //先照position 排序
    qsort(line, positionSize, sizeof(Car), cmpCarByPos);

    //從最靠近target的開始看
    double preTime = (double)(line[positionSize-1].pos-target)/line[positionSize-1].speed;
    int count = 1;

    for(int i = positionSize-2; i >= 0; i--){
        double time = (double)(line[i].pos-target)/line[i].speed;
        //開到終點比前車慢 --> 新fleet
        if(time < preTime){
            count++;
            preTime = time;
        }
    }

    free(line);
    return count;
}

/*************** 本機測試 main（LeetCode 交作業時刪掉 main） ***************/
static void test(int target, int* position, int n, int* speed) {
    int ans = carFleet(target, position, n, speed, n);
    printf("ans = %d\n", ans);
}

int main() {
    // Example 1
    int pos1[] = {10, 8, 0, 5, 3};
    int spd1[] = { 2, 4, 1, 1, 3};
    printf("expect 3 -> ");
    test(12, pos1, 5, spd1);

    // Example 2
    int pos2[] = {3};
    int spd2[] = {3};
    printf("expect 1 -> ");
    test(10, pos2, 1, spd2);

    // Example 3
    int pos3[] = {0, 2, 4};
    int spd3[] = {4, 2, 1};
    printf("expect 1 -> ");
    test(100, pos3, 3, spd3);

    return 0;
}
