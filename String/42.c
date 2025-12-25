#include <stdio.h>
#include <stdlib.h>

//two pointer

int trap(int* height, int heightSize){
    if(heightSize < 3) return 0;
    int leftMax = height[0];
    int rightMax = height[heightSize-1];
    int l = 0;
    int r = heightSize-1;
    int sum = 0;
    while(l < r){
        if(height[l] < height[r]){
            if(height[l] > leftMax){
                leftMax = height[l];
            }else{
                sum += leftMax - height[l];
            }
            l++;
        }else{
            if(height[r] > rightMax){
                rightMax = height[r];
            }else{
                sum += rightMax - height[r];
            }
            r--;
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
