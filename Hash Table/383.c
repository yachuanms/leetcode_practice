#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*
给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，
判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。
如果可以构成，返回 true ；否则返回 false。

(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，
组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)
*/

bool canConstruct(char* ransomNote, char* magazine) {
    int hashMap[26] = {0};
    int i = 0;
    while(magazine[i] != '\0'){
        hashMap[magazine[i++]-'a']++;
    }
    i = 0;
    while(ransomNote[i] != '\0'){
        hashMap[ransomNote[i++]-'a']--;
    }
    for(int i = 0; i < 26; i++){
        printf("%d \n", hashMap[i]);
        if (hashMap[i] < 0){
            printf("false\n");
            return false;
        }
    }
    printf("true\n");
    return true;
}

int main(){
    char* ransonNote = "aa";
    char* magazine = "aabb";
    printf("%d", magazine[0]);
    canConstruct(ransonNote, magazine);
}