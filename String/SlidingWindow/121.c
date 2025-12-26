#include<stdlib.h>
#include<stdio.h>

//買要最低價  先
//賣要最高價

int maxProfit(int* prices, int pricesSize) {
    int minPrice = prices[0];
    int maxPrice = prices[0];
    int profit = 0;
    int maxProfit = 0;
    for(int i = 0; i < pricesSize; i++){
        if(prices[i] < minPrice){
            minPrice = prices[i];// 更新歷史最低價
        }  
        if(maxProfit < prices[i]-minPrice){
            maxProfit = prices[i]-minPrice; // 更新最大利潤
        }

    }
    return maxProfit;

}


// 測試
int main() {
    int prices1[] = {7,1,5,3,6,4};
    int prices2[] = {7,6,4,3,1};

    printf("Max profit: %d\n", maxProfit(prices1, 6)); // 5
    printf("Max profit: %d\n", maxProfit(prices2, 5)); // 0
    return 0;
}