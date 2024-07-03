#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *top){ 
    if (top==NULL) return 1; 
    else return 0;
}


int isFull(struct Node *top){
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    if (n == NULL) return 1;
    else return 0;
}

struct Node *push(struct Node *top,int data){
    if (isFull(top)) printf("Stack is Overflow..!\n");
    else {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = top;
        top = newNode;
        printf("Element %d is Pushed in Stack..\n",data);
        return top;
    }
}

struct Node *pop(struct Node** top){
    if (isEmpty((*top))) printf("Stack is Empty..\n");
    else{
    struct Node *n = (*top);
    (*top) = (*top)->next;
    int data = n->data;
    free(n);
    printf("Element %d is Poped from stack!\n",data);
    }
}


int peek(struct Node *top,int index){
    if (isEmpty(top))  
    {
    printf("Stack is Empty!");
    }
    else{
        struct Node *n = top;
        for (int i = 1; i < index-1 && n != NULL; i++)
        {
            n = n->next;
        }
        if (n!=NULL)
        {
            printf("Element at of Stack is %d\n",n->data);
           return n->data;
        }
    }
    
}

int stackTop(struct Node *top){
    printf("Top Element of Stack is %d\n", top->data);
}

int stackBottom(struct Node *top){
    struct Node *n  = top;
    while (n->next!=NULL){
        n = n->next;
    }
   printf ("Last of Element of Stack is %d\n",n->data);
}

int main(){
struct Node *top = NULL;
top = push(top,300);
top = push(top,100);
top = push(top,128);
top = push(top,150);
top = push(top,160);
top = push(top,190);
top = push(top,200);
peek(top,4);
stackTop(top);
stackBottom(top);
}
