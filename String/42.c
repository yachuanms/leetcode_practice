#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){
    return (a<b)?a:b;
}

// 你要自己實作這個函式
int trap(int* height, int heightSize){
    int *leftMax = malloc(sizeof(int)*heightSize);
    int *rightMax = malloc(sizeof(int)*heightSize);
    leftMax[0] = 0;
    rightMax[0] = 0;
    for(int i = 0; i < heightSize; i++){
        if(height[i] > leftMax[i-1]){
            leftMax[i] = height[i];
        }
        if(height[heightSize-i]>rightMax[i-1]){
            rightMax[i] = height[heightSize-i];
        }
    }
    int area = 0;
    int sum = 0;
    for(int i = 0; i < heightSize; i++){
        area +=min(leftMax[i], rightMax[heightSize-i])-height[i];
        if(area > 0){
            sum += area;
        }
    }
    return sum;
}

int main() {
    int h1[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n1 = sizeof(h1) / sizeof(h1[0]);
    printf("Test 1: %d\n", trap(h1, n1));  // 預期 6

    int h2[] = {4,2,0,3,2,5};
    int n2 = sizeof(h2) / sizeof(h2[0]);
    printf("Test 2: %d\n", trap(h2, n2));  // 預期 9

    int h3[] = {1,0,2};
    int n3 = sizeof(h3) / sizeof(h3[0]);
    printf("Test 3: %d\n", trap(h3, n3));  // 預期 1

    int h4[] = {5,4,1,2};
    int n4 = sizeof(h4) / sizeof(h4[0]);
    printf("Test 4: %d\n", trap(h4, n4));  // 預期 1

    return 0;
}
