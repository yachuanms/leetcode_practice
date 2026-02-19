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

    struct ListNode* rotateRight(struct ListNode* head, int k) {
        struct ListNode* tail = head;
        struct ListNode* newHead;
        if(!head || !head->next || k == 0){
            return head;
            //空list 只有一點 和不用轉
        }
        //找總長和把linked list變環
        int length = 1;
        while(tail->next){
            length++;
            tail = tail->next;
        }
        tail->next = head;

        //可以少走很多次迴圈
        if(k >= length){
            k = k%length;  
        }

        for(int i = 0; i < (length-k); i++){
            tail = tail->next;
        }

        newHead = tail->next;
        tail->next = NULL;
        return newHead;
    }


int main(){
    struct ListNode* head = NULL;
    struct ListNode* newHead = NULL;
    insertAtHead(&head, 0);
    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    //insertAtTail(&head, 4);
    //insertAtTail(&head, 5);
    printList(head);
    newHead = rotateRight(head, 4);
    printList(newHead);


}