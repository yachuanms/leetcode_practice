#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int value;
    int count;
}Pair;

int cmpFreq(const void* a, const void* b){
    return ((Pair*)b)->count - ((Pair*)a)->count;
}

int cmp(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

// 你要自己實作這個函式
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    int* ret = malloc(sizeof(int)*k);
    if (k==0){
        return NULL;
    }

    if(k > numsSize){
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), cmp);
    Pair* hash = malloc(sizeof(Pair)*numsSize);
    int index = -1;
    for(int i = 0; i < numsSize; i++){
        if(index >= 0 && hash[index].value == nums[i]){ 
            hash[index].count++;
        }else{
            index++;
            hash[index].value = nums[i];
            hash[index].count = 1;
        }
    }
    qsort(hash, index+1, sizeof(Pair), cmpFreq);
    for(int i = 0; i < k; i++){
        ret[i] = hash[i].value;
    }

    free(hash);

    *returnSize = k;

    return ret;

}

int main() {
    int nums1[] = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    int returnSize1;
    int* result1 = topKFrequent(nums1, sizeof(nums1)/sizeof(nums1[0]), k1, &returnSize1);

    printf("Test 1: ");
    for (int i = 0; i < returnSize1; i++)
        printf("%d ", result1[i]);
    printf("\n");

    int nums2[] = {4, 4, 4, 5, 6, 6, 6, 7};
    int k2 = 3;
    int returnSize2;
    int* result2 = topKFrequent(nums2, sizeof(nums2)/sizeof(nums2[0]), k2, &returnSize2);

    printf("Test 2: ");
    for (int i = 0; i < returnSize2; i++)
        printf("%d ", result2[i]);
    printf("\n");

    // 記得如果你在函式裡 malloc 了要 free
    free(result1);
    free(result2);
    return 0;
}
