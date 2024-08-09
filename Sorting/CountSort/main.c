#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int A[] = {90,99,100,105};
int n  = 4;

void Print(int *A){
printf("\nArray: ");
    for (int i = 0; i < n; i++) printf(" %d ",A[i]);
}

int M_X(int *A){
int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max<A[i])
        {
            max = A[i];
        }
    }
    return max;
}

void CountSort(int *A,int n){
    int i,j;
//    Find Max Element in Array
 int max = M_X(A);

 int *count = (int*)malloc((max+1) *sizeof(int));
 for ( i = 0; i < max+1; i++){
   count[i] = 0;
 }

 for ( i = 0; i < n; i++){
    count[A[i]] = count[A[i]]+1;
 }

 i = 0; // count Aaray Counter
 j = 0; // counter for given Array

 while (i<=max+1)
 {
    if (count[i]>0)
    {
        A[j] = i;
        count[i]--;
        j++;
    }else{
        i++;
    }
 }
 


}



int main(){
    Print(A);
    CountSort(A,n);
    Print(A);
return 0;
}