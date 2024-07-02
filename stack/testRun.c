#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int size;
    int top;
    int *arr;
}stack;


int isEmpty(stack *sp){
    if (sp->top == -1) return 1;
    else return 0;
}

int isFull(stack *sp){
    if (sp->top == sp->size-1) return 1;
    else return 0;
}

void push(stack *sp){
    int data;
    printf("Enter the Element? ");
    scanf("%d",&data);

    if (isFull(sp)) printf("Stack Overload..! Value %d is Not Pushed in Stack\n",data);
     else {
        sp->top++;
        sp->arr[sp->top] = data;
        printf("Element %d is Pushed In Stack\n",data);
     }
}

void pop(stack *sp){
    if(isEmpty(sp)) printf("Stack is Empty!\n");
    else {
        int value = sp->arr[sp->top];
        sp->top--;
        printf("Element %d is Poped from Stack..\n",value);
    }
}

void peek(stack *sp){
    if (isEmpty(sp)) printf("Stack is Empty!\n");
    else{
        int index;
        printf("Enter the Possition? \n");
        scanf("%d",&index);
        int arrayIndex = sp->top-index+1;
          if (arrayIndex < 0) printf("Invalid Input\n");
          else printf("The Element At Possition %d is %d \n",index,sp->arr[arrayIndex]);
   }
}


void stackBottom(stack *sp){
    if (isEmpty(sp)) printf("Stack is Empty! \n");
    printf("Stack Bottom Element is: %d\n", sp->arr[sp->top]);
}


void stackTop(stack *sp){
    if (isFull(sp)) printf("Stack Overload! \n");
    printf("Top Element of Stack is: %d\n", sp->arr[0]);
}
int main(){
stack *sp = (stack *)malloc(sizeof(stack));
sp->size = 10;
sp->top = -1;
sp->arr = (int *)malloc(sp->size *sizeof(int ));
push(sp);
push(sp);
push(sp);
push(sp);
push(sp);

int choice;
printf("Enter 0 to Exit!\n");
printf("Enter 1 to Push Element\n");
printf("Enter 2 to POP Element\n");
printf("Enter 3 to Peek In Stack\n");
printf("Enter 4 to Get Stack Bottom In Stack\n");
printf("Enter 5 to Peek the Top Element of Stack \n");

scanf("%d",&choice);



switch (choice)
{
case 0: exit;
        break;
case 1: push(sp);
        break;
case 2: pop(sp);
        break;
case 3: peek(sp);
        break;
case 4: stackBottom(sp);
        break;
case 5: stackTop(sp);
        break;
default: printf("Enter a Valid Input! \n");
         break;
}
}
