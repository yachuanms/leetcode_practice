#include<stdio.h>
#include<stdlib.h>

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

int main() {
    char str[] = {'h','e','l','l','o'};
    int len = sizeof(str) / sizeof(str[0]);

    printf("Before reverse: ");
    for (int i = 0; i < len; i++) {
        printf("%c", str[i]);
    }
    printf("\n");

    reverseString(str, len);

    printf("After reverse: ");
    for (int i = 0; i < len; i++) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}
