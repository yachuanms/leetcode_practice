#include <stdio.h>
#include <stdlib.h>

//time limit exceeded

// ===== HashMap 結構，用來記錄 prefix sum 出現次數 =====
typedef struct {
    int key;
    int val;
} Pair;

int findIndex(Pair* map, int size, int key) {
    for(int i= 0; i < size; i++){
        if(map[i].key == key){
            return i;
        }
    }
    return -1;
}

// ===== 主函式 =====
int subarraySum(int* nums, int numsSize, int k) {
    if(numsSize == 0){
        return 0;
    }
    Pair* map = malloc(sizeof(Pair)*(numsSize*2+1));
    int mapSize = 0;

    int count = 0;
    int sum = 0;

    map[mapSize].key = 0;
    map[mapSize].val = 1;
    mapSize++;

    for(int i = 0; i< numsSize; i++){
        sum+=nums[i];
        int target = sum-k;
        int idx = findIndex(map, mapSize, target);
        if(idx != -1){
            count+=map[idx].val;
        }

        int idx2 = findIndex(map, mapSize, sum);
        if(idx2 == -1){
            map[mapSize].key = sum;
            map[mapSize].val = 1;
            mapSize++;
        }
        else{
            map[idx2].val++;
        }

    }
    free(map);
    return count;
}

// ===== 測試 =====
int main() {
    int nums1[] = {1, 1, 1};
    printf("Output: %d\n", subarraySum(nums1, 3, 2));  // 2

    int nums2[] = {1, 2, 3};
    printf("Output: %d\n", subarraySum(nums2, 3, 3));  // 2

    int nums3[] = {1, -1, 0};
    printf("Output: %d\n", subarraySum(nums3, 3, 0));  // 3

    int nums4[] = {3,4,7,2,-3,1,4,2};
    printf("Output: %d\n", subarraySum(nums4, 8, 7));  // 4

    return 0;
}
