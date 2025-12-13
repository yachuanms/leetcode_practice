#include <stdio.h>
#include <stdbool.h>
#include<string.h>

// 函式宣告，讓你自己寫
bool isAnagram(char* s, char* t){
    int count[26];
    memset(count, 0, sizeof(count));
    

    int lens = strlen(s);
    int lent = strlen(t);

    if(lens != lent){
        return false;
    }

    for(int i =0; i < lens; i++){
        int index = s[i]-'a';
        count[index]++;
    }

    for(int i = 0; i <lent; i++){
        int index = t[i]-'a';
        count[index]--;
    }


    for(int i = 0; i < 26; i++){
        if(count[i] != 0){
            return false;
        }
    }

    return true;
}

int main() {
    char s1[] = "anagram";
    char t1[] = "nagaram";
    //printf("Test 1: %s\n", isAnagram(s1, t1) ? "true" : "false");

    char s2[] = "rat";
    char t2[] = "car";
    //printf("Test 2: %s\n", isAnagram(s2, t2) ? "true" : "false");

    char s3[] = "aacc";
    char t3[] = "ccac";
    //printf("Test 3: %s\n", isAnagram(s3, t3) ? "true" : "false");

    char s4[] = "ggii";
    char t4[] = "eekk";
    printf("Test 4: %s\n", isAnagram(s4, t4) ? "true" : "false");

    return 0;
}
