#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* TODO: 請妳實作這個函式 */
bool isPalindrome(int x){
    if (x < 0) return false;

    char str[20];
    sprintf(str, "%d", x);

    int len = strlen(str);
    int left = 0;
    int right = len-1;
    while(left < right){
        if(str[left] != str[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main(void) {
    int nums[] = {121, -121, 10, 0, 1221, 12321, 1234321, 1001, 123};
    int size = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < size; i++) {
        printf("Test %d: %d → %s\n",
               i + 1,
               nums[i],
               isPalindrome(nums[i]) ? "true" : "false");
    }

    return 0;
}
