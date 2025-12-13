#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 函式宣告
char* longestCommonPrefix(char** strs, int strsSize){
    char* ret = malloc(sizeof(char)*200);
    int ptr = 0;
    int len = strlen(strs[0]);
    //用strs[0]當基準跟大家比
    //只比前綴 不是substring!!!!
    for(int i = 0; i < len; i++){
        for(int j = 0; j < strsSize; j++){
            if(strs[j][i] == '\0' || strs[j][i] != strs[0][i]){
                ret[ptr] = '\0';
                return ret;
            }
        }
        ret[ptr++] = strs[0][i];
    }

    ret[ptr] = '\0';
    return ret;
}

int main() {
    char* test1[] = {"flower", "flow", "flight"};
    char* test2[] = {"dog", "racecar", "car"};
    char* test3[] = {"interview", "internet", "internal", "interval"};
    char* test4[] = {"a"};
    char* test5[] = {"ab", "a"};

    char* result;

    printf("Test 1: %s\n", result = longestCommonPrefix(test1, 3));
    printf("Result: \"%s\"\n\n", result);

    printf("Test 2: %s\n", result = longestCommonPrefix(test2, 3));
    printf("Result: \"%s\"\n\n", result);

    printf("Test 3: %s\n", result = longestCommonPrefix(test3, 4));
    printf("Result: \"%s\"\n\n", result);

    printf("Test 4: %s\n", result = longestCommonPrefix(test4, 1));
    printf("Result: \"%s\"\n\n", result);

    printf("Test 5: %s\n", result = longestCommonPrefix(test5, 2));
    printf("Result: \"%s\"\n", result);

    return 0;
}
