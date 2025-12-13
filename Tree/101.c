#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isMirror(struct TreeNode* left, struct TreeNode* right){
    
    //兩邊空
    if(!left && !right){
        return true;
    }
    //一邊空
    if(!left || !right){
        return true;
    }
    //還有東西
    if(left->val == right->val){
        return isMirror(left->left, right->right) && isMirror(right->left, left->right);
    }
    return false;
    
}


bool isSymmetric(struct TreeNode* root) {
    if(!root){
        return true;
    }

    return isMirror(root->left, root->right);
}

//for testing

/* 建立新節點 */
struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}



int main() {
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    // --- Symmetric Tree (101) ---
    bool result = isSymmetric(root);
    printf("Symmetric? %s\n", result ? "true" : "false");

    return 0;
}
