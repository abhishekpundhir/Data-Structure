#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int * arr;
};


int isEmpty(struct stack *p){
    if (p->top == -1) printf("Stack is Empty\n");
    else return 0;
}

int isFull(struct stack *p){
     if (p->top == p->size-1) printf("Stack is Not Empty\n");
     else return 0;
}

int main(){
struct stack *s;
s->size = 90;
s->top = -1;
s->arr = (int *)malloc(s->size * sizeof(int));

// s->arr[0] = 2;
// s->top++;
// check if stack is Empty


return 0;
}