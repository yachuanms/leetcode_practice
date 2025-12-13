#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 預留你要實作的函式
char* reverseWords(char* s){
    int r = 0;
    int i = strlen(s)-1;
    char* result = (char*)malloc(sizeof(char)*(i+2));
    int word_end, word_start;
    while(i >= 0){
        while(i>=0 && s[i]==' '){
            i--;
        }
        word_end = i;
        if(i<0){
            break;
        }
        while(i>=0 && s[i] != ' '){
            i--;
        }
        
        word_start = i+1;
        //printf("start %d, end %d \n", word_start, word_end);
        for(int j = word_start; j <= word_end; j++){
            result[r++] = s[j];
        }
        result[r++] = ' ';
        
    }

    if (r > 0 && result[r-1] == ' ') r--;
    result[r]='\0';
    return result;
}

int main() {
    // 測資 1
    char input1[] = "the sky is blue";
    char* result1 = reverseWords(input1);
    printf("\nInput: \"%s\"\n", "the sky is blue");
    printf("Output: \"%s\"\n\n", result1);

    // 測資 2
    char input2[] = "  hello world!  ";
    char* result2 = reverseWords(input2);
    printf("Input: \"%s\"\n", "  hello world!  ");
    printf("Output: \"%s\"\n\n", result2);

    // 測資 3
    char input3[] = "a good   example";
    char* result3 = reverseWords(input3);
    printf("Input: \"%s\"\n", "a good   example");
    printf("Output: \"%s\"\n\n", result3);

    return 0;
}
