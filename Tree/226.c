#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root) {
    if(!root){
        return NULL;
    }
    struct TreeNode* left = invertTree(root->left);
    struct TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

//for testing

/* 建立新節點 */
struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

/* 前序列印樹 */
void printTree(struct TreeNode* root) {
    if (!root) return;
    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);
}

/* 釋放樹記憶體 */
void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

/* 測試 main */
int main(void) {
    /*
          4
         / \
        2   7
       / \ / \
      1  3 6  9
    */
    struct TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(9);

    printf("Before invert (preorder): ");
    printTree(root);
    printf("\n");

    invertTree(root);

    printf("After invert (preorder):  ");
    printTree(root);
    printf("\n");

    freeTree(root);
    return 0;
}