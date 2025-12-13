#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int v) {
    struct TreeNode* n = malloc(sizeof(struct TreeNode));
    n->val = v;
    n->left = n->right = NULL;
    return n;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if(!root){
        *returnSize =0;
        return NULL;
    }

    int front = 0; 
    int rear = 0;
    int **res = malloc(sizeof(int*)*2000);
    *returnColumnSizes = malloc(sizeof(int)*2000);
    *returnSize = 0;

    struct TreeNode* queue[2000];
    queue[rear++] = root;
    while(front < rear){
        int levelSize = rear - front;
        res[*returnSize] = malloc(sizeof(int)*levelSize);
        (*returnColumnSizes)[*returnSize] = levelSize;
        

        for(int i = 0; i < levelSize; i++){
            struct TreeNode* node = queue[front++];
            res[*returnSize][i] = node->val;
            if(node->left){
                queue[rear++] = node->left;
            }
            if(node->right){
                queue[rear++] = node->right;
            }
        }
        //* 優先級 低於 ++
        //所以要記得加括號
        (*returnSize)++;
    }
    return res;

}

int main(void) {
    // 建立樹: [3,9,20,null,null,15,7]
    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    int returnSize;
    int* returnColumnSizes;
    int** res = levelOrder(root, &returnSize, &returnColumnSizes);

    // 輸出結果
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", res[i][j]);
            if (j + 1 < returnColumnSizes[i]) printf(", ");
        }
        printf("]\n");
    }

    return 0;
}