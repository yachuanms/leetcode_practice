#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s){
    int len = strlen(s);
    char* stack = malloc(sizeof(char)*len);
    int idx = -1;//上一個位置 要先++

    for(int i = 0; i < len; i++){
        if(s[i]== '(' || s[i]=='[' || s[i]=='{'){
            stack[++idx] = s[i];
        }
        else if(s[i] == ')' || s[i] == ']' || s[i]=='}'){
            if(idx<0){
                free(stack);
                return false;
            }
            else if(idx >= 0){
                if(s[i]==')' && stack[idx] != '('){
                    free(stack);
                    return false;
                }
                if(s[i]==']' && stack[idx] != '['){
                    free(stack);
                    return false;
                }
                if(s[i]=='}' && stack[idx] != '{'){
                    free(stack);
                    return false;
                }
                idx--;
            }
        }
    }
    //idx == -1代表沒配對完
    free(stack);
    return idx == -1;
}

int main() {
    printf("Test 1: %d\n", isValid("([]){"));     // 預期 0
    printf("Test 2: %d\n", isValid("()[]{}"));    // 預期 1
    printf("Test 3: %d\n", isValid("(]"));        // 預期 0
    printf("Test 4: %d\n", isValid("([)]"));      // 預期 0
    printf("Test 5: %d\n", isValid("{[]}"));      // 預期 1
    printf("Test 6: %d\n", isValid("]"));         // 預期 0
    printf("Test 7: %d\n", isValid(""));          // 預期 1（空字串算有效）
    return 0;
}
