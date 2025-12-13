#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

//Given head, the head of a linked list, determine if the linked list has a cycle in it.

bool hasCycle(struct ListNode *head) {
    if(!head || !head->next){
        return false;
    }

    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }

    return false;
}

int main(){
    struct ListNode *node0 = (struct ListNode*)malloc(sizeof(struct ListNode));
    node0->val = 3;
    struct ListNode *node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    node1->val = 2;
    struct ListNode *node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    node2->val = 0;
    struct ListNode *node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    node3->val = -4;
    node0->next =node1;
    node1->next = node2;
    node2->next = node3;
    node3->next =node1;
    printf("%d", hasCycle(node0));
    
}