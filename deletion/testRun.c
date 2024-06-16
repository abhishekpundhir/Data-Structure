#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void Traverse(struct Node *head)
{
    while (head != NULL)
    {
        printf("Element: %d\n", head->data);
        head = head->next;
    }
}

struct Node *DelAtBegning(struct Node *head)
{
    struct Node *p = head;
    head = head->next;
    free(p);
    return head;
}

struct Node *DelWithValue(struct Node *head, int value){
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->data != value && q->next != NULL)
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

struct Node *DelATEnd(struct Node *head){
    struct Node *p = head;
    struct Node *q= head->next;
    while (q->next != NULL)
    {
       p = p->next;
       q = p->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node *DelAtIndex(struct Node *head,int index){
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

    third->data = 33;
    third->next = fourth;

    fourth->data = 44;
    fourth->next = NULL;

    printf("Linked Befor Deletion.....\n");
    Traverse(head);

    printf("Linked After Deletion.....\n");
    // head = DelAtBegning(head);
    // head = DelWithValue(head, 22);
    // head = DelATEnd(head);
    head = DelAtIndex(head,2);

    Traverse(head);

    return 0;
}