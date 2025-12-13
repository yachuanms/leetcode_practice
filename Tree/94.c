#include <stdio.h>
#include <stdlib.h>

// --- TreeNode structure ---
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// --- Function declaration ---
void dfs(struct TreeNode* node, int* arr, int* idx){
    if(!node){
        return;
    }

    dfs(node->left, arr, idx);
    arr[*idx] = node->val;
    (*idx)++;
    dfs(node->right, arr, idx); 
}



int* inorderTraversal(struct TreeNode* root, int* returnSize){
   int* arr = malloc(sizeof(int)*256);
   *returnSize = 0;
   dfs(root, arr, returnSize);
   return arr;
}

int main() {
    // 建立測試樹：
    //        1
    //         \
    //          2
    //         /
    //        3
    struct TreeNode* root = newNode(1);
    root->right = newNode(2);
    root->right->left = newNode(3);

    int returnSize;
    int* result = inorderTraversal(root, &returnSize);

    printf("Inorder Traversal: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // 若你在程式中用 malloc，記得釋放記憶體
    free(result);
    return 0;
}
