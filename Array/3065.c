#include<stdio.h>
#include<stdlib.h>

//how many elements are less than k

int minOperations(int* nums, int numsSize, int k) {
    int left = 0;
    int right = numsSize - 1;
    int count = 0;
    while(left <= right){
        if(nums[left++] < k){
            count++;
        }else if(nums[right--] < k){
            count ++;
        }
    }
    return count;
}


int main(){
    int nums[] = {2,11,10,1,3,7,12};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 10;
    int result = minOperations(nums, numsSize, target);
    printf("%d\n", result);

    return 0;
}