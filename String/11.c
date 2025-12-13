#include <stdio.h>

int min(int a, int b){
    return (a<b)?a:b;
}

// 你要自己實作這個函式
int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize-1;
    int maxArea = 0;
    int area = 0;
    while(left < right){
        area = (right-left)*min(height[left], height[right]);
        if(area > maxArea){
            maxArea = area;
        }
        if(height[left]> height[right]){
            right--;
        }
        else{
            left++;
        }
    }

    return maxArea;
}

int main() {
    int h1[] = {1,8,6,2,5,4,8,3,7};
    int n1 = sizeof(h1) / sizeof(h1[0]);
    printf("Test 1: %d\n", maxArea(h1, n1));  // 預期 49

    int h2[] = {3, 6,1};
    int n2 = sizeof(h2) / sizeof(h2[0]);
    printf("Test 2: %d\n", maxArea(h2, n2));  // 預期 3

    int h3[] = {4,3,2,1,4};
    int n3 = sizeof(h3) / sizeof(h3[0]);
    printf("Test 3: %d\n", maxArea(h3, n3));  // 預期 16

    int h4[] = {1,2,1};
    int n4 = sizeof(h4) / sizeof(h4[0]);
    printf("Test 4: %d\n", maxArea(h4, n4));  // 預期 2

    return 0;
}
