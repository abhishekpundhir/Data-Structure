#include<stdio.h>
#include<stdlib.h>
struct Node{
 int data;
 struct Node *next;
};

struct Node * insertAEnd(struct Node * node,int data){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node *p = node;
  while (p->next!=NULL)
  {
   p = p->next;
  }
  p->next = newNode;
  newNode->next = NULL;
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
head = insertAEnd(head,444);
Travers(head);
return 0;
}