#include <stdio.h>
#include <stdlib.h>

// 你要自己實作這個函式
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int left = 0;
    int right = numbersSize-1;

    int* ret = malloc(sizeof(int)*2);

    while(left < right){
        int sum = numbers[left]+numbers[right];
        if(sum == target){
            ret[0] = left+1;
            ret[1] = right+1;
            break;
        }else if(sum > target){
            right--;
        }else{
            left++;
        }

    }

    *returnSize = 2;
    return ret;
}

int main() {
    int nums1[] = {2,7,11,15};
    int size1 = sizeof(nums1)/sizeof(nums1[0]);
    int returnSize1;
    int* ans1 = twoSum(nums1, size1, 9, &returnSize1);

    printf("Test 1: [%d, %d]\n", ans1[0], ans1[1]);
    free(ans1);

    int nums2[] = {1,2,3,4,4,9,56,90};
    int size2 = sizeof(nums2)/sizeof(nums2[0]);
    int returnSize2;
    int* ans2 = twoSum(nums2, size2, 8, &returnSize2);

    printf("Test 2: [%d, %d]\n", ans2[0], ans2[1]);
    free(ans2);

    return 0;
}
