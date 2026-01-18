#include <stdio.h>
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if(numsSize == 0 || k==0 || k > numsSize){
        *returnSize = 0;
        return NULL;
    }

    int front = 0;
    int back = -1;//最後可用的值
    //由大排到小
    int* deque = malloc(sizeof(int)*(numsSize));
    int* ans = malloc(sizeof(int)*(numsSize-k+1));
    int idx = 0; //給ans當指標

    for(int i = 0; i < numsSize; i++){
        int leftbound = i - k +1;
        //先檢查有沒有front位置是否在window前方 --過期
        if(front <= back && deque[front] < leftbound){
            front++;
        }
        //看新元素是否大於deque[back]內的值
        while(front <= back && nums[deque[back]] <= nums[i]){
            back--;
        }

        deque[++back] = i;

        //window len == k
        if(leftbound>= 0){
            ans[idx++] = nums[deque[front]];
        }
    }

    free(deque);
    *returnSize = idx;
    return ans;
    
}

int main() {
    int rs;
    int* ans;

    int a1[] = {1,3,-1,-3,5,3,6,7};
    ans = maxSlidingWindow(a1, 8, 3, &rs); // 預期 [3,3,5,5,6,7]
    printf("Test 1: ");
    for (int i = 0; i < rs; i++) printf("%d%s", ans[i], (i==rs-1)?"\n":", ");
    free(ans);

    int a2[] = {1};
    ans = maxSlidingWindow(a2, 1, 1, &rs); // 預期 [1]
    printf("Test 2: ");
    for (int i = 0; i < rs; i++) printf("%d%s", ans[i], (i==rs-1)?"\n":", ");
    free(ans);

    return 0;
}
