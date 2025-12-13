#include <stdio.h>
#include <stdlib.h>

// 你要自己實作這個函式

int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int* ret = malloc(sizeof(int)*numsSize);
    ret[0] = 1;
    for(int i = 1; i < numsSize; i++){
        ret[i] = ret[i-1]*nums[i-1];
    }
    int right = 1;
    for(int j = numsSize-1; j >= 0; j--){
        ret[j] = ret[j]*right;
        right *= nums[j];
    }

    *returnSize = numsSize;
    return ret;
}

/*
O(n^2)
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int* ret = malloc(sizeof(int)*numsSize);

    for(int i = 0; i< numsSize; i++){
        int left = 1, right = 1;
        for(int j = 0; j < i; j++){
            left *= nums[j];
        }
        for(int k = i+1; k < numsSize; k++){
            right *= nums[k];
        }

        ret[i] = left*right;

    }
    *returnSize = numsSize;
    return ret;
}
*/

int main() {
    int nums1[] = {1, 2, 3, 4};
    int returnSize1;
    int* result1 = productExceptSelf(nums1, 4, &returnSize1);

    printf("Test 1: ");
    for (int i = 0; i < returnSize1; i++)
        printf("%d ", result1[i]);
    printf("\n");
    free(result1);

    int nums2[] = {-1, 1, 0, -3, 3};
    int returnSize2;
    int* result2 = productExceptSelf(nums2, 5, &returnSize2);

    printf("Test 2: ");
    for (int i = 0; i < returnSize2; i++)
        printf("%d ", result2[i]);
    printf("\n");
    free(result2);

    return 0;
}
