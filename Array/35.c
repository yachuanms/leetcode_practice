#include<stdio.h>
#include<stdlib.h>

//search or insert position

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize-1;
    int mid = 0;
    while(left <= right){
        mid = (left+right)/2;
        if(nums[mid] > target){
            right = mid -1;
        }
        else if(nums[mid]< target){
            left = mid +1;
        }
        else{
            return mid;
        }
    }
    if(left > right){
        return left;
    }
    return right;
}


int main(){
    int nums[] = {1,3,4,6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 7;
    int result = searchInsert(nums, numsSize, target);
    printf("%d\n", result);

    return 0;
}