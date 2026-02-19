#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

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

//題目
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode* previous = NULL;
    struct ListNode* temp;
    while(cur != NULL){
        temp = cur->next;
        cur->next = previous;
        previous = cur;
        cur = temp;
    }
    return previous;
}

/*  better
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *previous = NULL;
    struct ListNode *temp;
    while(head){
        temp = head->next;
        head->next = previous;
        previous = head;
        head = temp;
    }
    return previous;
}
*/


int main(){
    struct ListNode* head = NULL;
    insertAtHead(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 4);
    insertAtTail(&head, 5);
    printList(head);
    head = reverseList(head);
    printList(head);
    return 0;
}