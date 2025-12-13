#include<stdio.h>
#include<stdlib.h>

int min(int a, int b){
    return (a>b)?b:a;
}

int coinChange(int* coins, int coinsSize, int amount) {
    int *DP = malloc((amount+1)*sizeof(int));
    for(int i = 0; i <= amount; i++){
        DP[i] = __INT_MAX__;
    }
    DP[0]  = 0;
    
    for(int i = 0; i < coinsSize; i++){
        for(int w = coins[i]; w <= amount; w++){
            if(DP[w-coins[i]]!=__INT_MAX__){
                DP[w] = min(DP[w], DP[w-coins[i]]+1);
            }
        }
    }

    int ans = (DP[amount]==__INT_MAX__)?-1:DP[amount];
    free(DP);
    return ans;
    
}



int main() {
    int coins[] = {1, 2, 5};
    int coinsSize = sizeof(coins) / sizeof(coins[0]);
    int amount = 11;

    int result = coinChange(coins, coinsSize, amount);
    printf("Minimum coins needed for amount %d: %d\n", amount, result);

    // More tests
    int coins2[] = {2};
    printf("Test 2 -> %d\n", coinChange(coins2, 1, 3));  // expect -1
    int coins3[] = {1};
    printf("Test 3 -> %d\n", coinChange(coins3, 1, 0));  // expect 0

    return 0;
}