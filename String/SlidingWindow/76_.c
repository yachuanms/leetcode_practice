#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>


char* minWindow(char* s, char* t){
    int left = 0;
    int needs[128] = {0};
    int lens = strlen(s);
    int lent = strlen(t);
    int missing = lent;
    int minLen = INT_MAX;
    int start = 0;

    for(int i = 0; i < lent; i++){
        needs[(unsigned char)t[i]]++;
    }

    for(int right = 0; right < lens; right++){
        if(needs[(unsigned char)s[right]] >0){
            missing--;
        }
        needs[(unsigned char)s[right]]--;

        while(missing == 0){
            if(right-left+1 < minLen){
                minLen = right-left+1;
                start = left;
            }
            needs[(unsigned char)s[left]]++;
            if(needs[(unsigned char)s[left]]>0){
                missing++;
            }
            left++;
        }
    }
    if(minLen == INT_MAX){
        return "";
    }

    char *res = (char* )malloc(minLen+1);
    strncpy(res, s+start, minLen);
    res[minLen]='\0';
    return res;
    
}


// 測試
int main() {
    char s[] = "ADOBECODEBANC";
    char t[] = "ABC";
    char* ans = minWindow(s, t);
    printf("Result: %s\n", ans); // 預期輸出 "BANC"
    free(ans);
    return 0;
}
