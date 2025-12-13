#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

//20. Valid Parentheses

bool isValid(char* s){
    int top = -1;
    int len =strlen(s);
    char stack[len];

    for(int i = 0; i < len; i++){
        if (s[i]== '{' || s[i]== '[' ||s[i]== '('){
            stack[++top] = s[i];
            continue;
        }
        if(top == -1){
            return false;
        }
        char pre = stack[top--];
        
        if((s[i] == '}' && pre != '{') || (s[i] == ']' && pre != '[') || (s[i] == ')' && pre != '(')){
            return false;
        }
    }
    return true;

}

int main() {
    printf("%d\n", isValid("()"));       // 1
    printf("%d\n", isValid("()[]{}"));   // 1
    printf("%d\n", isValid("(]"));       // 0
    printf("%d\n", isValid("([)]"));     // 0
    printf("%d\n", isValid("{[]}"));     // 1
    return 0;
}