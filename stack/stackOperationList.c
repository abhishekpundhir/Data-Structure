// Implimentation of Stack Structure:
typedef struct stack{
    int size;
    int top;
    int *arr;
} stack;


//1. Check if the stack is Empty ?
int isEmpty( stack *s){
    if (s->top == -1) return 1;
    else return 0;
}

// Check if the Stack is Full ?
int isFull( stack *s){
    if (s->top == s->size - 1) return 1;
    else return 0;
}

// Push Operation
void push( stack *s, int data)
{
    if (isFull(s)) printf("Stack is Overload value %d Insertion Faild!", data);
    else{
        s->top++;
        s->arr[s->top] = data;
        printf("Element %d Pushed in the Stack...\n", data);
    }
}

// Pop Operation
int pop( stack *s){
    if (isEmpty(s)){
        printf("Stack is Empty\n");
        return -1;
    } 
    else{
        int value = s->arr[s->top];
        s->top--;
        printf("\nElement %d Poped from Stack\n", value);
    }
}


// peek Operation
int peek( stack *s,int index){
    int arrayIndex = s->top-index+1;
    if (arrayIndex < 0){
      printf("Invalid Input %d ",index);
      return -1;
    } else return s->arr[arrayIndex];
}

// stackToop Operation:
int stackTop( stack *s){
    if (isEmpty(s)) printf("Stack is Empty..!\n");
    else  printf("Stack Top is %d\n",s->arr[s->top]);
}

// stackBottom Operation:
int stackBottom(struct stack *s){
    if (isFull(s)) printf("Stack Overflow..!\n");
    else  printf("Stack Bottom is %d\n",s->arr[0]);
}

