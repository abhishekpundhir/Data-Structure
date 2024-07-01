#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int * arr;
};

int isEmpty(struct stack* ptr){
    if (ptr->top == -1 )
    {
       return 1;
      
    }else 
        return 0;
    
}
int isFull(struct stack *ptr){
    if (ptr->top == ptr->size-1)
    {
        return 1;
    }else {
        return 0;
    }
}

void push(struct stack *ptr,int value){
if (isFull(ptr))
{
    printf("Stack Overflow! Cannot Push %d to the stack\n",value);
}else{
 ptr->top++;
 ptr->arr[ptr->top] = value;
}

}

int pop(struct stack *ptr){
if (isEmpty(ptr))
{
    printf("Stack UnderFlow! Cannot Pop From the stack\n");
    return -1;
}else{
 int value = ptr->arr[ptr->top];
 ptr->top--;
 return value;
}

}

int main(){
struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
sp->size = 5;
sp->top = -1;
sp->arr = (int *)malloc(sp->size *sizeof(int));
printf("Stack Implimented Successfully!....");


printf("%d\n",isFull(sp));
printf("%d\n",isEmpty(sp));

push(sp,36);
push(sp,46);
push(sp,56);
push(sp,66);
push(sp,100);

printf("After Pushing : Full -> %d\n",isFull(sp));
printf("After Pushing : Empty -> %d\n",isEmpty(sp));


printf("Popped %d from the stack\n",pop(sp));
printf("Popped %d from the stack\n",pop(sp));
printf("Popped %d from the stack\n",pop(sp));
printf("Popped %d from the stack\n",pop(sp));
printf("Popped %d from the stack\n",pop(sp));
printf("Popped %d from the stack\n",pop(sp));

return 0;
}
