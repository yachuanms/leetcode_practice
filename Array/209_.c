#include<stdio.h>
#include<stdlib.h>

/*给定一个含有 n 个正整数的数组和一个正整数 s 
找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组
并返回其长度。如果不存在符合条件的子数组，返回 0。
*/

//滑動窗口
int minSubArrayLen(int target, int* nums, int numsSize) {
    int min = numsSize +1;

    int left = 0, sum = 0;
    //用雙指標 將兩個for loop 改成一個
    for(int right = 0; right < numsSize; right++){
        sum += nums[right];
        while(sum >= target){
            int subLen = right - left +1;
            if(subLen < min){
                min = subLen;
            }
            sum -= nums[left++];
            //將最左邊的值扣掉 = 窗口向右移
        }
    }

    if(min != numsSize+1){
        return min;
    }else{
        return 0;
    }
}


int main(){
    int nums[] = {1,4,1,1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 7;
    int result = minSubArrayLen(target,nums,numsSize);
    printf("%d ", result);

    return 0;
}