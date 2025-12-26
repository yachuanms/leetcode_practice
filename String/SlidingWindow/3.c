#include<stdio.h>
#include<string.h>

int lengthOfLongestSubstring(char* s) {
    int lastIndex[256];//ASCII 有256字元 存字元最後出現的位置
    for(int i = 0; i < 256; i++){
        lastIndex[i] = -1;//初始化
    }
    int sLen = strlen(s);
    int left = 0;
    int maxLen = 0;
    int windowLen = 0;
    for(int right = 0; right < sLen; right++){
        char c = s[right];
        //要先檢查才更新right
        //如果這個字已經出現過了 
        //若signed 可能是-128-127沒法存lastIndex
        if(lastIndex[(unsigned char)c] >= left){
            left = lastIndex[(unsigned char)c]+1;
            //這整個window都不要了
        }
        lastIndex[(unsigned char)c] = right;
        windowLen = right -left +1;
        if(windowLen > maxLen){
            maxLen = windowLen;
        }
    }
    return maxLen;

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
