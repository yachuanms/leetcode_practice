#include<stdio.h>
#include<stdlib.h>

//Given the head of a linked list, return the node where the cycle begins. 
//If there is no cycle, return null.

typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

struct ListNode* createNode(int value){
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}


struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        //如果相遇代表有環  再進一步找環的入口
        if(slow == fast){
            struct ListNode* index1 = fast;
            struct ListNode* index2 = head;
            while(index1 != index2){
                index1 = index1->next;
                index2 = index2->next;
            }
            return index1;
        }
    }
    return NULL;
    
}

void printList(struct ListNode* head){
    struct ListNode* current = head;
    while(current != NULL){
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
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

    printf("%d \n", detectCycle(node0)->val);

    
}