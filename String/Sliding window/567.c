#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

bool checkInclusion(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int freq1[26] = {0};
    int freq2[26] = {0};

    for(int i = 0; i < len1; i++){
        freq1[s1[i]-'a']++;
        freq2[s2[i]-'a']++;

    }

    if(memcmp(freq1, freq2, 26*sizeof(int))==0){
        return true;
    }

    for(int i = len1; i< len2; i++){
        freq2[s2[i-len1]-'a']--;
        freq2[s2[i]-'a']++;
        if(memcmp(freq1, freq2, 26*sizeof(int))==0){
            return true;
        }
    }
    return false;

}

int main() {
    char s1_1[] = "ab";
    char s2_1[] = "eidbaooo";
    printf("Test1: %s -> %s : %s\n", s1_1, s2_1, 
           checkInclusion(s1_1, s2_1) ? "true" : "false");
           //true

    char s1_2[] = "ab";
    char s2_2[] = "eidboaoo";
    printf("Test2: %s -> %s : %s\n", s1_2, s2_2, 
           checkInclusion(s1_2, s2_2) ? "true" : "false");
            //false

    char s1_3[] = "adc";
    char s2_3[] = "dcda";
    printf("Test3: %s -> %s : %s\n", s1_3, s2_3, 
           checkInclusion(s1_3, s2_3) ? "true" : "false");
           //true

    return 0;
}
