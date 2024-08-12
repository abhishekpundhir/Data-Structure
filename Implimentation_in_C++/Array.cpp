#include<iostream>
using namespace std;
int size = 5;
int capacity = 6;
int key = 100;
int index = 0;
int A[] = {11,22,33,44,55};
// int A[] = {};
class Array{
    public:
    void Print(int A[]){
     for (int i = 0; i < size; i++) cout<<endl<<"Element "<<A[i]<<" ";
    }

    // Array Insertion
    void insertion(int A[],int key,int size,int capacity,int index){
    if (size >= capacity) cout<<endl<<"Array is Full Elment: "<<key<<" Can't Insert At Index " <<index ;
    else{
        for (int i = index; i < size-1; i++){
            A[i+1] = A[i];
            A[index] = key;
            cout<<endl<<"Element "<<key<<" Add in Array At Index: "<<A[i]<<endl;
        }
    }
    }

    // Array Deletion
    int deletion(int A[],int size,int index){
        
            // size-=1;
    if (A[0] == 0) cout<<endl<<"Array is Empty Elment: "<<key<<" Can't Delete At Index " <<index ;
    else{
        for (int i = index ; i < size-1; i++)
        {
            A[i] = A[i+1];
            cout<<endl<<"Element "<<A[index]<<" Deleted in Array At Index: "<<i<<endl;
        }
    }
    }
};
int main(){
    Array a;
    a.Print(A);
    a.deletion(A,size,1);
        size--;
    a.Print(A);
return 0;
}