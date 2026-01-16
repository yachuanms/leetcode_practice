#include <stdio.h>
#include <limits.h>

double findMaxAverage(int* nums, int numsSize, int k){
    double ans = 0;
    int maxSum = INT_MIN;
    int sum = 0;
    int left = 0;

    for(int right = 0; right < numsSize; right++){
        sum += nums[right];
        int windowLen= right - left +1;
        if(windowLen == k){
            if(sum >= maxSum){
                maxSum = sum;
            }
            sum-= nums[left++];
        }
    }

    ans = (double)maxSum / k;
    return ans;
}

int main() {
    int a1[] = {1,12,-5,-6,50,3};
    printf("Test 1: %.5f\n", findMaxAverage(a1, 6, 4)); // 預期 12.75000

    int a2[] = {5};
    printf("Test 2: %.5f\n", findMaxAverage(a2, 1, 1)); // 預期 5.00000

    int a3[] = {-1,-2,-3,-4};
    printf("Test 3: %.5f\n", findMaxAverage(a3, 4, 2)); // 預期 -1.50000

    return 0;
}
