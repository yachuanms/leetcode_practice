#include<stdio.h>
#include<string.h>

//704.Binary search

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize-1;
    int middle = 0;

    while(left <= right){
        middle = (left+right)/2;
        if(nums[middle] < target){
            left = middle+1;
        }else if(nums[middle] > target){
            right = middle -1;
        }else{
            return middle;
        }
    }
    //沒找到
    return -1;
}


int main(){
    int nums[] = {-1,0,3,5,9,12};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int target = 12;
    printf("%d", search(nums, numsSize, target));
    return 0;
}