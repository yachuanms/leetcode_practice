#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpChar(const void* a, const void* b) {
   return *(char*)a - *(char*)b;
}

char* orderlyQueue(char* s, int k){
    int len = strlen(s);
    if(len <= 1){
        return s;
    }
    if(k == 1){
        char* best = malloc(sizeof(char)*(len+1));
        char* rotate = malloc(sizeof(char)*(len+1));
        strcpy(best, s);
        for(int i = 1; i < len; i++){
            memcpy(rotate, s+i, len-i);
            memcpy(rotate+len-i, s, i);
            rotate[len] = '\0';
            if(strcmp(rotate, best)<0){
                strcpy(best, rotate);
            }
        }
        strcpy(s, best);
        free(best);
        free(rotate);
        
    }else{
        qsort(s, len, sizeof(char), cmpChar);
    }
    return s;
}

int main() {
    char s1[] = "cba";
    char s2[] = "baaca";
    char s3[] = "a";
    char s4[] = "zzxy";

    printf("Input: s=\"%s\", k=1 -> Output: \"%s\"\n", s1, orderlyQueue(s1, 1));
    printf("Input: s=\"%s\", k=3 -> Output: \"%s\"\n", s2, orderlyQueue(s2, 3));
    printf("Input: s=\"%s\", k=1 -> Output: \"%s\"\n", s3, orderlyQueue(s3, 1));
    printf("Input: s=\"%s\", k=2 -> Output: \"%s\"\n", s4, orderlyQueue(s4, 2));

    return 0;
}
