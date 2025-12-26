#include<stdio.h>
#include<string.h>

//3. Longest Substring Without Repeating Characters

int lengthOfLongestSubstring(char* s) {
    int lastIndex[256];
    for(int i = 0; i < 256; i++){
        lastIndex[i] = -1;
    }
    int left = 0;
    int maxWindow = 0;
    int windowLen =0;
    for(int right = 0; right < strlen(s); right++){
        char c = s[right];
        if(lastIndex[(unsigned char)c] >= left){
            left = lastIndex[(unsigned char)c]+1;
        }
        lastIndex[(unsigned char)c] = right;

        windowLen = right - left +1;
        if(maxWindow < windowLen){
            maxWindow = windowLen;
        }

        
    }
    return maxWindow;
}

// 測試
int main() {
    char s1[] = "abcabcbb";
    char s2[] = "bbbbb";
    char s3[] = "pwwkew";

    printf("%s -> %d\n", s1, lengthOfLongestSubstring(s1)); // 3
    printf("%s -> %d\n", s2, lengthOfLongestSubstring(s2)); // 1
    printf("%s -> %d\n", s3, lengthOfLongestSubstring(s3)); // 3
    return 0;
}
