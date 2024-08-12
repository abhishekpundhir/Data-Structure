#include<iostream>
using namespace std;
#define SIZE 5
class Queue{
    public:
    int f;
    int r;
    int *A;

    Queue(){
        f = r = -1;
        A = new int(SIZE);
    }


    int enQueueRear(int data){
        if (r == SIZE-1) cout<<"\nQueue is Overload!\n";
        else{
            r++;
            A[r]= data;
            cout<<endl<<"Element "<<data<<" Added in the Stack through Rear";
            return A[r];
        }
    }

    int deQueueRear(){
        int R;
        if (r  == f) cout<<"\nQueue is Underflow!\n";
        else{
            r--;
            R = A[r];
            cout<<endl<<"Element "<<R<<" Popped from the Stack through Rear";
            return R;
        }
    }

    void enQueueFront(int data){
        if (f == SIZE-1) cout<<"\nQueue is Overload!\n";
        else{
            f--;
            A[f]= data;
            cout<<endl<<"Element "<<data<<" Added in the Stack Through Front";
        }
    }

    void deQueueFront(){
        int r;
        if (r == f) cout<<"\nQueue is Underflow!\n";
        else{
            f++;
            r = A[f];
            cout<<endl<<"Element "<<r<<" Popped from the Stack through front";
        }
    }
};


int main(){
Queue sp;

// sp.enQueueFront(666); // can't insert Because Rear of Queue is on last element but queue is empty :: Major COns of Single Ended Queue.
return 0;
}