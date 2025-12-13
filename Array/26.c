#include <stdio.h>

// 函式宣告
int removeDuplicates(int* nums, int numsSize){
    //int k = numsSize;
    int index = nums[0];
    int ptr = 1;
    int curr = 1;

    if(numsSize == 0){
        return 0;
    }

    while(ptr < numsSize){
        if(nums[ptr] != index){
            nums[curr++] = nums[ptr];
            index = nums[ptr];

        }
        ptr++;  
    }
    //printf("curr: %d\n", curr);
    return curr;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int nums1[] = {1, 1, 2};
    int numsSize1 = sizeof(nums1)/sizeof(nums1[0]);
    int k1 = removeDuplicates(nums1, numsSize1);
    printf("Test 1: k = %d, nums = ", k1);
    printArray(nums1, k1);

    int nums2[] = {0,0,1,1,1,2,2,3,3,4};
    int numsSize2 = sizeof(nums2)/sizeof(nums2[0]);
    int k2 = removeDuplicates(nums2, numsSize2);
    printf("Test 2: k = %d, nums = ", k2);
    printArray(nums2, k2);

    return 0;
}
