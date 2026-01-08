#include <stdio.h>
#include <string.h>

int characterReplacement(char* s, int k){
    int freq[26] = {0};
    int windowSize = 0;
    int maxLen = 0;
    int maxCount = 0;
    int left = 0;
    for(int right = 0; s[right]; right++){
        int idx = s[right]-'A'; //因為input只給大寫
        freq[idx]++;
        windowSize++;

        if(freq[idx]>maxCount){
            maxCount = freq[idx];
        }
        //超過了 window 縮小
        //減去最前面的字元freq 並left++
        if(windowSize>maxCount+k){
            freq[s[left++]-'A']--;
            windowSize--;
        }

        if(windowSize>maxLen){
            maxLen = windowSize;
        }

    }

    return maxLen;
};

int main() {
    printf("Test 1: %d\n", characterReplacement("ABAB", 2));     // 預期 4
    printf("Test 2: %d\n", characterReplacement("AABABBA", 1));  // 預期 4
    printf("Test 3: %d\n", characterReplacement("AAAA", 0));     // 預期 4
    printf("Test 4: %d\n", characterReplacement("ABCDE", 1));    // 預期 2
    printf("Test 5: %d\n", characterReplacement("", 2));         // 預期 0
    return 0;
}
