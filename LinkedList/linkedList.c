#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};  //記得加分號

struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode; 
}

void insertAtHead(struct Node** head, int value){
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

void insertAtTail(struct Node** head, int value){
    struct Node* newNode = createNode(value);

    // 情況1：如果是空的 list
    if(*head == NULL){
        *head = newNode;
        return;
    }

    // 情況2：找最後一個節點
    struct Node* current = *head;
    while (current->next != NULL){
        current = current->next;
        //還有下一個就直接跳下一個
    }

    current->next = newNode;
}

void deleteNode(struct Node** head, int target){
    struct Node* current = *head;
    struct Node* previous = NULL;

    // 空 list，什麼都不做
    if(current == NULL) return;

    // 如果要刪的是第一個節點
    if(current->data == target){
        *head = current->next;
        free(current);
        return;
    }

    // 其他情況：從第二個節點開始找
    while(current != NULL && current->data != target){
        previous = current;
        current = current->next;
    }

    // 找不到
    if(current == NULL) return;

    // 找到了，從串列中移除並釋放記憶體
    previous->next = current->next;
    free(current);
}

void printList(struct Node* head){
    struct Node* current = head;
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int search(struct Node* head, int target){
    struct Node* current = head;
    while(current != NULL){
        if(current->data == target){
            return 1;
        }
        current = current->next;
    }
    return 0;

}

int main(){
    struct Node* head = NULL;
    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtHead(&head, 30);
    insertAtHead(&head, 10);
    insertAtTail(&head, 40);
    insertAtTail(&head, 50);
    deleteNode(&head, 10);
    printList(head);
    printf("search for 10: %s\n", search(head, 10) ? "Y" : "N");
    printf("search for 40: %s\n", search(head, 40) ? "Y" : "N");
    return 0;
}