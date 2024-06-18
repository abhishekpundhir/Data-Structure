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
    while (head!=NULL)
    {
        printf("%d\t",p->data);
        p= p->next;
    }
}

// struct Node *deletionAtBegning(struct Node *head){
//    struct Node *p = head;
//    struct Node *q = p->next;
// //    q->prev = NULL;
//    p->next = NULL;
//    free(p);
//    return head;
// }


// Case: 2 When We Need to delete the last Node of an linked list.
struct Node *deletionAtEnd(struct Node *head){
  struct Node *p = head;
  struct Node *q = head->next;
  while (q->next!=NULL)
  {
    p = p->next;
    q = p->next;
  }
  p->next = NULL;
  free(q);
  return head;
}

// Case: 3 When We Need to delete the  Node of an linked list thorugh index.
struct Node *deletionAtIndex(struct Node *head,int index){
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = p->next;
    }
    p->next = q->next;
    free(q);
    return head;
    
}

// Case: 3 When We Need to delete the  Node of an linked list in Between.
struct Node *deletionAtValue(struct Node *head,int value){
    struct Node *p = head;
    struct Node *q = p->next;
    while (q->data != value && q->next !=NULL)
    {
        p = p->next;
        q = p->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
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
deletionAtValue(head,22);
traverse(head);

return 0;
}
