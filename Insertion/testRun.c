// https://youtu.be/QD6WdmJaMys?si=J-m4FUMwJxWRKpdL
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};

void Traverse(struct Node *node){
    while (node!=NULL)
    {
        printf("Elements: %d\n",node->data);
        node=node->next;
    }
}

struct Node * InsertAtFirst(struct Node * head,int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->next = head;
    newNode->data = data;
    return newNode;
}

struct Node * insertAtEnd(struct Node * node, int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node *p = node;
    while (p->next!=NULL)
    {
        p = p->next ;
    }
    p->next = newNode;
    newNode->next= NULL;
    return node;
}

struct Node * insertBetween(struct Node * node,int data,int index){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = node;
    int i = 0;
    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    newNode->data = data;
    newNode->next = p->next;
    p->next = newNode;
    return node;
}

struct Node * insertAfter(struct Node *head,struct Node * prevNode,int data){
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    return head;
}
int main(){
struct Node *head;
struct Node *second;
struct Node *third;

head = (struct Node*)malloc(sizeof(struct Node));
second = (struct Node*)malloc(sizeof(struct Node));
third = (struct Node*)malloc(sizeof(struct Node));

head->data = 12;
head->next = second;
second->data = 13;
second->next = third;
third->data = 14;
third->next = NULL;

// head = InsertAtFirst(head,100);
// head = insertAtEnd(head,100);
// head = insertBetween(head,100,2);
head = insertAfter(head,second,29);

Traverse(head);
return 0;
}