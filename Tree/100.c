#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

/* TODO: 你要自己實作這個函式 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    bool ans = false;
    if(!p && !q){
        return true;
    }
    if(!p || !q){
        return false;
    }

    if(p->val != q->val){
        return false;
    }

    if(p && q){
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        ans = left && right;
    }
    return ans;

};

void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    /* 測試1: 相同的樹 */
    struct TreeNode* p1 = newNode(1);
    p1->left = newNode(2);
    p1->right = newNode(3);

    struct TreeNode* q1 = newNode(1);
    q1->left = newNode(2);
    q1->right = newNode(3);

    printf("Test1 => %s (true)\n", isSameTree(p1, q1) ? "true" : "false");

    freeTree(p1);
    freeTree(q1);

    /* 測試2: 不同的樹 */
    struct TreeNode* p2 = newNode(1);
    p2->left = newNode(2);

    struct TreeNode* q2 = newNode(1);
    q2->right = newNode(2);

    printf("Test2 => %s (false)\n", isSameTree(p2, q2) ? "true" : "false");

    freeTree(p2);
    freeTree(q2);

    return 0;
}
