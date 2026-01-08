#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s){
    int lastIndex[256];
    for(int i = 0; i < 256; i++){
        lastIndex[i] = -1;
    }

    int maxLen = 0;
    int left = 0;
    int len = strlen(s);
    for(int right = 0; right < len; right++){
        char c = s[right];
        //先確定在這個window裡面有沒有出現過
        if(lastIndex[(unsigned char)c] >= left){
            left =lastIndex[c]+1;
        }

        lastIndex[(unsigned char)c] = right;
        int windowLen = right -left +1;
        if(windowLen > maxLen){
            maxLen = windowLen; 
        }
    }

    return maxLen;
    
}

int main() {
    printf("Test 1: %d\n", lengthOfLongestSubstring("abcabcbb")); // 預期 3 ("abc")
    printf("Test 2: %d\n", lengthOfLongestSubstring("bbbbb"));    // 預期 1 ("b")
    printf("Test 3: %d\n", lengthOfLongestSubstring("pwwkew"));   // 預期 3 ("wke")
    printf("Test 4: %d\n", lengthOfLongestSubstring(""));         // 預期 0
    printf("Test 5: %d\n", lengthOfLongestSubstring(" "));        // 預期 1
    printf("Test 6: %d\n", lengthOfLongestSubstring("dvdf"));     // 預期 3 ("vdf")
    return 0;
}
