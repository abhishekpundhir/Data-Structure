#include<stdio.h>
#include<stdlib.h>
// DFS Implimentation
int visited [8] = {0,0,0,0,0,0,0,0};
int A [8][8] = {
    {0,1,1,1,0,0,0,0}, //0
    {1,0,1,0,0,0,0,0}, //1
    {1,1,0,1,1,0,0,0}, //2
    
    {1,0,1,0,1,0,0,0}, //3
    {0,0,1,1,0,1,1,0}, //4
    {0,0,0,0,0,1,0,0}, //5
    {0,0,0,0,0,1,0,1}, //6
    {0,0,0,0,0,0,1,0}, //7
};

void depthfirstsearch(int i){
    int j;
    printf(" %d ",i);
    visited[i] = 1;
    for (int j = 0; j < 8; j++){
        if (A[i][j]==1 && !visited[j]) depthfirstsearch(j);
    }
}

int main(){
depthfirstsearch(0);

return 0;
}