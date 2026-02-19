#include<stdio.h>
#include<stdlib.h>

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

void insertAtHead(struct ListNode** head, int value){
    struct ListNode* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

void insertAtTail(struct ListNode** head, int value){
    struct ListNode* newNode = createNode(value);
    struct ListNode* cur = *head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    cur->next = newNode;
    newNode->next =NULL;
    newNode->val = value;
}

void printList(struct ListNode* head){
    struct ListNode* current = head;
    while(current != NULL){
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* fakeHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    fakeHead->next = head;
    struct ListNode* pre = fakeHead;

    while (head){
            if(head->next && head->val == head->next->val){
                while(head->next && head->val == head->next->val){
                    head = head->next;
                }
                pre->next = head->next;
            }else{
                pre = pre->next;
            }
            head = head->next;
    }
    return fakeHead->next;
}

/*
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* fakeHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    fakeHead->next = head;
    struct ListNode* pre = fakeHead;
    struct ListNode* cur = head;

    while(cur && cur->next){
        int flag = 0;
        while(cur->next && cur->val == cur->next->val){
            flag = 1;
            cur = cur->next;
        }
        if(flag){
            pre->next = cur->next;
        }else{
            pre = pre->next;
        }
        cur = cur->next;
    }
    return fakeHead->next;
}
*/

/*
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* fakeHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    fakeHead->next = head;
    struct ListNode* pre = fakeHead;
    struct ListNode* cur = head;

    while(cur){
        int flag = 0;
        while(cur->next && cur->val == cur->next->val){
            flag = 1;
            cur = cur->next;
        }
        if(flag){
            pre->next = cur->next;
        }else{
            pre = pre->next;
        }
        cur = cur->next;

    }
    return fakeHead->next;
}
*/

int main(){
    struct ListNode* head = NULL;
    insertAtHead(&head, 1);
    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 3);
    printList(head);
    deleteDuplicates(head);
    printList(head);


}