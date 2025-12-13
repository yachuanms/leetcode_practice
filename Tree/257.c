#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//Given the root of a binary tree, 
//return all root-to-leaf paths in any order.

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//helper function
void dfs(struct TreeNode* node, char* path, char** res, int* returnSize){
    if(!node){
        return;
    }
    char newPath[256];
    if(strlen(path) == 0){
        sprintf(newPath, "%d", node->val);
    }else{
        sprintf(newPath, "%s->%d", path, node->val);
    }

    if(!node->left && !node->right){
        res[*returnSize] = malloc(strlen(newPath)+1);
        strcpy(res[*returnSize], newPath);
        (*returnSize)++;
        return;
    }

    dfs(node->left, newPath, res, returnSize);
    dfs(node->right, newPath, res, returnSize);

}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char** res = malloc(sizeof(char*)*256);
    if(!root){
        return res;
    }
    char path[256] = ""; //dfs 裡面%s 能正常印它
    *returnSize =0;
    dfs(root, path, res, returnSize);
    return res;

}


// --- 結構定義與建立函式 ---

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}


int main() {
    // 建立測資樹：
    //        1
    //       / \
    //      2   3
    //       \
    //        5
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);

    int returnSize;
    char **paths = binaryTreePaths(root, &returnSize);

    printf("Paths found: %d\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", paths[i]);
    }

    // 若有 malloc，在實作中記得釋放
    return 0;
}
