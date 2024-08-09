#include <stdio.h>
int A[] = {7, 8, 12, 16, 332, 2, 11, 90, 100, 200};
int n = 10;

void Print(int *A)
{
    printf("\nArray: ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", A[i]);
    }
}

void Merge(int *A, int low, int mid, int high)
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
            i++,k++;
        }
       else
        {
            B[k] = A[j];
            j++,k++;
        }
    }

        while (i <= mid)
        {
            B[k] = A[i];
            k++;i++;
        }
        while (j <= high)
        {
            B[k] = A[j];
            k++,j++;
        }
        
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void MergeSort(int *A, int low, int high)
{
    if (low<high)
    {
      
    
    int mid = (low + high) / 2;
    MergeSort(A, low, mid);
    MergeSort(A, mid + 1, high);
    Merge(A, low, mid, high);
    }

}

int main()
{
    Print(A);
    MergeSort(A, 0, 9);
    Print(A);
}