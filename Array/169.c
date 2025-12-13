#include<stdio.h>
#include<stdlib.h>

//find element which appears more than n/2 times
//好像不對

int majorityElement(int* nums, int numsSize) {
    int count = 0;
    int maj = nums[0];
    for(int i = 0; i<numsSize; i++){
        if(nums[i] == maj){
            count++;
        }
    }
    
    if(count >= numsSize/2){
        return maj;
    }else{
        maj = nums[1];
        for(int i = 0; i<numsSize; i++){
            if(nums[i] == maj){
                count++;
            }
        }
    }
    return count;
}


int main(){
    int nums[] = {2,2,1,1,1,2,2,1,1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = majorityElement(nums, numsSize);
    printf("%d\n", result);

    return 0;
}