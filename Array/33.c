#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize -1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(nums[mid]== target){
            return mid;
        }
        //先判斷做邊是不是遞增
        if(nums[left] <= nums[mid]){
            //判斷target在不在左側
            if(nums[left] <= target && target < nums[mid]){
                right = mid-1;
            }else{
                left = mid+1;
            }
        //右邊才是遞增
        }else{
            if(nums[mid] < target && target <= nums[right]){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
    }

    return -1;

}


static void test(int* nums, int n, int target, int expect) {
    int ans = search(nums, n, target);
    printf("target=%d ans=%d expect=%d %s\n", target, ans, expect, (ans==expect)?"OK":"WRONG");
}

int main() {
    int a1[] = {4,5,6,7,0,1,2};
    test(a1, 7, 0, 4);
    test(a1, 7, 3, -1);
    test(a1, 7, 6, 2);

    int a2[] = {1};
    test(a2, 1, 0, -1);
    test(a2, 1, 1, 0);

    int a3[] = {3,1};
    test(a3, 2, 1, 1);
    test(a3, 2, 3, 0);

    int a4[] = {5,6,7,8,9,1,2,3,4};
    test(a4, 9, 2, 6);
    test(a4, 9, 8, 3);

    return 0;
}
