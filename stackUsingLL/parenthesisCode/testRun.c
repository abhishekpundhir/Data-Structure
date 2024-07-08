#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
};

char isEmpty(struct stack *ptr){
    if (ptr->top==-1) {
        return 1;
    }
    else return 0;
}

char isFull(struct stack *ptr){
    if (ptr->top==ptr->size-1) return 1;
    else return 0;
}


char push(struct stack *sp,char value){
    if(isFull(sp)){
        printf("Stack Overflow!\n");
        return -1;
    }else{
        sp->top++;
        sp->arr[sp->top] = value;
    }
}

char pop(struct stack *sp){
    if(isEmpty(sp)){
        printf("Stack is Empty!\n");
        return -1;
    }else{
        sp->top--;
        char n = sp->arr[sp->top];
        // printf("Element %c is Poped from the Stack\n");
        return n;
    }
}

int checkParenshise(char *exp){
   struct stack * sp;
   sp->size = 100;
   sp->top = -1;
   sp->arr = (char *)malloc(sp->size * sizeof(char));
   for (int i = 0;exp[i]!= '\0'; i++){
    if (exp[i]=='(')
    {
        push(sp,'(');
    }
    else if(exp[i]==')'){
        if(isEmpty(sp)){
            // printf("stack is Empty!\n");
            return 0;
        }
            pop(sp);
        
    }
   }
   if (isEmpty(sp))
   {
    // printf("Parenthesis is Balanced!\n");
    return 1;
   }else {
    // printf("Parenthesis is Not Balanced!\n");
    return 0;
   }
}
int main(){
    char * exp = "(9)";
    // Check if stack is empty
    if(checkParenshise(exp)){
        printf("The Parenthesis is Balanced");
    }
    else{
        printf("Parenthesis Not Balanced..\n");
    }
return 0;
}
