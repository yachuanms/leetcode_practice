#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char* s, int sSize) {
    int i = 0;
    int len = sSize-1;
    char temp;
    while(i < len){
        temp = s[i];
        s[i++] = s[len];
        s[len--] = temp;
    }  
}

char* reverseStr(char* s, int k){
    int i  = 0;
    int count = 0;
    while(s[i++] != '\0'){
        count++;
    }
    printf("count: %d\n", count);
    i = 0;
    while(count >= 2*k){
        reverseString(s+i, k);
        count-= 2*k;
        i += 2*k;
    }
    if (count >= k) {
        reverseString(s + i, k);
    } else {
        reverseString(s + i, count);
    }
    return s;
}

int main() {
    char input[] = "abcdefg";
    printf("Input: \"%s\"\n", input);
    int k = 8;
    // 因為 reverseStr 可能會修改字串，傳進去的是可以改的 char*
    char* result = reverseStr(input, k);

    printf("Result: \"%s\"\n", result);

    // 如果你有用 malloc 的話，要記得釋放記憶體
    // free(result);

    return 0;
}
