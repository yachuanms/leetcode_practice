#include <stdlib.h>
#include <stdio.h>

//題目要求 ans return ans mod 1e9+7
#define MOD 1000000007

int sumSubarrayMins(int* arr, int arrSize) {
    if(arrSize <= 0){
        return 0;
    }

    int* L = malloc(sizeof(int)*arrSize);
    int* R = malloc(sizeof(int)*arrSize);
    int* st = malloc(sizeof(int)*arrSize);
    int top = -1;

    for(int i = 0; i < arrSize; i++){
        //為什麼要一邊用 >，一邊用 >=  : 對於相等的值，只讓其中一邊負責算
        //第一個比 arr[i] 小的位置
        //L[i] 存小值 stack越下越小 
        while(top >= 0 && arr[st[top]] > arr[i]){
            top--;
        }
        //stack空代表i是目前最小
        L[i] = (top == -1)?(i+1):(i-st[top]);
        st[++top] = i;
    }
    //記得重治top
    top = -1;

    for(int i = arrSize-1; i >= 0; i--){
        while(top >= 0 && arr[st[top]] >= arr[i]){
            top--;
        }
        R[i] = (top == -1)?(arrSize-i):(st[top]-i);
        st[++top] = i;
    }

    long long ans = 0;
    for(int i = 0; i < arrSize; i++){
        ans = (ans+(long long)arr[i]*L[i]*R[i])% MOD ;
    }

    free(L);
    free(R);
    free(st);
    return (int)ans;

}


int main() {
    int a1[] = {3,1,2,4};
    printf("%d (expect 17)\n", sumSubarrayMins(a1, 4));

    int a2[] = {11,81,94,43,3};
    printf("%d (expect 444)\n", sumSubarrayMins(a2, 5));

    return 0;
}
