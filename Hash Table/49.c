#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct {
    char key[300];
    char* words[300];
    int count;
}Group;

int cmpChar(const void* a, const void* b){
    return (*(char*)a - *(char*)b);
}

void sortString(char* s){
    qsort(s, strlen(s), sizeof(char), cmpChar);
}

// 你要自己實作這個函式
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    Group groups[strsSize];
    int groupCount = 0;

    for(int i =0; i < strsSize; i++){
        int found = -1;
        char temp[300];
        strcpy(temp, strs[i]);
        sortString(temp);

        for(int g = 0; g < groupCount; g++){
            if(strcmp(temp, groups[g].key) == 0){
                found = g;
                break;
            }
        }

        if(found == -1){
            strcpy(groups[groupCount].key, temp);
            found = groupCount;
            groups[groupCount].count = 0;
            groupCount++;
        }

        groups[found].words[groups[found].count++] = strs[i];
    }

    *returnSize = groupCount;
    *returnColumnSizes = malloc(sizeof(int)*groupCount);

    char ***result = malloc(sizeof(char**)*groupCount);

    for(int g = 0; g < groupCount; g++){
        (*returnColumnSizes)[g] = groups[g].count;
        result[g] = malloc(sizeof(char*)*groups[g].count);

        for(int j = 0; j < groups[g].count; j++){
            result[g][j] = groups[g].words[j];
        }
    }

    return result;
    
}

int main() {
    char* strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    int strsSize = sizeof(strs) / sizeof(strs[0]);
    int returnSize;
    int* returnColumnSizes;

    char*** result = groupAnagrams(strs, strsSize, &returnSize, &returnColumnSizes);

    printf("Output groups (%d):\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("[ ");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("\"%s\" ", result[i][j]);
        }
        printf("]\n");
    }

    return 0;
}
