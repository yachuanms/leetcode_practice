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


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* fakeHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    fakeHead->next = NULL;
    struct ListNode* l1 = list1;
    struct ListNode* l2 = list2;
    struct ListNode* tmp = fakeHead;
    while(l1 && l2){
        if(l1->val <= l2->val){
            tmp->next = l1;
            l1 = l1->next;
        }else{
            tmp->next = l2;
            l2 = l2->next;
        }
        tmp = tmp->next;
    }

    tmp->next = l1?l1:l2;
    return fakeHead->next;
    
}


int main(){
    struct ListNode* head1 = NULL;
    struct ListNode* head2 = NULL;
    insertAtHead(&head1, 1);
    insertAtTail(&head1, 2);
    insertAtTail(&head1, 4);
    insertAtHead(&head2, 1);
    insertAtTail(&head2, 3);
    insertAtTail(&head2, 4);
    printList(mergeTwoLists(head1, head2));
    return 0;
}