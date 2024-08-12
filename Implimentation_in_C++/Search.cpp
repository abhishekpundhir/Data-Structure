#include<iostream>
using namespace std;
int size = 5;
int capacity = 6;
int key = 22;
int index = 0;
int A[] = {11,22,33,44,55};
// int A[] = {};
class Search{
    public:
    void Print(int A[],int size){
     for (int i = 0; i < size; i++) cout<<endl<<"Element "<<A[i]<<" ";
    }

    // Linear Search
    int linearSearch(int A[],int key){
    for (int i = 0; i < size; i++){
        if (A[i] == key) cout<<"\nElement "<<key<<" Found At Index "<<i;
        
    }
    return -1;
    }

    // Binary Search
    int binSearch(int A[],int key,int size){
    int low,mid,high;
    low = 0;
    high = size-1;
    while (low<=high)
    {
        mid = (low+high)/2;
        if (A[mid] == key) cout<<" \nElement "<<key<<" found at Index: "<<mid; return mid;
         if (mid<key) low = mid+1;
        else high = mid-1;
    }
    return -1;
    }
 };
