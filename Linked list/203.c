#include<stdio.h>
#include<stdlib.h>

//Given the head of a linked list and an integer val, 
//remove all the nodes of the linked list that has Node.val == val, 
//and return the new head.

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

//create dummy head better
struct ListNode* removeElements(struct ListNode* head, int target){
    struct ListNode* fakeHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    fakeHead->next = head;

    struct ListNode* current = fakeHead;

    while(current->next != NULL){
        if(current->next->val == target){
            struct ListNode* tmp = current->next;
            current->next = current->next->next;
            free(tmp);
        }
        else{
            current = current->next;
        }
    }

    struct ListNode* result = fakeHead->next;
    free(fakeHead);

    return result;

}



// 第一個很笨的方法 一個一個處裡 但格式和leetcode給的不一樣
/*
struct ListNode* removeElements(struct ListNode* head, int target){

    //單獨處理頭節點
    while(head != NULL && head->val == target){
        struct ListNode* tmp = head;
        head = head->next;
        free(tmp);
    }

    struct ListNode* cur = head;
    while(cur != NULL && cur->next != NULL){
        if(cur->next->val == target){
            struct ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            free(tmp);
        }else{
            cur = cur->next;
        }
    }

    return head;

}
*/

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


int main(){
    struct ListNode* head = NULL;
    //test 1 successed
    insertAtHead(&head, 6);
    insertAtHead(&head, 5);
    insertAtHead(&head, 4);
    insertAtHead(&head, 3);
    insertAtHead(&head, 6);
    insertAtHead(&head, 4);
    insertAtHead(&head, 1);

    printf("head is %d \n", removeElements(head, 4)->val);
    printList(head);

}