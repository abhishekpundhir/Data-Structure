#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int size ;
    int f;
    int r;
    int * arr;
}queue;

int isFull(queue *q){
    if ((q->r+1)%q->size == q->f) return 1;
    else return 0;
    }

int isEmpty(queue *q){
    if (q->r == q->f) return 1;
    else return 0;
    }

void EnQueue(queue *q,int data){
    if (isFull(q)) printf("Queue is Full!\n");
    else {
        q->r = (q->r+1) % q->size;
        q->arr[q->r] =data;
        printf("Element %d is Added in the Queue..\n",data);
    }
}

int DeQueue(queue *q){
    int result = -1;
    if (isEmpty(q)) printf("Queue is Empty!\n");
    else{
      q->f = (q->f+1)%q->size;
        result = q->arr[q->f];
    //    printf("Element %d is Removed from the Queue!\n",result);
    }
    
}



int main(){
queue *q = (queue*)malloc(sizeof(queue));
q->size = 4;
q->f = q->r = 0;
q->arr = (int *)malloc(q->size *sizeof(int));
EnQueue(q,11);
EnQueue(q,22);
EnQueue(q,33);
EnQueue(q,44);
DeQueue(q);
DeQueue(q);
DeQueue(q);
DeQueue(q);
// EnQueue(q,55);

return 0;
}