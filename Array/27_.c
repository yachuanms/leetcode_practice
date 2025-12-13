#include<stdio.h>

//27.remove element in the array without creating another array

int removeElement(int* nums, int numsSize, int val) {
    int slow = 0;
    for(int fast = 0; fast < numsSize; fast++){
        if(nums[fast] != val){
            nums[slow++] = nums[fast];
        }
    }
    
    return slow;
}
/*用slow當作指標紀錄目前有幾個不等於val的值
fast指標用來將不等於val的值複製到array當中*/


int main(){
    int nums[] = {0,1,2,3,4,2};
    int val = 2;
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int result = removeElement(nums, numsSize, val);
    printf("%d\n", result);
    for(int i =0; i < result; i++){
        printf("%d ", nums[i]);
    }
    return 0;
}