#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

void traverse(struct Node *head){
    struct Node *p = head;
        printf("Element: ");
    while (p!=NULL)
    {
        printf("%d\t",p->data);
        p= p->next;
    }
   
}

// 1. Insert Node at Begning
struct Node *insertionAtBegning(struct Node *head,int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    head->prev = NULL;
    return head;
}


struct Node *insertionAtLast(struct Node *head,int data){
    struct Node *newNode =  (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    while (p->next!= NULL)
    {
        p = p->next;
    }
    newNode->data = data;
    p->next = newNode;
    newNode->next = NULL;
     return head;
}

struct Node *insertionBetween(struct Node *head,int data,int index){
    struct Node *newNode =  (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i!=index)
    {
        p = p->next;
        i++;
    }
    newNode->data = data;
    newNode->next = p->next;
    p->next = newNode;
    return head;    
}


struct Node *insertionAtAfter(struct Node *head,struct Node *prevNode , int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    return head;
}

int main(){
struct Node *head = (struct Node*)malloc(sizeof(struct Node));
struct Node *second = (struct Node*)malloc(sizeof(struct Node));
struct Node *third = (struct Node*)malloc(sizeof(struct Node));
struct Node *fourth = (struct Node*)malloc(sizeof(struct Node));

// [NULL|Data|next] -> [NULL|Data|next] -> [NULL| Data|next] -> [NULL|Data|next]:
// Node 1:
head->prev = NULL;
head->data = 11;
head->next = second;

// Node 2:
second->prev = head;
second->data = 22;
second->next = third;

// Node 3:
third->prev = second;
third->data = 33;
third->next = fourth;

// Final 4:
fourth->prev = third;
fourth->data = 44;
fourth->next = NULL;

head = insertionAtAfter(head,second,1111);
traverse(head);

return 0;
}
