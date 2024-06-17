#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void traverse(struct Node *head){
    struct Node *pointer = head;
    do{
        printf("Element: %d\n",pointer->data);
        pointer = pointer->next;
    }while(pointer!= head);
}

struct Node *insertAtFirst(struct Node *head,int data){
    struct Node *newNode  = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    // P point to the last node of list at thise stage.
    p->next = newNode;
    newNode->next = head;
    head = newNode;
    return head;
}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 11;
    head->next = second;

    second->data = 22;
    second->next = third;

    third->data = 22;
    third->next = fourth;

    fourth->data = 44;
    fourth->next = head;

    printf("Linked Befor Deletion.....\n");
    traverse(head);

    printf("Linked After Deletion.....\n");
     head = insertAtFirst(head,33);
       traverse(head);

    return 0;
}