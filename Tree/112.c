#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(!root){
        return false;
    }
    if(!root->left && !root->right){
        return targetSum== root->val;
    }

    return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
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


    // --- Path Sum (112) ---
    int target = 7;
    bool hasPath = hasPathSum(root, target);
    printf("Has path sum %d? %s\n", target, hasPath ? "true" : "false");

    return 0;
}
