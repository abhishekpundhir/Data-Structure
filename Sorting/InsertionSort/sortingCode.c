#include<stdio.h>
// int A[] = {(int)22, (int)4, (int)66, (int)1, (int)78, (int)2, (int)12, (int)6, (int)90, (int)99, (int)7, (int)10};
int A[] = {22,4,66,1,78,2,12,6,90,99,7,10};
int n = 12; 

void Print(int *A){
    printf("\nArray: ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ",A[i]);
    }
}

void InsertionSort(int *A){
    int key,J;
  for (int i = 1; i <= n-1; i++){
      key = A[i];
      J = i-1;
   while (J >= 0 && A[J] > key){
    A[J+1] = A[J];
    J--;
   }
   A[J+1] = key;
  }
}

int main(){
Print(A);
InsertionSort(A);
Print(A);
return 0;
}