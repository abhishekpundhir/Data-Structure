#include<stdio.h>
#include<stdlib.h>
typedef struct Queue{
    int size;
    int f;
    int r;
    int *arr;
}queue;


int isEmpty(queue *q){
    if (q->r == q->f) return 1;
    else  return 0;
}

int isFull(queue *q){
    if (q->r == q->size-1) return 1;
    else  return 0;
}

int enQueue(queue* q,int key){
    if (isFull(q)) printf("Queue is Full!\n");
    else
    {
        q->r++;
        q->arr[q->r] = key;
    }
  return q->arr[q->r];
}

int deQueue(queue* q){
    int result = -1;
    if (isEmpty(q)) printf("Queue is Empty!\n");
    else{
        q->f++;
        result = q->arr[q->f];
    }
  return result;
}

void BFS(queue*q,int *A[],int *visited,int node,int i){
    
    
}
int main(){
queue* q = (queue*)malloc(sizeof(queue));
q->f = q->r = 0;
q->size = 10;
q->arr = (int*)malloc(q->size * sizeof(int));

int node,i=0;
int visited[7] = {0,0,0,0,0,0,0};
int A[7][7] = {
    {0,1,1,1,0,0,0}, // 0
    {1,0,1,0,0,0,0}, // 1
    {1,1,0,1,1,0,0}, // 2
    {1,0,1,0,1,0,0}, // 3
    {0,0,1,1,0,1,1}, // 4
    {0,0,0,0,0,1,0}, // 5
    {0,0,0,0,0,1,0}, // 6
};

printf(" %d ",i);
visited[i]  = 1;
enQueue(q,i);

while (!isEmpty(q))
{
    int node = deQueue(q);
    for (int j = 0; j < 7; j++)
    {
    if (A[node][j] == 1 && !visited[j])
    {
        printf(" %d ",j);
        visited[j] = 1;
        enQueue(q,j);
    }
    }
    
    
}


}