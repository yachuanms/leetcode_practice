#include <stdio.h>

int minEatingSpeed(int* piles, int pilesSize, int h){

    //最慢1根/1小時
    //最快就是max(piles[i])
    int left = 1;
    int right = piles[0]; //max of piles[i]
    for(int i = 1; i < pilesSize; i++){
        if(piles[i]> right){
            right = piles[i];
        }
    }
    int k;
    int ans;
    while(left <= right){
        k = (left+right)/2;
        long long hours = 0;
        for(int i = 0; i < pilesSize; i++){
            //hours += piles[i] / k+1;
            //不行的原因是因為整除的時候不需要加1
            //除之前先多給它「k-1 的緩衝」
            //只要有剩，就一定會被推到下一個整數
            hours+= (piles[i] + k - 1) / k;
        }
        if(hours > h){ //太慢
            left = k+1;
        }else{//太快
            right = k-1;
            ans = k;
        }
    }

    return ans;

}

static void test(int* piles, int n, int h, int expect) {
    int ans = minEatingSpeed(piles, n, h);
    printf("ans=%d expect=%d %s\n", ans, expect, ans==expect?"OK":"WRONG");
}

int main() {
    int a1[] = {3,6,7,11};
    test(a1, 4, 8, 4);

    int a2[] = {30,11,23,4,20};
    test(a2, 5, 5, 30);
    test(a2, 5, 6, 23);

    return 0;
}
