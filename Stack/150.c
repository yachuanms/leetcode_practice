#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
LeetCode signature:
int evalRPN(char **tokens, int tokensSize);
*/
int evalRPN(char **tokens, int tokensSize) {
    // 不用malloc 因為不會回傳 stack
    int stack[tokensSize];
    int top = -1;
    for(int i = 0; i < tokensSize; i++){
        char* t = tokens[i];

        //❌ 只看第一個字元 " -11 " 也會被當成運算子
        //❌ 用 isdigit(t[0]) "-11" 第一個字元是 '-'
        //❌ 用 atoi 判斷是不是 0
        if(strlen(t) == 1 && (t[0] == '+' || t[0]=='-' || t[0]== '*' || t[0] == '/')){
            int a = stack[top--]; // right
            int b = stack[top--]; // left
            if(t[0] == '+'){
                stack[++top] = a + b;
            }else if(t[0] == '-'){
                stack[++top] = b - a;
            }else if(t[0] == '*'){
                stack[++top] = a*b;
            }else if(t[0] == '/'){
                stack[++top] = b/a;//除法順序有差!!!
            }
        }else{
            int val = atoi(t);
            stack[++top] = val;
        }
    }
    return stack[top];
}

/*************** 本機測試 main（LeetCode 交作業時刪掉 main） ***************/
int main() {
    // Example 1: ["2","1","+","3","*"] => 9
    char *tokens1[] = {"2","1","+","3","*"};
    printf("ans1 = %d (expect 9)\n", evalRPN(tokens1, 5));

    // Example 2: ["4","13","5","/","+"] => 6 (13/5 = 2)
    char *tokens2[] = {"4","13","5","/","+"};
    printf("ans2 = %d (expect 6)\n", evalRPN(tokens2, 5));

    // Example 3: ["10","6","9","3","+","-11","*","/","*","17","+","5","+"] => 22
    char *tokens3[] = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    printf("ans3 = %d (expect 22)\n", evalRPN(tokens3, 13));

    // Division toward zero sanity check: ["-7","3","/"] => -2
    char *tokens4[] = {"-7","3","/"};
    printf("ans4 = %d (expect -2)\n", evalRPN(tokens4, 3));

    return 0;
}
