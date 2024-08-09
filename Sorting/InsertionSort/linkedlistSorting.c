#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node * initNode(Node** head,int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    

    newNode->data = data;
    newNode->next = NULL;
    // return newNode;

    if (*head == NULL) {
        *head = newNode;
        return *head;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    // make the next of the tail to the new Node
    current->next = newNode;
    return newNode;
}


void Traverse(Node *node){
   printf("\nElement: ");
   Node* temp = node;
   while (temp!=NULL)
   {
    printf(" %d ",temp->data);
    temp = temp->next;
   }
   
}


void Swap(Node *a,Node *b){
int temp = a->data;  
    a->data = b->data;  
    b->data = temp; 
}

void BubbleSort(Node *head)
{
  Node *ptr;
  Node *lptr = NULL;
  int swp,i;
    if (head==NULL)
    {
        return -1;
    }
    do{
      swp  = 0;
      ptr = head;
      while (ptr->next != lptr)
      {
        if (ptr->data > ptr->next->data)
        {
            swap(ptr,lptr->next);
            swp = 1;
        }
        lptr = lptr->next;
      }
      
      lptr = ptr;
    }
    while (swp);
}
int main(){
    Node *head = NULL;
initNode(&head,99);
initNode(&head,88);
initNode(&head,80);
initNode(&head,6);
initNode(&head,100);
initNode(&head,5);
BubbleSort(&head);
Traverse(head);


return 0;
}