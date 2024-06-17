#include<stdio.h>
#include<stdlib.h>
struct Node{
 int data;
 struct Node *next;
};

void travers(struct Node *head){
  struct Node *p = head;
  do
  {
    printf("Element: %d\n",p->data);
    p = p->next;
  } while (p != head);
}

struct Node *InsertAtBegning(struct Node *head,int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = newNode;
    newNode->next = head;
    head = newNode;
    return head;
    
}

struct Node *InsertAtEnd(struct Node *head, int data){
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  struct Node *p = head->next;
  while (p->next != head)
  {
    p =  p->next;
  }
  p->next = newNode;
  newNode->next = head;
  return head;
  
}

struct Node *InsertAtBetween(struct Node *head,int data,int index){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    
    newNode->data = data;
    newNode->next = p->next;
    p->next = newNode;
    return head;
}


struct Node *InsertAtAfter(struct Node *head,struct Node *prevNode,int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  
    
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    return head;
}
int main(){
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 11;
    head->next = second;

    second->data = 22;
    second->next = third;

    third->data = 33;
    third->next = fourth;

    fourth->data = 44;
    fourth->next = fifth;

    fifth->data = 55;
    fifth->next = head;

    printf("Circular List Befor Deletion.....\n");
    travers(head);

    printf("Circular List After Deletion.....\n");
     head = InsertAtAfter(head,fourth,400);
       travers(head);
return 0;
}