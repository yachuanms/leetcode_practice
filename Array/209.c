#include<stdio.h>
#include<stdlib.h>

/*给定一个含有 n 个正整数的数组和一个正整数 s 
找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组
并返回其长度。如果不存在符合条件的子数组，返回 0。
*/

//暴力解法會time limit exceeded
int minSubArrayLen(int target, int* nums, int numsSize) {
    //int ans = 0;
    int min = numsSize+1;
    for(int i = 0; i< numsSize; i++){
        int add = nums[i];
        if(add >= target){
            min = 1;
            return min;
        }
        for(int j = i+1; j< numsSize; j++){
            add+=nums[j];
            if(add >= target){
                if((j-i+1) <= min){
                    min = j-i+1;
                }
                continue;
            }
            
        }
    }
    if(min<= numsSize){
        return min;
    }
    return 0;
}


int main(){
    int nums[] = {1,4,1,1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 7;
    int result = minSubArrayLen(target,nums,numsSize);
    printf("%d ", result);

    return 0;
}