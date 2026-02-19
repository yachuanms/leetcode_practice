#include<stdio.h>
#include<stdlib.h>

//自己加的function
typedef struct Node{
    int val;
    struct Node* next;
}Node;

typedef struct {
    int size;
    Node* data;
    
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    Node *head = (Node*)malloc(sizeof(Node));
    head->next = (void*)0;
    obj->size = 0;
    obj->data = head;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index < 0 || index >= obj->size){
        return -1;
    }

    Node *cur = obj->data;
    while(index-- >= 0){
        cur = cur->next;
    }
    return cur->val;
    
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = obj->data->next;
    obj->data->next = newNode;
    obj->size++;
    return;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    Node *cur = obj->data;
    while(cur->next != NULL){
        cur = cur->next;
    }
    cur->next = newNode;
    obj->size++;
    return;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index < 0 || index > obj->size){
        return ;
    }
    Node *cur = obj->data;
    Node *previous;
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    while(index-- >= 0){
        previous = cur;
        cur = cur->next;
    }
    
    previous->next = newNode;
    newNode->next = cur;
    obj->size++;
    return;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index < 0 || index >= obj->size){
        return ;
    }

    Node *cur = obj->data;
    Node *previous;
    while(index-- >= 0){
        previous = cur;
        cur = cur->next;
    }
    Node *tmp = cur;
    previous->next = cur->next;
    cur = cur->next;
    obj->size--;
    free(tmp);
    return;

}

void myLinkedListFree(MyLinkedList* obj) {
    Node* tmp = obj->data;
    while(tmp != NULL){
        Node* n = tmp;
        tmp = tmp->next;
        free(n);
    }
    free(obj);
}

void printLinkeList(MyLinkedList* obj){
    Node* cur = obj->data->next;
    while(cur != NULL){
        printf("%d -> ", cur->val);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main(){
    MyLinkedList* list = myLinkedListCreate();
    myLinkedListAddAtHead(list, 1);
    myLinkedListAddAtTail(list,3);
    myLinkedListAddAtIndex(list, 2,0);    
    myLinkedListAddAtIndex(list, 3,1);    
    myLinkedListAddAtIndex(list, 4,2);    
    printf("get %d \n", myLinkedListGet(list,0)); 
    printLinkeList(list); 
    myLinkedListDeleteAtIndex(list,1);
    printf("get %d \n", myLinkedListGet(list,1)); 
    printLinkeList(list);
    return 0;
}

/*

typedef struct Node{
    int val;
    struct Node* next;
}Node;

typedef struct {
    int size;
    Node* data;
    
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = (void*)0;
    obj->data = head; //dummy head
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index < 0 || index >= obj->size){
        return -1;
    }
    Node* cur = obj->data;
    while(index-- >= 0){
        cur = cur->next;
    }
    return cur->val;
    
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = obj->data->next;
    obj->data->next = newNode;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    Node* cur = obj->data;
    
    while(cur->next != NULL){
        cur = cur->next;
    }
    cur->next = newNode;
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->size || index < 0) {
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    Node* cur = obj->data;
    Node* previous;
    while(index-- >= 0){
        previous = cur;
        cur = cur->next;
    }
    previous->next = newNode;
    newNode->next = cur;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index < 0 || index >= obj->size){
        return;
    }
    Node* cur = obj->data;
    Node* previous;
    while(index-- >= 0){
        previous = cur;
        cur = cur->next;
    }
    Node* tmp = cur;
    previous->next = cur->next;
    cur = cur->next;
    free(tmp);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* tmp = obj->data;
	while (tmp != NULL) {
		Node* n = tmp;
		tmp = tmp->next;
		free(n);
	}
	free(obj);
    
}

//add it by myself
void printLinkeList(MyLinkedList* obj){
    Node* cur = obj->data->next;
    while(cur != NULL){
        printf("%d -> ", cur->val);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main(){
    MyLinkedList* list = myLinkedListCreate();
    //myLinkedListAddAtHead(list, 1);
    //myLinkedListAddAtTail(list,3);
    myLinkedListAddAtIndex(list, 0,10);    
    myLinkedListAddAtIndex(list, 0,20);    
    myLinkedListAddAtIndex(list, 1,30);    
    printf("get %d \n", myLinkedListGet(list,0));  
    //myLinkedListDeleteAtIndex(list,1);
    //printf("get %d \n", myLinkedListGet(list,1)); 
    printLinkeList(list);
    return 0;
}
*/

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/