#include <stdio.h>
#include <stdlib.h>

int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize-1;
    int ans;
    while(left < right){
        int mid = left + (right-left)/2;
        if(nums[mid]>nums[right]){
            left = mid+1;
        }else{
            //因為mid在右段
            //mid本身有可能是最小值
            //所以不能right = mid-1
            right = mid;
        }
    }
    //最後left會等於right
    //因為一直丟掉沒有min的地方
    //所以最後被包夾的區塊一定有min
    return nums[left];
}

/*************** 本機測試 main（LeetCode 交作業時刪掉 main） ***************/
static void test(int* nums, int n, int expect) {
    int ans = findMin(nums, n);
    printf("ans=%d expect=%d %s\n", ans, expect, ans==expect?"OK":"WRONG");
}

int main() {
    int a1[] = {3,4,5,1,2};
    test(a1, 5, 1);

    int a2[] = {4,5,6,7,0,1,2};
    test(a2, 7, 0);

    int a3[] = {11,13,15,17};
    test(a3, 4, 11);

    int a4[] = {2,1};
    test(a4, 2, 1);

    return 0;
}
