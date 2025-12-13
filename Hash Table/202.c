#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

int getSum(int value){
    int sum = 0;
    while(value >= 10){
        int tmp = value%10;
        sum += tmp*tmp;
        value/=10;
    }
    sum += value*value;
    printf("sum = %d\n", sum);
    return sum;
}


bool isHappy(int n) {

    int seen[20000] = {0};

    while(n != 1){
        n = getSum(n);
        if(seen[n]){
            return false;
        }
        seen[n] = 1;
    }

    
    return true;
    
}

int main() {
    int n1 = 19;
    int n2 = 2;

    if (isHappy(n1)) {
        printf("%d is a happy number.\n", n1);
    } else {
        printf("%d is NOT a happy number.\n", n1);
    }

    if (isHappy(n2)) {
        printf("%d is a happy number.\n", n2);
    } else {
        printf("%d is NOT a happy number.\n", n2);
    }

    return 0;
}