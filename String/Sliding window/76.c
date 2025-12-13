#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

//76. Minimum Window Substring
//給兩個字串 s 和 t，找出 s 中最短的一個子字串，
//這個子字串必須包含 t 的所有字元（順序不限，可有重複）

char* minWindow(char* s, char* t){
    int need[128] = {0}; //紀錄t需要 ASCII
    int missing = strlen(t);

    for(int i =0;t[i] ; i++){
        need[(unsigned char)t[i]]++;
    }

    int left = 0;
    int start = 0;
    int minLen = INT_MAX;


    for(int right = 0; s[right]; right++){

        if(need[(unsigned char)s[right]] > 0){
            missing--;
        }
        need[(unsigned char)s[right]]--;

        //條件滿足 收縮左邊
        while(missing == 0){
            if(right-left+1 < minLen){
                minLen = right - left +1;
                start = left;
            }
            need[(unsigned char)s[left]]++;
            if(need[(unsigned char)s[left]]>0){
                missing++;
            }
            left++;
        }
    }

    if(minLen == INT_MAX){
        return "";
    }
    char *res = (char*)malloc(minLen +1);
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