#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* addBinary(char* a, char* b) {
    int lena = strlen(a);
    int lenb = strlen(b);
    int ptra = lena-1;
    int ptrb = lenb-1;
    int maxlen= ((lena>lenb)?lena:lenb)+2;//進位和'\0'
    char* ret = malloc(sizeof(char)*maxlen);
    int ptrc = 0;
    int carry = 0;


    while(ptra >= 0 || ptrb >= 0 || carry){
        int abit = (ptra >= 0 && a[ptra--]=='1')?1:0;
        int bbit = (ptrb >= 0 && b[ptrb--]=='1')?1:0;

        int sum = abit + bbit + carry;
        ret[ptrc++] = (sum%2)+'0';
        carry = sum /2;

    }

    ret[ptrc] = '\0';

    char* reverse = malloc(sizeof(char)*maxlen);

    for(int i = 0; i < ptrc; i++){
        reverse[i] = ret[ptrc-1-i];//先扣掉'\0'
    }
    reverse[ptrc] = '\0';

    free(ret);
    return reverse;
    
}

int main(void) {
    char a1[] = "11";
    char b1[] = "1";
    printf("Test1: %s + %s = %s\n", a1, b1, addBinary(a1, b1));

    char a2[] = "1010";
    char b2[] = "1011";
    printf("Test2: %s + %s = %s\n", a2, b2, addBinary(a2, b2));

    char a3[] = "0";
    char b3[] = "0";
    printf("Test3: %s + %s = %s\n", a3, b3, addBinary(a3, b3));

    return 0;
}
