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

//題目 自己寫的第一版 和bubble sort一樣爛
/*
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* ptrA = headA;
    struct ListNode* ptrB = headB;

    while(ptrA != NULL ){
        while(ptrB != NULL){
            if(ptrA == ptrB){
                return ptrA;
            }else{
                ptrB = ptrB->next;
            }
        }
        ptrB = headB;
        ptrA = ptrA->next;
    }
    return NULL;
}
*/

/*
struct ListNode* *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* ptrA = headA;
    struct ListNode* ptrB = headB;
    int lenA = 0, lenB = 0;

    while(ptrA != NULL){
        lenA++;
        ptrA = ptrA->next;
    }
    while(ptrB != NULL){
        lenB++;
        ptrB = ptrB->next;
    }

    ptrA = headA;
    ptrB = headB;

    if(lenA > lenB){
        for(int i = 0; i < (lenA-lenB); i++){
            ptrA = ptrA->next;
        }
    }else if(lenB > lenA){
        for(int i = 0; i < (lenB-lenA); i++){
            ptrB = ptrB->next;
        }
    }

    while(ptrA!= NULL && ptrB!= NULL){
        if(ptrA == ptrB){
            return ptrA;
        }
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }
    return NULL;
}
*/

//chatGPT thought
//一開始各走各自的 linked list
//當指標走到尾端時，不要停下來，而是切換去走對方的 linked list。
//兩個指標會在相遇的時候剛好同步  如果沒有交點，兩個指標最後都會變成 NULL，同時停下來
/*  但自己寫的還是很長  底下chatGPT簡化版本 超聰明
struct ListNode* getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* ptrA = headA;
    struct ListNode* ptrB = headB;

    while(ptrA != NULL || ptrB != NULL){
        if(ptrA == ptrB){
            return ptrA;
        }else if(ptrA == NULL){
            ptrA = headB;
            continue;
        }else if(ptrB == NULL ){
            ptrB = headA;
            continue;
        }
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }
    return NULL;
}
*/

struct ListNode* getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* ptrA = headA;
    struct ListNode* ptrB = headB;

    while(ptrA != ptrB){
        if(ptrA == NULL){
            ptrA = headB;
        }else{
            ptrA = ptrA->next;
        }
        if(ptrB == NULL){
            ptrB = headA;
        }else{
            ptrB = ptrB->next;
        }
    }
    return ptrA;

}

//沒改成和題目描述一樣的程式 
//basic function不同
int main(){
    struct ListNode* listA = NULL;
    struct ListNode* listB = NULL;
    insertAtHead(&listA, 4);
    insertAtTail(&listA, 1);
    insertAtTail(&listA, 8);
    insertAtTail(&listA, 4);
    insertAtTail(&listA, 5);
    printList(listA);

    insertAtHead(&listB, 5);
    insertAtTail(&listB, 6);
    insertAtTail(&listB, 1);
    insertAtTail(&listB, 8);
    insertAtTail(&listB, 4);
    insertAtTail(&listB, 5);
    printList(listB);

}