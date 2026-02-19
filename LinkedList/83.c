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
    if(!head){ //head == NULL
        return NULL;
    }
    struct ListNode* curr = head;
    while(curr->next){ //curr->next != NULL
        if(curr->val == curr->next->val){
            curr->next = curr->next->next;
        }else{
            curr = curr->next;
        }
    }
    return head;

}

/*
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;

    if(!head){ //head == NULL
        return NULL;
    }

    while(slow && fast){
        while(fast->val == slow->val){
            if(fast->next){
                slow->next = fast->next;
                fast = fast->next;
            }else{
                slow->next = NULL;
                return head;
            }
            
        }
        slow = slow->next;
        fast = fast->next;
    }

    return head;
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