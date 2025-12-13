#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

bool isVowel(char c) {
    switch(c) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
        case 'A': case 'E': case 'I': case 'O': case 'U':
            return true;
        default:
            return false;
    }
}
/* 簡單但漫不少
bool isVowel(char c){
    if(strchr("aeiouAEIOU", c)){
        return true;
    }
    return false;
}
*/

char* reverseVowels(char* s){
    int left = 0;
    int len = strlen(s);
    int right = len-1;
    while(left < right){
        while(left < len && !isVowel(s[left])){
            left++;
        }
        while(right >= 0 && !isVowel(s[right])){
            right--;
        }
        if(left < right){
            char tmp = s[left];
            s[left++]= s[right];
            s[right--] = tmp;
        }
    }
    return s;

}

int main() {
    char s1[] = "hello";
    char s2[] = "leetcode";
    char s3[] = "aA";
    char s4[] = "TikTok";
    char s5[] = "AEIOUaeiou";

    printf("Input: \"%s\" -> Output: \"%s\"\n", s1, reverseVowels(s1));
    printf("Input: \"%s\" -> Output: \"%s\"\n", s2, reverseVowels(s2));
    printf("Input: \"%s\" -> Output: \"%s\"\n", s3, reverseVowels(s3));
    printf("Input: \"%s\" -> Output: \"%s\"\n", s4, reverseVowels(s4));
    printf("Input: \"%s\" -> Output: \"%s\"\n", s5, reverseVowels(s5));

    return 0;
}
