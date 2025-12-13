//104. Maximum Depth of Binary Tree (Easy)
#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    if(!root){
        return 0;
    }
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return (left>right?left:right)+1;
    
}