#include <stdio.h>

int maxProfit(int* prices, int pricesSize){
    if(pricesSize < 2){
        return 0;
    }

    int buy = prices[0];
    int maxProfit = 0;

    for(int i = 1; i< pricesSize; i++){
        if(prices[i]<buy){
            buy = prices[i];
        }
        int profit = prices[i]-buy;
        maxProfit = (profit>maxProfit)?profit:maxProfit;
    }

    return maxProfit;
}

int main() {
    int p1[] = {7,1,5,3,6,4};
    int n1 = sizeof(p1)/sizeof(p1[0]);
    printf("Test 1: %d\n", maxProfit(p1, n1)); // 預期 5 (1->6)

    int p2[] = {7,6,4,3,1};
    int n2 = sizeof(p2)/sizeof(p2[0]);
    printf("Test 2: %d\n", maxProfit(p2, n2)); // 預期 0

    int p3[] = {2,4,1};
    int n3 = sizeof(p3)/sizeof(p3[0]);
    printf("Test 3: %d\n", maxProfit(p3, n3)); // 預期 2

    int p4[] = {1};
    int n4 = sizeof(p4)/sizeof(p4[0]);
    printf("Test 4: %d\n", maxProfit(p4, n4)); // 預期 0

    return 0;
}
