#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

void travers(struct Node *head){
    struct Node *p = head;
        printf("Element: ");
    do
    {
        printf("%d\t",p->data);
        p = p->next;
    } while (p != head);
    
}



// struct Node *deletionAtBegning(struct Node *head){
//     struct Node *p = head;
//     head = head->next;
//     free(p);
//     return head;
// }


struct Node *deleteAtEnd(struct Node *node){
    struct Node *p = node;
    struct Node *q = p->next;
    while (q->next!=node)
    {
        p = p->next;
        q= p->next;
    }
    p->next = node;
    free(q);
    return node;
}

struct Node *deletionAtIndex(struct Node *head,int index){
    struct Node *p = head;
    struct Node *q = p->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q= p->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node *deletionAtGivenValue(struct Node *head,int value){
    struct Node *p = head;
    struct Node *q = p->next;
   while (q->data != value && q->next != head){
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


head->data = 11;
head->next = second;

second->data = 22;
second->next = third;

third->data = 33;
third->next = fourth;

fourth->data = 44;
fourth->next = head;

deletionAtIndex(head,2);
travers(head);
return 0;
}