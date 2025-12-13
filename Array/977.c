#include<stdio.h>
#include<stdlib.h>
/*
输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]，排序后，数组变为 [0,1,9,16,100]
*/

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int left = 0;
    int right = numsSize -1;
    *returnSize = numsSize;
    //malloc 在堆（heap）上分配記憶體，
    //這樣即使 sortedSquares 函式結束，
    //這塊記憶體仍然有效，
    //直到我們手動用 free() 釋放它
    int *ans = (int *)malloc(sizeof(int) * numsSize);
    for(int i = 0 ; i < numsSize; i++){
        int l2 = nums[left]*nums[left];
        int r2 = nums[right]*nums[right];

        if(l2 > r2){
            ans[numsSize-i-1] = l2;
            left++;
        }else{
            ans[numsSize-i-1] = r2;
            right--;
        }
    }
    
    return ans;
}


int main(){
    int nums[] = {-7,-3,2,3,11};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *result = sortedSquares(nums, numsSize, &returnSize);
    for(int i = 0; i < numsSize;i++){
        printf("%d ", result[i]);
    }
    //釋放記憶體
    free(result);

    return 0;
}