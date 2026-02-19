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

//題目 dumb
/*
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int size = 0;
    struct ListNode* cur = head;
    struct ListNode* pre;
    while(cur!= NULL){
        cur = cur->next;
        size++;
    }
    if(size == 1){
        free(head);
        return head;
    }
    size-=n;
    cur = head;
    if(size == 0){
        struct ListNode* tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }
    while(size-- > 0){
        pre = cur;
        cur = cur->next;
    }
    pre->next = cur->next; //若size==n(跳過上面while迴圈) 則pre會未初始
    //printf("%d\n", size);

    return head;
}
*/

//better 雙指針法
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* fakeHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    fakeHead->next = head;
    fakeHead->val = 0;
    struct ListNode* fast = fakeHead;
    struct ListNode* slow = fakeHead; 

    for(int i = 0; i <= n; i++){
        fast = fast->next;
    }

    while(fast != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    head = fakeHead->next;
    free(fakeHead);
    return head;

}

int main(){
    struct ListNode* head = NULL;
    insertAtHead(&head, 1);
    //insertAtTail(&head, 2);
    //insertAtTail(&head, 3);
    //insertAtTail(&head, 4);
    //insertAtTail(&head, 5);
    printList(head);
    removeNthFromEnd(head, 1);
    printList(head);

    return 0;
}