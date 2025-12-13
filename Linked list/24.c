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

//題目  自己獨力寫完了一題完全沒看 嘿嘿
struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL ){
        return head;
    }
    struct ListNode* cur = head->next;
    struct ListNode* pre = head;
    int tmp;
    while(cur != NULL && pre!= NULL){
        tmp = cur->val;
        cur->val = pre->val;
        pre->val = tmp;
        pre = cur->next;
        if(pre != NULL){
            cur = pre->next;
        }
    }
    
    return head;
}

/*
//递归版本
struct ListNode* swapPairs(struct ListNode* head){
    //递归结束条件：头节点不存在或头节点的下一个节点不存在。此时不需要交换，直接返回head
    if(!head || !head->next)
        return head;
    //创建一个节点指针类型保存头结点下一个节点
    struct ListNode *newHead = head->next;
    //更改头结点+2位节点后的值，并将头结点的next指针指向这个更改过的list
    head->next = swapPairs(newHead->next);
    //将新的头结点的next指针指向老的头节点
    newHead->next = head;
    return newHead;
}
//迭代版本
struct ListNode* swapPairs(struct ListNode* head){
    //使用双指针避免使用中间变量
    typedef struct ListNode ListNode;
    ListNode *fakehead = (ListNode *)malloc(sizeof(ListNode));
    fakehead->next = head;
    ListNode* right = fakehead->next;
    ListNode* left = fakehead;
    while(left && right && right->next ){
        left->next = right->next;
        right->next = left->next->next;
        left->next->next = right;
        left = right;
        right = left->next;
    }
    return fakehead->next;
}
*/

int main(){
    struct ListNode* head = NULL;
    insertAtHead(&head, 1);
    //insertAtTail(&head, 2);
    //insertAtTail(&head, 3);
    //insertAtTail(&head, 4);
    printList(head);
    swapPairs(head);
    printf("after swapping pairs: \n");
    printList(head);

    return 0;
}