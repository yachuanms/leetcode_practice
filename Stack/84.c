#include <stdio.h>
#include <stdlib.h>

//為什麼 stack 要遞增？
//什麼時候 pop？
//pop 的那一刻，左右邊界各是誰？

int largestRectangleArea(int* heights, int heightsSize) {
    int stack[heightsSize];
    int top = -1;
    int max = 0;

    //stack 存遞增的index
    //若遇到更矮的柱子 代表stack[top]沒辦法再擴增了
    //所以要pop出來算高度
    for(int i = 0; i < heightsSize; i++){
        while(top >= 0 && heights[stack[top]] > heights[i]){
            int height = heights[stack[top--]];
            //若top== -1 代表前面沒有更矮的柱子 所以寬度是i (前面柱子都更矮可以被算進長方形)
            //若top!= -1 就算到上一個比他矮的柱子後一個 所以是i - (stack[top]+1)
            int width = (top == -1)?i:(i-stack[top]-1);
            int area = height * width;
            max = (area > max)? area:max;
        }
        //
        stack[++top] = i;
    }

    //把stack中剩下的index算完
    while(top >= 0){
        int height = heights[stack[top--]];
        int width = (top == -1)?heightsSize:(heightsSize-stack[top]-1);
        int area = height * width;
        max = (area > max)? area:max;
    }

    return max;
}


static void runTest(int* a, int n, int expect) {
    int ans = largestRectangleArea(a, n);
    printf("ans=%d expect=%d %s\n", ans, expect, (ans==expect) ? "OK" : "WRONG");
}

int main() {
    int a1[] = {2,1,5,6,2,3};
    runTest(a1, 6, 10);

    int a2[] = {2,4};
    runTest(a2, 2, 4);

    int a3[] = {2,1,2};
    runTest(a3, 3, 3);

    int a4[] = {1,1,1,1};
    runTest(a4, 4, 4);

    int a5[] = {5,4,3,2,1};
    runTest(a5, 5, 9);

    return 0;
}
