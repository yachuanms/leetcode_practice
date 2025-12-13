#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int count = 0;

    for(int i = len-1; i >= 0; i--){
        // 用" "會報錯
        if(s[i] != ' '){
            count++;
        }else{
            if(count != 0){
                break;
            }
        }
    }
    
    return count;
    
}

int main(){
    char str[] = "   fly me   to   the moon  ";
    printf("%s\n", str);
    int result = lengthOfLastWord(str);
    printf("%d ", result);

    return 0;
}