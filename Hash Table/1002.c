#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void updateHash(int* hash1, int* hash2){
    for(int i = 0; i <26; i++){
        hash1[i] = (hash1[i] < hash2[i])? hash1[i] : hash2[i];
    }

}

char** commonChars(char** words, int wordsSize, int* returnSize) {
    if(!wordsSize){
        return NULL;
    }

    int hashTable[26] = {0};
    for(int i = 0; i < strlen(words[0]); i++){
        hashTable[words[0][i]-'a']++; 
    }

    for(int i = 0; i < wordsSize; i++){
        int newHashTable[26] = {0};
        for(int j = 0; j < strlen(words[i]); j++){
            newHashTable[words[i][j] - 'a']++; 
        }
        updateHash(hashTable, newHashTable);
    }

    *returnSize = 0;
    char** ret = (char**)malloc(sizeof(char*)* 100);

    for(int i = 0; i < 26; i++){
        if(hashTable[i]){
            for(int j =0; j < hashTable[i]; j++){
                char* tmp = (char*)malloc(sizeof(char)*2);
                tmp[0] = i + 'a';
                tmp[1] = '\0';
                ret[(*returnSize)++] = tmp;
            }
        }
    }

    return ret;
}


int main() {
    // 模擬輸入：words = ["bella", "label", "roller"]
    char *words[] = {"bella", "label", "roller"};
    int wordsSize = 3;

    // 用來接收返回結果的長度
    int returnSize = 0;

    // 呼叫你的函式
    char **result = commonChars(words, wordsSize, &returnSize);

    // 印出結果
    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("\"%s\"", result[i]);
        if (i != returnSize - 1) printf(", ");
        free(result[i]);  // 記得釋放每個字串
    }
    printf("]\n");

    free(result);  // 最後釋放整個結果陣列

    return 0;
}