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

void selectionSort(int *A){
    int indexOfMin;
       for (int i = 0; i < n-1; i++)
       {
        indexOfMin=i;
        for (int j = i+1; j < n; j++)
        {
            if (A[j]<A[indexOfMin])
            {
                indexOfMin = j;
            }
            
        }
        Swap(&A[i],&A[indexOfMin]);
        
       }
       
}
int main(){
Print(A);
selectionSort(A);
Print(A);
return 0;
}