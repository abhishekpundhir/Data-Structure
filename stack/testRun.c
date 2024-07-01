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

int main()
{
    // Initialization of Stack data Members.
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // Pushing Elements
    push(s, 11);
    push(s, 22);
    push(s, 33);
    push(s, 44);
    push(s, 55);
    push(s, 66);

    // Poping Elements
    pop(s);
    push(s, 100);
    return 0;
}