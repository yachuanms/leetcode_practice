#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include "uthash.h"

//過了但beat 16% 效果很差
//但算了先這樣吧
struct HashItem{
    int key;
    int index; //最後一次出現的位置
    UT_hash_handle hh;
};

bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    struct HashItem *hashTable = NULL;

    for(int i =0; i< numsSize; i++){
        struct HashItem *item;
        //HASH_FIND_INT(head, keyptr, out);
        HASH_FIND_INT(hashTable, &nums[i], item);

        if(item){
            if(i-item->index <= k){
                // 清理記憶體
                struct HashItem *cur, *tmp;
                HASH_ITER(hh, hashTable, cur, tmp){
                    HASH_DEL(hashTable, cur);
                    free(cur);
                }
                return true;
            }else{
                item->index = i;
            }
        }else{
            item= (struct HashItem*)malloc(sizeof(struct HashItem));
            item->key = nums[i];
            item->index = i;
            HASH_ADD_INT(hashTable, key, item);
        }
    }
    struct HashItem *cur, *tmp;
    HASH_ITER(hh, hashTable, cur, tmp){
        HASH_DEL(hashTable, cur);
        free(cur);
    }
    return false;
}


/*想法對了 可是freq[100]不夠
得用hashMap了 麻煩的東西
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    int freq[100]= {0};
    for(int i = 0; i < k+1; i++){
        freq[nums[i]]++;
        if(freq[nums[i]]>=2){
            return true;
        }
    }
    for(int i = k+1; i < numsSize; i++){
        freq[nums[i-k-1]]--;
        freq[nums[i]]++;
        if(freq[nums[i]]==2){
            return true;
        }
    }
    return false;

}
*/
int main() {
    int nums1[] = {1,2,3,1};
    printf("Test1: %s\n", containsNearbyDuplicate(nums1, 4, 3) ? "true" : "false");
    // 預期: true

    int nums2[] = {1,0,1,1};
    printf("Test2: %s\n", containsNearbyDuplicate(nums2, 4, 1) ? "true" : "false");
    // 預期: true

    int nums3[] = {1,2,3,1,2,3};
    printf("Test3: %s\n", containsNearbyDuplicate(nums3, 6, 2) ? "true" : "false");
    // 預期: false

    int nums4[] = {99,99};
    printf("Test4: %s\n", containsNearbyDuplicate(nums4, 2, 2) ? "true" : "false");
    // 預期: true

    int nums5[] = {1,2,3,4,5};
    printf("Test5: %s\n", containsNearbyDuplicate(nums5, 5, 3) ? "true" : "false");
    // 預期: false

    return 0;
}

