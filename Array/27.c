#include<stdio.h>

//27.remove element in the array without creating another array

int removeElement(int* nums, int numsSize, int val) {
    int right = numsSize-1;
    int left = 0;
    int temp = 0;
    while(left<= right){
        if(nums[left] == val){
            if(nums[right] != val){
                //exchange
                temp = nums[right];
                nums[right] = nums[left];
                nums[left] = temp;
                right--;
                left++;
                //numsSize--;
            }else{
                //numsSize--;
                right--;
            }
        }else{
            left++;
        }
    }
    return left;
}
/*用左右指標 將左側val值的和右側不是val的互換
*/


int main(){
    int nums[] = {0,1,2,3,4,2,6,7,2};
    int val = 2;
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int result = removeElement(nums, numsSize, val);
    printf("%d\n", result);
    for(int i =0; i < result; i++){
        printf("%d ", nums[i]);
    }
    return 0;
}