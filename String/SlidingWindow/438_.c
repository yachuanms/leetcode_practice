#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* findAnagrams(char* s, char* p, int* returnSize){
    int lens = strlen(s);
    int lenp = strlen(p);

    if(lens < lenp){
        *returnSize = 0;
        return NULL;
    }   
    
    int freqp[26] = {0};
    int freqs[26] = {0};

    int* ans = malloc(sizeof(int)*(lens-lenp+1));
    //要記得加這行!!!!!!
    //不然returnSize裡面可能存垃圾值
    *returnSize = 0;


    for(int i = 0; i < lenp; i++){
        freqp[p[i]-'a']++;
        freqs[s[i]-'a']++;
    }

    int left = 0;

    if(memcmp(freqp, freqs, 26*sizeof(int))==0){
        ans[(*returnSize)++] = left;
    }

    for(int right = lenp; right < lens; right++){
        freqs[s[left]-'a']--;
        left++;
        freqs[s[right]-'a']++;

        if(memcmp(freqp, freqs, 26*sizeof(int))==0){
            ans[(*returnSize)++] = left;
        }
    }

    return ans;

}

static void printArr(int* a, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i) printf(", ");
        printf("%d", a[i]);
    }
    printf("]\n");
}

int main() {
    int rs;
    int* ans;

    ans = findAnagrams("cbaebabacd", "abc", &rs); // 預期 [0, 6]
    printf("Test 1: "); printArr(ans, rs);
    free(ans);

    ans = findAnagrams("abab", "ab", &rs); // 預期 [0, 1, 2]
    printf("Test 2: "); printArr(ans, rs);
    free(ans);

    ans = findAnagrams("baa", "aa", &rs); // 預期 [1]
    printf("Test 3: "); printArr(ans, rs);
    free(ans);

    return 0;
}
