#include <stdio.h>

int max(int a, int b){
    return (a>b)?a:b;
}

int maxProfit(int* prices, int pricesSize){
    if(pricesSize < 2) return 0;

    int buy1 = -prices[0];
    int sell1 = 0;
    int buy2 = -prices[0];
    int sell2 = 0;

    for(int i = 1; i<pricesSize; i++){
        int prevBuy1 = buy1;
        int prevSell1 = sell1;
        int prevBuy2 = buy2;
        int prevSell2 = sell2;

        int p = prices[i];

        buy1 = max(prevBuy1, -p);
        sell1 = max(prevSell1, prevBuy1+p);
        buy2 = max(prevBuy2, prevSell1-p);
        sell2 = max(prevSell2, prevBuy2+p);
    }

    return sell2;
}

int main() {
    int p1[] = {3,3,5,0,0,3,1,4};
    int n1 = sizeof(p1)/sizeof(p1[0]);
    printf("Test 1: %d\n", maxProfit(p1, n1)); // 預期 6 (0->3 + 1->4)

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
