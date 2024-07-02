#include <stdio.h>
#include <stdlib.h>

// Implimentation of Stack Structure:
typedef struct stack
{
    int size;
    int top;
    int *arr;
} stack;

// Check if the stack is Empty ?
int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Check if the Stack is Full ?
int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Push Operation
void push(struct stack *s, int data)
{
    if (isFull(s))
    {
        printf("Stack is Overload value %d Insertion Faild!", data);
    }
    else
    {
        s->top++;
        s->arr[s->top] = data;
        printf("Element %d Pushed in the Stack...\n", data);
    }
}

// Pop Operation
int pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty\n");
        return -1;
    } 
    else
    {
        int value = s->arr[s->top];
        s->top--;
        printf("\nElement %d Poped from Stack\n", value);
    }
}


// peek Operation
int peek(struct stack *s,int index){
    int arrayIndex = s->top-index+1;
    if (arrayIndex < 0){
      printf("Invalid Input %d ",index);
      return -1;
    }else{
        return s->arr[arrayIndex];

    }
}


// stackToop Operation:
int stackTop(struct stack *s){
    if (isEmpty(s)){
        printf("Stack is Empty..!\n");
    }else  printf("Stack Top is %d\n",s->arr[s->top]);
}

// stackBottom Operation:
int stackBottom(struct stack *s){
    if (isFull(s)){
        printf("Stack Overflow..!\n");
    }else  printf("Stack Bottom is %d\n",s->arr[0]);
}


int main()
{
    // Initialization of Stack data Members.
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // Pushing Elements
    push(s, 11);
    push(s, 22);
    push(s, 33);
    push(s, 44);
    push(s, 55);
    push(s, 100);


    // Peek Invoked:
    //  for (int i = 1; i <= s->top+1; i++)
    // {
    //       printf("Value at Given Possition %d is %d \n",i,peek(s,i));
    // }


    // stackTop Invoked:
       stackTop(s);

    // stackTop Invoked:
       stackBottom(s);
    return 0;
}