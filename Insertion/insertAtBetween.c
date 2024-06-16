#include<stdio.h>
#include<stdlib.h>
struct Node{
 int data;
 struct Node *next;
};

struct Node * insertABetween(struct Node * node,int data,int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = node;
    int i =0;
    while (i!=index-1)
    {
       p = p->next;
       i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return node;
}

void Travers(struct Node * Node){
    while (Node!=NULL)
    {
        printf("Element: %d\n",Node->data);
        Node=Node->next;
    }
    
}
int main(){
struct Node *head;
struct Node *second;
struct Node *third;

head = (struct Node*)malloc(sizeof(struct Node));
second = (struct Node*)malloc(sizeof(struct Node));
third = (struct Node*)malloc(sizeof(struct Node));

head->data = 11;
head->next = second;
second->data = 12;
second->next = third;
third->data= 13;
third->next = NULL;

// head = insertATFirst(head,55);
head = insertABetween(head,44,1);
Travers(head);
return 0;
}