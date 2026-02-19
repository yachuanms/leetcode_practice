#include<stdio.h>
#include<stdlib.h>

//Given a linked list, swap every two adjacent nodes and return its head. 
//You must solve the problem without modifying the values in the list's nodes 
//(i.e., only nodes themselves may be changed.)

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

/*
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* fakeHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    fakeHead->next = head;
    struct ListNode* pre = head;
    struct ListNode* check = head;
    struct ListNode* gPre = fakeHead;
    struct ListNode* gStart = head;
    struct ListNode* cur=head;
    struct ListNode* next=NULL;
    while(gPre->next){
        //1. 檢查是否有k個node可以反轉
        check = gPre->next;
        for(int i = 0; i < k; i++){
            if(!check){
                return fakeHead->next;
            }
            check =check->next;//gEnd
        }
        pre = gPre->next;
        gStart = gPre->next;
        cur = (pre) ? pre->next : NULL;
        for(int i = 0; i < k-1; i++){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        gPre->next = pre;
        gStart->next = cur;
        gPre = gStart;
        gStart = next;
    }
    return fakeHead->next;

}
*/

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if(!head || k<= 1){
        return head;
    }

    struct ListNode* fakeHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    fakeHead->next = head;

    struct ListNode* gPre = fakeHead;
    struct ListNode* check = gPre;
    struct ListNode* cur, *tail, *next, *pre;

    while(1){
        check = gPre;
         // 1. 檢查是否還有 k 個節點
        for(int i = 0; i < k && check; i++){
            check = check->next;
        }
        if(!check){
            break;
        }
        pre = NULL;
        cur = gPre->next;
        tail = cur;
        
        // 2. 反轉 k 個節點
        for(int i = 0 ; i< k; i++){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        // 3. 接回來
        gPre->next = pre;
        tail->next = cur;
        gPre = tail;

    }

    return fakeHead->next;
}

int main(){
    struct ListNode* head = NULL;
    insertAtHead(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 4);
    //insertAtTail(&head, 5);
    printList(head);
    reverseKGroup(head, 3);
    printf("after swapping pairs: \n");
    printList(head);

    return 0;
}