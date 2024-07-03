#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

void traverse(struct Node *ptr){
    while (ptr != NULL){
    printf("Element: %d\n",ptr->data);
    ptr = ptr->next; 
    }
}

int isEmpty(struct Node *top){ 
    if (top==NULL) return 1; 
    else return 0;
}

int isFull(struct Node *top){ 
    struct Node *n =  (struct Node *)malloc(sizeof(struct Node));
    if (n==NULL) return 1;
    else return 0;   
}

struct Node  *push(struct Node *top,int element){
    if (isFull(top)) printf("Stack Overflow! \n");
    else{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = top;
    top = newNode;
    }
    printf("Element %d is Pushed in Stack Using Linked List\n",element);
    return top;
}


struct Node  *pushbyUser(struct Node *top){
    int element;
    printf("Enter the Element!\n");
    scanf("%d",&element);

    if (isFull(top)) printf("Stack Overflow! \n");
    else{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = top;
    top = newNode;
    }
    printf("Element %d is Pushed in Stack Using Linked List\n",element);
    return top;
}


int pop(struct Node** top){
  if (isEmpty((*top))) printf("Stack is Empty!\n");
  else {
    struct Node *n = (*top);
    (*top )= (*top)->next;
    int value = n->data;
    free(n);
    printf("Element %d is Poped From Stack..!\n",value);
  }
  
}

int main(){
struct Node *top = NULL;
// Pushing Default Values
top = push(top,22);
// pop(top); // Pop Operation.
top = push(top,23);
// pop(top); // Pop Operation.
top = push(top,44);
// pop(top); // Pop Operation.


pop(&top);
pop(&top);
pop(&top);

// top = pushbyUser(top); // Push User Defined.

// Traverse Function
// traverse(top);


}
