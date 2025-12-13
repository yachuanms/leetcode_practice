//125. Valid Palindrome(Easy)

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

bool isPalindrome(char *s){
    int left = 0;
    int right = strlen(s) -1;
    while(left < right){
        //跳過非數字英文的字母
        while(left < right && !isalnum((unsigned char)s[left])){
            left++;
        }while(left < right && !isalnum((unsigned char)s[right])){
            right--;
        }
        //比較 不一樣就返回
        if(tolower((unsigned char)s[left]) != tolower((unsigned char)s[right])){
            return false;
        }
        left ++;
        right --;
    }
    return true;
}