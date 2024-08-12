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

    
    void push(int key){
     if (top == SIZE-1) cout<<"\nStack overflow!...";
     else{
       top++;
       A[top] = key;
       cout<<endl<<"Element "<<key<<" Added in the Stack";
     }
    }

    void pop(){
     if (top == -1) cout<<"\nStack Underflow!...";
     else{
       int r = A[top];
       top--;
       cout<<endl<<"Element "<<r<<" Popped from the Stack";
     }
    }

};
int main(){
Stack sp;
sp.push(11);
sp.push(22);
sp.push(33);
sp.push(44);
sp.push(55);


sp.StackTop();
cout<<endl;
sp.pop();
sp.pop();
sp.pop();
sp.pop();
sp.pop();

return 0;
}