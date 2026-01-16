#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* minWindow(char* s, char* t){
    int lens = strlen(s);
    int lent = strlen(t);

    if(lens < lent){
        char* ans = malloc(sizeof(char)*1);
        ans[0] = '\0';
        return ans;
    }

    int freqt[128] = {0};
    for(int i = 0; i < lent; i++){
        freqt[(unsigned char)t[i]]++;
    }

    int missing = lent;
    int windowLen = 0;
    int minLen = lens+1;
    int start = 0;
    int left = 0;

    for(int right = 0; right < lens; right++){
        freqt[(unsigned char)s[right]]--;
        if(freqt[(unsigned char)s[right]] >= 0){
            missing--;
        }

        while(missing == 0){
            windowLen = right - left+1;
            if(windowLen < minLen){
                minLen = windowLen;
                start = left;
            }
            //縮左邊
            freqt[(unsigned char)s[left]]++;
            if(freqt[(unsigned char)s[left]] > 0){
                missing++;
            }
            left++;
        }
    }

    if (minLen == lens+1){
        char* ans = malloc(sizeof(char)*1);
        ans[0] = '\0';
        return ans;
    }

    char* ans = malloc(sizeof(char)*(minLen+1));
    for(int i = 0; i < minLen; i++){
        ans[i] = s[start+i];
    }
    ans[minLen] = '\0';
    return ans;

}

int main() {
    char* ans;

    ans = minWindow("ADOBECODEBANC", "ABC");
    printf("Test 1: %s\n", ans); // 預期 "BANC"
    free(ans);

    ans = minWindow("a", "a");
    printf("Test 2: %s\n", ans); // 預期 "a"
    free(ans);

    ans = minWindow("a", "aa");
    printf("Test 3: %s\n", ans); // 預期 ""
    free(ans);

    ans = minWindow("aa", "aa");
    printf("Test 4: %s\n", ans); // 預期 "aa"
    free(ans);

    return 0;
}
