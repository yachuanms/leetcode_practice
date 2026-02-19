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

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next = head; //l1: dummy head for list 1
    l2->next = NULL;
    struct ListNode* cur1 = l1;
    struct ListNode* cur2 = l2;
    while(cur1 && cur1->next){
        if(cur1->next->val >= x){
            cur2->next = cur1->next;
            cur1->next = cur1->next->next;
            cur2 = cur2->next;
            //因為cur->next改變了  所以不用cur = cur->next
            //不然會少遍歷一個node
        }else{ //注意 一開始放錯位置
            cur1 = cur1->next;
        }
    }
    cur2->next = NULL;  // 斷開尾巴
    cur1->next = l2->next;

    return l1->next;
}


int main(){
    struct ListNode* head = NULL;
    insertAtHead(&head, 1);
    insertAtTail(&head, 4);
    insertAtTail(&head, 3);
    insertAtTail(&head, 2);
    insertAtTail(&head, 5);
    insertAtTail(&head, 2);
    printList(head);
    partition(head, 3);
    printList(head);


}