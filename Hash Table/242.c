#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
//Given two strings s and t, return true if t is an anagram of s, and false otherwise.

bool isAnagram(char* s, char* t) {
    int count[26] = {0};

    //檢查s和t的長度一不一樣 不一樣直接return false
    if(strlen(s) != strlen(t)){
        return false;
    }
    int len = strlen(s);
    //printf("Len %d\n", len);
    int sTemp = 0;
    int tTemp = 0;
    for(int i = 0; i < len; i++){
        sTemp = s[i]-97; //ASCII code a = 97 --> 0
        tTemp = t[i]-97;
        count[sTemp]++;
        count[tTemp]--;
    }

    for(int i = 0; i < 26; i++){
        if(count[i] != 0){
            return false;
        }
    }

    return true;
}


int main(){
    char s[] = "anagr";
    char t[] = "nagar";
    printf("isAnagram: %d", isAnagram(s, t));

}