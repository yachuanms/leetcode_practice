#include <stdio.h>
#include <stdlib.h>

int longestSubarray(int* nums, int numsSize, int limit){
    if(numsSize <=0 || limit < 0){
        return 0;
    }

    //最大放frontMax
    int frontMax = 0, backMax = -1;
    //最小放frontMin
    int frontMin = 0, backMin = -1;
    int len = 0;
    int max = 0;
    int* dqMax = malloc(sizeof(int)*numsSize);
    int* dqMin = malloc(sizeof(int)*numsSize);
    int left = 0;

    for(int right = 0; right < numsSize; right++){
        //每次存取dq前都要記得比較front <= back
        //front > back --> dq空的
        //front <= back --> dq有元素
        //nums[right]要和尾巴最爛的元素比不是跟最前面的極值
        while(frontMax <= backMax && nums[dqMax[backMax]] <= nums[right]){
            backMax--;
        }
        while(frontMin <= backMin && nums[dqMin[backMin]] >= nums[right]){
            backMin--;
        }
        //把right放進dq
        dqMax[++backMax] = right;
        dqMin[++backMin] = right;

        while(frontMax <= backMax && frontMin <= backMin && nums[dqMax[frontMax]] - nums[dqMin[frontMin]] > limit){
            //left一次只動一格 
            //所以過期的front一定是剛好等於left
            if(dqMax[frontMax] == left){
                frontMax++;
            }
            if(dqMin[frontMin] == left){
                frontMin++;
            }
            left++;
        }

        len = right - left +1;
        max = (len>max)?len:max;
    }

    free(dqMax);
    free(dqMin);
    return max;
}

int main() {
    int a1[] = {8,2,4,7};
    printf("Test 1: %d\n", longestSubarray(a1, 4, 4)); // 預期 2 ([2,4])

    int a2[] = {10,1,2,4,7,2};
    printf("Test 2: %d\n", longestSubarray(a2, 6, 5)); // 預期 4 ([2,4,7,2])

    int a3[] = {4,2,2,2,4,4,2,2};
    printf("Test 3: %d\n", longestSubarray(a3, 8, 0)); // 預期 3 ([2,2,2])

    return 0;
}
