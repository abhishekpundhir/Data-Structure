#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
// Traverse function.
void LinkedListTravers(struct Node *Node){
    while (Node!=NULL)
    {
        printf("Element %d\n",Node->data);
        Node=Node->next;
    }
    
}
int main(){
struct Node *head;
struct Node *second;
struct Node *third;
struct Node *fourth;

// Allocate memory for nodes in the linked list in Heap.
  // Dynamic Memory Allocation.
head = (struct Node*)malloc(sizeof(struct Node));
second = (struct Node*)malloc(sizeof(struct Node));
third = (struct Node*)malloc(sizeof(struct Node));
fourth = (struct Node*)malloc(sizeof(struct Node));

// Link first , second  and third node
head->data = 7;
head->next = second;

second->data = 12;
second->next = third;

third->data = 32;
third->next = fourth;

// Termination or last node
fourth->data = 44;
fourth->next = NULL;

LinkedListTravers(head);
}