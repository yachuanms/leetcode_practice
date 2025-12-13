#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// 你要自己實作這個函式
bool isPalindrome(char* s){
    int len = strlen(s);
    int right = len-1, left = 0;
    
    while(left < right){
        // 跳過非英數字@!~$%
        while(!isalnum(s[left])){
            left++;
            if(left >= right){
                return true;
            }
        }
        while(!isalnum(s[right])){
            right--;
            if(left >= right){
                return false;
            }
        }
        char r = tolower(s[right--]);
        char l = tolower(s[left++]);
        if(r != l){
            return false;
        }

    }

    return true;

}

int main() {
    char s1[] = "A man, a plan, a canal: Panama";
    printf("Test 1: %s\n", isPalindrome(s1) ? "true" : "false");

    char s2[] = "race a car";
    printf("Test 2: %s\n", isPalindrome(s2) ? "true" : "false");

    char s3[] = " ";
    printf("Test 3: %s\n", isPalindrome(s3) ? "true" : "false");

    char s4[] = "0P";
    printf("Test 4: %s\n", isPalindrome(s4) ? "true" : "false");

    return 0;
}
