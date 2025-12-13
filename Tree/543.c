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

//只回傳當點樹高
//diameter用指標存
int dfs(struct TreeNode* node, int* diameter){
    if(!node){
        return 0;
    }

    int leftH = dfs(node->left, diameter);
    int rightH = dfs(node->right, diameter);
    if(leftH+rightH > *diameter){
        *diameter = leftH+rightH;
    }

    return (leftH>rightH)?leftH:rightH+1;

}


// --- Function declaration ---
int diameterOfBinaryTree(struct TreeNode* root){
    int diameter = 0;
    dfs(root, &diameter);
    return diameter;
}

// --- Main test ---
int main() {
    // 建立測試樹：
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    struct TreeNode* root = newNode(1);
    int result = diameterOfBinaryTree(root);
    printf("Diameter of binary tree: %d\n", result); 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    result = diameterOfBinaryTree(root);
    printf("Diameter of binary tree: %d\n", result);  // 預期輸出 3
    return 0;
}
