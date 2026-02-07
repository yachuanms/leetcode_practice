#include<stdio.h>
#include<string.h>

//704.Binary search

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize-1;

    while(left <= right){
        int mid = (left+right)/2;
        int val = nums[mid];
        if(target == val){
            return mid;
        }else{
            //left 不能直接等於mid
            //因為如果l =  3 r = 4, mid = 3
            //則下一輪left = mid 還是等於3
            if(target > val){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
    }

    return -1;
}


int main(){
    int nums[] = {-1,0,3,5,9,12};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int target = 12;
    printf("%d", search(nums, numsSize, target));
    return 0;
}