#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cmp(const void* a, const void* b){
    return (*(int*)a)-(*(int*)b);
}

// 宣告函式，讓你自己實作
bool containsDuplicate(int* nums, int numsSize){
    if(numsSize <= 1){
        return false;
    }

    qsort(nums, numsSize, sizeof(int), cmp);

    for(int i = 0; i < numsSize-1; i++){
        if(nums[i] == nums[i+1]){
            return true;
        }
    }

    return false;

}

int main() {
    int nums1[] = {1, 2, 3, 1};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Test 1: %s\n", containsDuplicate(nums1, numsSize1) ? "true" : "false");

    int nums2[] = {1, 2, 3, 4};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Test 2: %s\n", containsDuplicate(nums2, numsSize2) ? "true" : "false");

    int nums3[] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Test 3: %s\n", containsDuplicate(nums3, numsSize3) ? "true" : "false");

    return 0;
}
