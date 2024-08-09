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

void BubbleSort(int *A){
    int isSorted = 0;
   for (int i = 0; i < n-1; i++)
   {
    isSorted = 1;
    for (int j = 0; j < n-1-i; j++)
    {
        if (A[j]>A[j+1])
        {
                Swap(&A[j],&A[j+1]);
                isSorted = 0;
        }
        
    }
   }
    if (isSorted) return ;
}


void SelectionSort(int *A){
    int indexMin;
    for (int i = 0; i < n-1; i++)
    {
        indexMin = i;
        for (int j = i+1; j < n; j++)
        {
            if (A[j]<A[indexMin])
            {
                indexMin = j;
            }
        }
        Swap(&A[i],&A[indexMin]);
    }
}


void InsertionSort(int *A){
    int key,j;
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
// BubbleSort(A);
Print(A);
InsertionSort(A);
Print(A);

return 0;
}