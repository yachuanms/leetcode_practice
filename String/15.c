#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}


// 你要自己實作這個函式
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if(numsSize == 0){
        return NULL;
    }
    
    qsort(nums, numsSize, sizeof(int), cmp);
    int sum, target, left, right;
    *returnSize = 0;

    int** ret = malloc(sizeof(int*)*(numsSize));
    *returnColumnSizes = malloc(sizeof(int)*(numsSize));
    for(int i = 0; i< numsSize; i++){
        if(i> 0 && (nums[i] == nums[i-1])){
            continue;
        }
        target = -nums[i];
        left = i+1;
        right = numsSize-1;
        while(left < right){
            sum = nums[left]+nums[right];
            if(sum == target){
                ret[*returnSize] = malloc(sizeof(int)*3);
                ret[*returnSize][0] = nums[i];
                ret[*returnSize][1] = nums[left++];
                ret[*returnSize][2] = nums[right--];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                while (left < right && nums[left] == nums[left-1]){
                    left++;
                }
                while (left < right && nums[right] == nums[right+1]){
                    right--;
                }               
            } else if(sum > target){
                right--;
            }else{
                left++;
            }
        }
    }

    return ret;
}

int main() {
    int nums1[] = {-1,0,1,2,-1,-4};
    int size1 = sizeof(nums1)/sizeof(nums1[0]);

    int returnSize1;
    int* returnColumnSizes1;

    int** res1 = threeSum(nums1, size1, &returnSize1, &returnColumnSizes1);

    printf("Test 1:\n");
    for (int i = 0; i < returnSize1; i++) {
        printf("[%d, %d, %d]\n", res1[i][0], res1[i][1], res1[i][2]);
        free(res1[i]);
    }
    free(res1);
    free(returnColumnSizes1);

    return 0;
}
