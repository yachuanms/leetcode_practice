#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int characterReplacement(char* s, int k) {
    int freq[26] = {0};
    int maxCount = 0;
    int windowSize =0;
    int right = 0, left = 0;
    int maxLen =0;

    for(right = 0; s[right]; right++){
        freq[s[right]-'A']++;
        windowSize++;
        if(freq[s[right]-'A'] > maxCount){
            maxCount = freq[s[right]-'A'];
        }
        if(windowSize- maxCount > k){
            windowSize--;
            freq[s[left++]-'A']--;
        }
        if(windowSize>maxLen){
            maxLen = windowSize;
        }
    }
    return maxLen;
    
}

int main() {
    char s1[] = "ABAB";
    int k1 = 2;
    printf("Test1: %d\n", characterReplacement(s1, k1));
    // 預期: 4

    char s2[] = "AABABBA";
    int k2 = 1;
    printf("Test2: %d\n", characterReplacement(s2, k2));
    // 預期: 4

    char s3[] = "AAAA";
    int k3 = 2;
    printf("Test3: %d\n", characterReplacement(s3, k3));
    // 預期: 4

    char s4[] = "ABCDE";
    int k4 = 1;
    printf("Test4: %d\n", characterReplacement(s4, k4));
    // 預期: 2 (任意兩個字母換成相同)

    return 0;
}