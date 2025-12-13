#include<stdio.h>
#include<stdlib.h>

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int hashTable[1001] = {0};
    *returnSize = 0;
    int* ret = (int*)malloc(sizeof(int)*nums1Size);

    for(int i = 0; i < nums1Size; i++){
        hashTable[nums1[i]]++;
    }

    for(int i = 0; i < nums2Size; i++){
        if(hashTable[nums2[i]] != 0){
            ret[(*returnSize)++] = nums2[i];
            hashTable[nums2[i]] --; // 標記已加入，避免重複
        }
    }

    return ret;
    
}



int main() {
    // 測資：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    int nums1[] = {4,9,5};
    int nums2[] = {9,4,9,8,4};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    int returnSize = 0;

    // 呼叫你的函式
    int* result = intersect(nums1, nums1Size, nums2, nums2Size, &returnSize);

    // 印出結果
    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i != returnSize - 1) printf(", ");
    }
    printf("]\n");

    // 釋放記憶體
    free(result);

    return 0;
}