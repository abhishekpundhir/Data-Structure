#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
};

char isEmpty(struct stack *ptr){
    if (ptr->top==-1) return 1;
    else return 0;
}

char isFull(struct stack *ptr){
    if (ptr->top==ptr->size-1) return 1;
    else return 0;
}

char stackTop(struct stack *sp){
    return sp->arr[sp->top];
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
        return n;
    }
}

int match(char a , char b){
    if (a == '{' && b == '}'){
            return 1;
         }
    if (a == '(' && b == ')'){ 
           return 1;
        }
    if (a == '[' && b == ']'){
           return 1;
         }
    return 0;
}

int checkParenshise(char *exp){
   struct stack * sp;
   sp->size = 100;
   sp->top = -1;
   sp->arr = (char *)malloc(sp->size * sizeof(char));
   char Popped_charecter;

   for (int i = 0;exp[i]!= '\0'; i++){

    if (exp[i]=='(' || exp[i]=='{' || exp[i]=='['){ push(sp,exp[i]);}


    else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){


          if(isEmpty(sp)){ return 0;}

            Popped_charecter = pop(sp);

            if (!match(Popped_charecter,exp[i]))
            {
                return 0;
            }
    }}

   if (isEmpty(sp)) return 1;
    else return 0;
   
}
int main(){
    // char * exp = "4()){6*9)";
    char * exp = "4*(9+8)";

    // Check if stack is empty
    if(checkParenshise(exp)){ 
          printf("The Parenthesis is Balanced");
        }
    else{ 
          printf("Parenthesis Not Balanced..\n");
        }
    
return 0;
}
