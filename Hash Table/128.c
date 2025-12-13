#include <stdio.h>
#include <stdlib.h>

// 你要自己實作這個函式
//這題要O(n)

int cmp(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int longestConsecutive(int* nums, int numsSize){
    
    if(numsSize == 0){
        return 0;
    }

    if(numsSize == 1){
        return 1;
    }

    //qsort很快
    qsort(nums, numsSize, sizeof(int), cmp);

    int max = 1;
    int len = 1;

    for(int i = 1; i < numsSize; i++){
        if(nums[i] == nums[i-1]+1){
            len++;
            if(len > max){
                max = len;
            }
        }else if(nums[i] != nums[i-1]){
            len = 1;
        }
    }

    return max;
}

int main() {
    int nums1[] = {100, 4, 200, 1, 3, 2};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Test 1: %d\n", longestConsecutive(nums1, size1));

    int nums2[] = {0,3,7,2,5,8,4,6,0,1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Test 2: %d\n", longestConsecutive(nums2, size2));

    int nums3[] = {};
    int size3 = 0;
    printf("Test 3: %d\n", longestConsecutive(nums3, size3));

    int nums4[] = {9};
    int size4 = sizeof(nums4) / sizeof(nums4[0]);
    printf("Test 4: %d\n", longestConsecutive(nums4, size4));

    return 0;
}
