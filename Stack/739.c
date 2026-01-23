#include <stdio.h>
#include <stdlib.h>

/*
LeetCode signature:
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize);
*/
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {

    if(temperaturesSize <= 1){
        *returnSize = temperaturesSize;
        int* ans = malloc(sizeof(int));
        ans[0] = 0;
        return ans;
    }

    //stack 存還沒有找到ans值的index
    int stack[temperaturesSize];
    int top = -1;
    int* ans = malloc(sizeof(int)*temperaturesSize);

    for(int i = 0; i < temperaturesSize; i++){
        ans[i] = 0;
        while(top >= 0 && temperatures[i] > temperatures[stack[top]]){
            int j = stack[top--];
            ans[j] = i-j;
        }
        stack[++top] = i;
    }

    *returnSize = temperaturesSize;
    return ans;
}

/*************** 本機測試 main（LeetCode 交作業時刪掉 main） ***************/
static void printArr(int* a, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != n-1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int T1[] = {73,74,75,71,69,72,76,73};
    int n1 = sizeof(T1)/sizeof(T1[0]);
    int returnSize1 = 0;
    int* ans1 = dailyTemperatures(T1, n1, &returnSize1);
    printf("ans1 expect [1,1,4,2,1,1,0,0]\n");
    printArr(ans1, returnSize1);
    free(ans1);

    int T2[] = {30,40,50,60};
    int n2 = sizeof(T2)/sizeof(T2[0]);
    int returnSize2 = 0;
    int* ans2 = dailyTemperatures(T2, n2, &returnSize2);
    printf("ans2 expect [1,1,1,0]\n");
    printArr(ans2, returnSize2);
    free(ans2);

    int T3[] = {30,60,90};
    int n3 = sizeof(T3)/sizeof(T3[0]);
    int returnSize3 = 0;
    int* ans3 = dailyTemperatures(T3, n3, &returnSize3);
    printf("ans3 expect [1,1,0]\n");
    printArr(ans3, returnSize3);
    free(ans3);

    return 0;
}
