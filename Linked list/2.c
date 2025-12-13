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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* fakeHead3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l3 = fakeHead3;
    fakeHead3->next = NULL;
    int sum = 0;
    int val1 = 0;
    int val2 = 0;
    int carry = 0;

    while(l1 || l2 || carry){
        val1 = (l1) ? l1->val: 0;
        val2 = (l2) ? l2->val: 0;
        sum = val1 + val2 + carry;
        carry = sum/10;

        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        newNode->val = sum%10;
        l3->next= newNode;
        l3 = l3->next;

        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;

    }

    return fakeHead3->next;

}

//很笨很笨的一版 每個每個考慮
/*
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* li1 = l1;
    struct ListNode* li2 = l2;
    struct ListNode* head3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    head3->next = NULL;
    struct ListNode* l3 = head3;
    l3->next = NULL;
    int tmp = 0;
    int carry = 0;

    while(li1 && li2){
        tmp = li1->val + li2->val + carry;
        carry = (tmp >= 10)? 1:0;
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        newNode->val = (carry) ? (tmp-10) : tmp;
        l3->next = newNode;
        li1 = li1->next;
        li2 = li2->next;
        l3 = l3->next;
    }

    while(li1){
        tmp = li1->val + carry;
        carry = (tmp >= 10)? 1:0;
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        newNode->val = (carry) ? (tmp-10) : tmp;
        l3->next = newNode;
        li1 = li1->next;
        l3 = l3->next;
    }

    while(li2){
        tmp = li2->val + carry;
        carry = (tmp >= 10)? 1:0;
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        newNode->val = (carry) ? (tmp-10) : tmp;
        l3->next = newNode;
        li2 = li2->next;
        l3 = l3->next;
    }
    if(carry){
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        newNode->val = carry;
        l3->next = newNode;
    }

    return head3->next;

}
*/

int main(){
    struct ListNode* list1 = NULL;
    struct ListNode* list2 = NULL;
    struct ListNode* list3 = NULL;
    insertAtHead(&list1, 2);
    insertAtTail(&list1, 4);
    insertAtTail(&list1, 5);
    insertAtTail(&list1, 9);
    //insertAtTail(&list1, 9);
    //insertAtTail(&list1, 9);
    //insertAtTail(&list1, 9);
    insertAtHead(&list2, 5);
    insertAtTail(&list2, 6);
    insertAtTail(&list2, 4);
    //insertAtTail(&list2, 9);
    list3 = addTwoNumbers(list1, list2);
    printList(list1);
    printList(list2);
    printList(list3);

}