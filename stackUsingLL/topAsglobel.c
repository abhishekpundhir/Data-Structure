#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *top = NULL; // Use Top as Global to avoid repeatative dereffrencing and reffrencing. and avoid use of local variable with same name


int isEmpty(struct Node *head){ 
    if (head==NULL) return 1; 
    else return 0;
}

int isFull(struct Node *head){ 
    struct Node *n =  (struct Node *)malloc(sizeof(struct Node));
    if (n==NULL) return 1;
    else return 0;   
}

struct Node  *push(struct Node *head,int element){
    if (isFull(top)) printf("Stack Overflow! \n");
    else{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = head;
    top = newNode;
    }
    printf("Element %d is Pushed in Stack Using Linked List\n",element);
    return top;
}


int pop(struct Node* head){
  if (isEmpty(head)) printf("Stack is Empty!\n");
  else {
    struct Node *n = head;
    top = head->next;
    int value = n->data;
    free(n);
    printf("Element %d is Poped From Stack..!\n",value);
  }
}

int main(){
top = push(top,22);
top = push(top,23);
top = push(top,44);

pop(top);
pop(top);
pop(top);
}
