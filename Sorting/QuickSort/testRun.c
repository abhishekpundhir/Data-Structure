#include<stdio.h>
int A[]={7,8,1,9,0,10,20,3};
int n = 8;
void Print(int *A){
    printf("\nArray: ");
    for (int i = 0; i < n; i++){
        printf(" %d ",A[i]);
    }
}

int Swap(int *a,int *b){
    int temp = *a ;
    *a = *b;
    *b = temp;
}


int Partition(int *A,int low,int high){
    int pivot = A[low];
    int i = low+1;
    int j = high;
    do{
    while (A[i]<=pivot) i++;
    while (A[j]>pivot) j--;
    if (i<j) Swap(&A[i],&A[j]);
    }while (i<j);
   Swap(&A[low],&A[j]);
   return j;
}


void QuickSort(int *A,int low,int high){
  int pivot;
  if (low<high)
  {
  pivot = Partition(A,low,high);
  QuickSort(A,low,pivot-1);
  QuickSort(A,pivot+1,high);
  }
  
}
int main(){
Print(A);
QuickSort(A,0,n-1);
Print(A);

return 0;
}