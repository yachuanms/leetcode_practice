#include<stdio.h>
#include<stdlib.h>
#include "uthash.h"  //額外下載的

typedef struct{
    int key;
    int value;
    UT_hash_handle hh;// hash handle，用於 uthash 管理
}HashItem;


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashItem *hashTable = NULL;
    for(int i = 0 ; i < numsSize ; i++){
        int wanted = target - nums[i];
        HashItem *item;
        HASH_FIND_INT(hashTable, &wanted, item);
        if(item){
            int *result = malloc(2 * sizeof(int));
            result[0] = item->value;
            result[1] = i;
            *returnSize  = 2;
            HashItem *current_item, *tmp;
            HASH_ITER(hh, hashTable, current_item, tmp) {
                HASH_DEL(hashTable, current_item);
                free(current_item);
            }
            return result;
        }
        item = malloc(sizeof(HashItem));
        item->key = nums[i];
        item->value = i;
        HASH_ADD_INT(hashTable, key, item);
    }
    *returnSize = 0;
    return NULL;

}


//不可行  因為nums內的數可能超級大  
//hash得設到10^9次方
/*
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2* sizeof(int));
    int hash[2000] = {-1};
    int wanted = 0;

    *returnSize = 0;

    for(int i = 0; i < numsSize; i++){
        wanted = target - nums[i];
        //printf("wanted: %d\n", wanted);
        if(hash[wanted+1000] ){
            //printf("hash wanted: %d\n", hash[wanted]);
            result[(*returnSize)++] = i;
            result[(*returnSize)++] = hash[wanted+1000] - 1;
            return result;
        }
        hash[nums[i+1000]] = i + 1;
    }

    return result;
}
*/

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    
    int* result = twoSum(nums, numsSize, target, &returnSize);

    if (result != NULL && returnSize == 2) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
    } else {
        printf("No solution found.\n");
    }

    // 記得釋放動態記憶體
    free(result);

    return 0;
}