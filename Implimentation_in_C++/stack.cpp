#include<iostream>
using namespace std;
#define SIZE 5
class Stack{
    public:
    int top;
    int *A;
    Stack(){
        top=-1;
        A =  new int[SIZE];
    }
    int StackTop(){
       cout<<"Top of the Stack is "<<A[top];
       return A[top];
    }

    
    void enQueue(int key){
     if (top == SIZE-1) cout<<"\nStack overflow!...";
     else{
       top++;
       A[top] = key;
       cout<<endl<<"Element "<<key<<" Added in the Stack";
     }
    }

    int peek(Stack* sp,int index){
    int indexPos = sp->top-index+1;
    if (indexPos<0) cout<<"Invalid index!!"<<endl;
    else{
        int r = A[indexPos];
        cout<<"Peeked Value is "<<r<<endl;
       return r;
    }
    
    }

    void deQueue(){
     if (top == -1) cout<<"\nStack Underflow!...";
     else{
       int r = A[top];
       top--;
       cout<<endl<<"Element "<<r<<" Popped from the Stack";
     }
    }

};


int main(){
Stack *sp;
sp->enQueue(11);
sp->enQueue(22);
sp->enQueue(33);
sp->enQueue(44);
sp->enQueue(55);


sp->peek(sp,2);
cout<<endl;
// sp.pop();
// sp.pop();
// sp.pop();
// sp.pop();
// sp.pop();

return 0;
}