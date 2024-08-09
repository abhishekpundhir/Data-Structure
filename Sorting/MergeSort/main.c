#include <stdio.h>
int A[] = {7, 8, 12, 16, 332,2, 11, 90, 100, 200};
int n = 10;

void Print(int *A)
{
  printf("\nArray: ");
  for (int i = 0; i < n; i++)
  {
    printf(" %d ", A[i]);
  }
}

int Swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Merge(int *A, int mid, int low, int high)
{
  int i, j, k;
  int B[n];
  i = low;
  j = mid + 1;
  k = low;

  while (i <= mid && j <= high)
  {
    if (A[i] < A[j])
    {
      B[k] = A[i];
      i++, k++;
    }
    else
    {
      B[k] = A[j];
      j++, k++;
    }
  }
  
  while (i <= mid)
  {
    B[k] = A[i];
    k++, i++;
  }
  while (j <= high)
  {
    B[k] = A[j];
    k++, j++;
  }
    for (int i = low; i <= high; i++)
    {
      A[i] = B[i];
    }
    
}

void MergeSort(int *A,int low,int high){
    if (low<high)
    {
      int mid = (low+high)/2;
      MergeSort(A,low,mid);
      MergeSort(A,mid+1,high);
      Merge(A,mid,low,high);
    }
  
    
}


// void MergeSort(int *A,int *B,int *C,int m,int n){
//      int i,j,k;
//      i = j = k = 0;
//      while (i<m && j<n)
//      {
//        if (A[i] < B[j])
//        {
//         C[k] = A[i];
//         i++ , k++;
//        }else{
//         C[k] = B[j];
//         j++; k++;
//        }
//      }while (i<m){
//        C[k]=A[i];
//        k++,i++;
//      }while (j<m){
//        C[k]=A[j];
//        k++,j++;
//      }

int main()
{
  Print(A);
  MergeSort(A, 0, 9);
  Print(A);
}