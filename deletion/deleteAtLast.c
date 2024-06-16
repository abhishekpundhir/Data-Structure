#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

void Traversal(struct Node *head){
  while (head!=NULL)
  {
    printf("Element: %d\n",head->data);
    head = head->next;
  }
}

struct Node * DelAtLast(struct Node *node){
 struct Node *p = node;
 struct Node *q = node->next;
 while(q->next!=NULL)
 {
     p = p->next;
     q = p->next;
 }
 p->next =NULL;
 free(q);
  return node;
}

int main(){
struct Node *head = (struct Node*)malloc(sizeof(struct Node));
struct Node *second = (struct Node*)malloc(sizeof(struct Node));
struct Node *third = (struct Node*)malloc(sizeof(struct Node));

head->data = 112;
head->next = second;

second->data = 133;
second->next = third;

third->data = 144;
third->next = NULL;

printf("Linked Befor Deletion.....\n");
Traversal(head);

printf("Linked After Deletion.....\n");
head = DelAtLast(head);
Traversal(head);

return 0;
}