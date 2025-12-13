#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>


bool isValid(char* s) {
    int n = strlen(s);
    char stack[n];
    int top = -1;

    for(int i = 0; i < n ; i++){
        char now = s[i];
        if(now == '(' || now == '[' || now == '{'){
            stack[++top] = now;
        }else{
            if(top == -1){
                return false;
            }
            char pre = stack[top--];
            if((now == ')' && pre != '(') ||(now == ']' && pre != '[')||(now == '}' && pre != '{')){
                return false;
            }
        }
    }

    if(top == -1){
        return true;
    }
    return false;
    
}

int main() {
    printf("%d\n", isValid("()"));       // 1
    printf("%d\n", isValid("()[]{}"));   // 1
    printf("%d\n", isValid("(]"));       // 0
    printf("%d\n", isValid("([)]"));     // 0
    printf("%d\n", isValid("{[]}"));     // 1
    return 0;
}