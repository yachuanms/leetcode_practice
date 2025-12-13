#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* findAnagrams(char* s, char* p, int* returnSize) {
    int freqs[26] = {0};
    int freqp[26] = {0};
    int lens = strlen(s);
    int lenp = strlen(p);

    if (lenp > lens) {
        *returnSize = 0;
        return malloc(0); 
    }
    //int *res = (int *)malloc(sizeof(int)*(lens-lenp+1));
    //C可以不用加(int *) C++才要
    int *ret = malloc(sizeof(int) * (lens - lenp + 1));
    *returnSize = 0;

    // 初始化第一個視窗 //window大小為lenp
    for (int i = 0; i < lenp; i++) {
        freqs[s[i]-'a']++;
        freqp[p[i]-'a']++;
    }
    //memory compare 相同回傳0 不同看誰大傳正數或負數
    if (memcmp(freqs, freqp, 26*sizeof(int)) == 0) {
        ret[(*returnSize)++] = 0;
    }

    // 滑動視窗
    for (int i = lenp; i < lens; i++) {
        freqs[s[i-lenp]-'a']--;// 移出視窗左邊的字母
        freqs[s[i]-'a']++;// 加入新的字母
        if (memcmp(freqs, freqp, 26*sizeof(int)) == 0) {
            ret[(*returnSize)++] = i - lenp + 1;
        }
    }

    return ret;
}


int main() {
    char s[] = "cbaebabacd";
    char p[] = "abc";
    int returnSize = 0;

    int* res = findAnagrams(s, p, &returnSize);

    printf("Indices: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    free(res); // 記得釋放 malloc 的記憶體
    return 0;
}