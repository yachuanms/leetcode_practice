#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int value;
    int index;
}Number;

int compare(const void* a, const void* b){
    return ((Number*)a)->value - ((Number*)b)->value;
}


// 函式宣告
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    Number* numbers = (Number*)malloc(sizeof(Number)*numsSize);

    for(int i = 0; i < numsSize; i++){
        numbers[i].value = nums[i];
        numbers[i].index = i;
    }

    qsort(numbers, numsSize, sizeof(Number), compare);

    int left = 0;
    int right = numsSize-1;
    while(left < right){
        int sum = numbers[left].value+numbers[right].value;
        if(sum == target){
            int* ret = malloc(sizeof(int)*2);
            ret[0] = numbers[left].index;
            ret[1] = numbers[right].index;
            *returnSize = 2;
            free(numbers);
            return ret;
        }else if(sum < target){
            left++;
        }else{
            right--;
        }
    }
    free(numbers);
    *returnSize = 0;
    return NULL;
}

void printResult(int* result, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", result[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int nums1[] = {2, 7, 11, 15};
    int target1 = 9;
    int returnSize1;
    int* res1 = twoSum(nums1, 4, target1, &returnSize1);
    printf("Test 1 Output: ");
    printResult(res1, returnSize1);
    free(res1);

    int nums2[] = {3, 2, 4};
    int target2 = 6;
    int returnSize2;
    int* res2 = twoSum(nums2, 3, target2, &returnSize2);
    printf("Test 2 Output: ");
    printResult(res2, returnSize2);
    free(res2);

    int nums3[] = {3, 3};
    int target3 = 6;
    int returnSize3;
    int* res3 = twoSum(nums3, 2, target3, &returnSize3);
    printf("Test 3 Output: ");
    printResult(res3, returnSize3);
    free(res3);

    return 0;
}
