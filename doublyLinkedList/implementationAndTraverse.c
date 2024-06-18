#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

void traverse(struct Node *head,struct Node *index){
    struct Node *p = head;
        printf("Element: ");
    while (head!=NULL)
    {
        printf("%d\t",p->data);
        p= p->next;
    }
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

traverseReverse(head,third);

return 0;
}
