#include<stdio.h>
#include<stdio.h>
#include<limits.h>
int A[] = {23,12,100,5};
int n  = 4;


void Print(int *A){
printf("\nArray: ");
for (int i = 0; i < n; i++){
    printf(" %d ",A[i]);
}
}

int Swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort Algorithm
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
        if (isSorted) return;
    }
}

void InsertionSort(int *A){
int key,j;
for (int i = 1; i <= n-1; i++)
{
    key = A[i];
    j = i-1;

    while (j>=0&&A[j]>key)
    {
     A[j+1] = A[j];
     j--;
    }
    A[j+1] = key;
}
}


int Partition(int *A,int low,int high){
    int pivot = A[low];
    int i = low+1,j = high;

do{
    while (A[i]<=pivot)i++; //find eleent jo Pivot se bada h A[i] = low+1;
    while (A[j]>pivot)j--; // find element jo pivot se chota h A[j]= high;
    if (i<j) Swap(&A[i],&A[j]); // low+1 < high
    
}while(i<j) ;   
 Swap(&A[low],&A[j]); // Swap Low to High Swap(low,high);
 return j;
}

void QiuckSort(int *A,int low,int high){
    int PartitionIndex;
    if (low<high){
    PartitionIndex = Partition(A,low,high);
    QiuckSort(A,low,PartitionIndex-1);
    QiuckSort(A,PartitionIndex+1,high);
    }
}

int Merge(int *A,int low,int mid,int high){
    int i,j,k;
    i = low;
    j = mid+1;
    k = low;
    int B[k];
    while (i<= mid && j<=high)
    {
        if (A[i]<A[j])
        {
           B[k] = A[i];
           i++,k++;
        }
        else{
           B[k] = A[j];
           j++,k++;
        }
    }


    while (i<=mid){
       B[k]  = A[i];
       k++,i++;
    }

    while (j<=high){
       B[k]  = A[j];
       k++,j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
    
}

void MergeSort(int *A,int low,int high){
    if (low<high){
    int mid = (low+high)/2;
    MergeSort(A,low,mid);
    MergeSort(A,mid+1,high);
    Merge(A,low,mid,high);
    }
}



void SelectionSort(int *A){
    int indexMin;
    for (int i = 0; i < n-1; i++)
    {
        indexMin=i;
        for (int j = i+1; j < n; j++)
        {
            if (A[j]<A[indexMin])
            {
                indexMin = j;
            }
            Swap(&A[i],&A[indexMin]);
        }
        
    }
    
}
int main(){
Print(A);
SelectionSort(A);
Print(A);
return 0;
}