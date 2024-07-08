#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Stack{
    int size;
    int top;
    char *arr;
}stack;

int stackTop(struct Stack *sp){
    return sp->arr[sp->top];
}
int isEmpty(struct Stack *sp){
    if (sp->top==-1){
       return 1;
    }else {
        return 0;
        }
    
}

int isFull(struct Stack *sp){
   if (sp->top==sp->size-1) return 1;
   return 0;
}

char push( struct Stack *sp,int value){
    if(isFull(sp)){
        printf("Stack Overflow!\n");
        return -1;
    }else{
        sp->top++;
        sp->arr[sp->top] = value;
    }
}

char pop(struct Stack *sp){
    if (isEmpty(sp))
    {
        printf("Stack is Underflow!\n");
        return -1;
    }else{
        char n = sp->arr[sp->top];
        sp->top--;
        return n;
    }
}

int precedence(char ch){
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}
 

 int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/') 
        return 1;
    else
        return 0;
}

char* infixToPostfix(char* infix){
    struct Stack * sp = (struct Stack *) malloc(sizeof(struct Stack));
    sp->size = 10; 
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition 
    while (infix[i]!='\0')
    {
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])> precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))    
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}


int main(){
 char *infix = "a-b+t/6";
printf("Postfix is %s\n",infixToPostfix(infix));
return 0;
}
