#include<stdio.h>
int A[]= {99,41,55,2,1,6,9,1};
int n = 8;
void Print(int *A){
  printf("\nArray: ");
  for (int i = 0; i < n; i++){
    printf(" %d ",A[i]);
  }
}


void InsertSort(int *A){
  int j,key;
  for (int i = 1; i <= n-1; i++)
  {
    key = A[i];
    j = i-1;
    while (j>=0 && A[j]>key)
    {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    
  }
  
}
int main(){
Print(A);
InsertSort(A);
Print(A);
return 0;
}
