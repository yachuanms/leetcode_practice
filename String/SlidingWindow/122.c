#include <stdio.h>

int maxProfit(int* prices, int pricesSize){
    if(pricesSize <2){
        return 0;
    }

    int buy = prices[0];
    int profit = 0;
    for(int i = 1; i < pricesSize; i++){
        if(prices[i]<buy){
            buy = prices[i];
        }
        else{
            profit += prices[i]-buy;
            buy = prices[i];
        }
    }
    return profit;
}

int main() {
    int p1[] = {7,1,5,3,6,4};
    int n1 = sizeof(p1)/sizeof(p1[0]);
    printf("Test 1: %d\n", maxProfit(p1, n1)); // 預期 7 (1->5 + 3->6)

    int p2[] = {1,2,3,4,5};
    int n2 = sizeof(p2)/sizeof(p2[0]);
    printf("Test 2: %d\n", maxProfit(p2, n2)); // 預期 4

    int p3[] = {7,6,4,3,1};
    int n3 = sizeof(p3)/sizeof(p3[0]);
    printf("Test 3: %d\n", maxProfit(p3, n3)); // 預期 0

    int p4[] = {1};
    int n4 = sizeof(p4)/sizeof(p4[0]);
    printf("Test 4: %d\n", maxProfit(p4, n4)); // 預期 0

    return 0;
}
