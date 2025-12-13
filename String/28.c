#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* TODO: 由妳來完成 */
int strStr(char* haystack, char* needle){
    int lenh = strlen(haystack);
    int lenn = strlen(needle);

    if(lenn > lenh){
        return -1;
    }

    if(lenn == 0){
        return 0;
    }

    int ptrh = 0;
    int ptrn = 0;

    int ret = -1;

    while (ptrh < lenh){
        int start = ptrh;

        while(ptrn < lenn && start < lenh){
            if(haystack[start] == needle[ptrn]){
                start ++;
                ptrn ++;
            }else{
                break;
            }
        }

        if(ptrn == lenn){
            ret = ptrh;
            return ptrh;
        }

        ptrn = 0;
        ptrh ++;
    }

    return ret;

}

int main(void) {
    char s1[] = "hello";
    char t1[] = "ll";
    printf("Test1: %s, %s → %d\n", s1, t1, strStr(s1, t1)); // 2

    char s2[] = "aaaaa";
    char t2[] = "bba";
    printf("Test2: %s, %s → %d\n", s2, t2, strStr(s2, t2)); // -1

    char s3[] = "abc";
    char t3[] = "c";
    printf("Test3: %s, %s → %d\n", s3, t3, strStr(s3, t3)); // 2

    char s4[] = "mississippi";
    char t4[] = "issi";
    printf("Test4: %s, %s → %d\n", s4, t4, strStr(s4, t4)); // 1

    char s5[] = "a";
    char t5[] = "";
    printf("Test5: %s, %s → %d\n", s5, t5, strStr(s5, t5)); // 0

    return 0;
}
