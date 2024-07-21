#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
  int size;

  int r;
  int f;
  int *arr;
}queue ;

int isFull(queue *q) {
    if (q->r == q->size-1) return 1;
    else return 0;
    }

int isEmpty(queue *q) {
    if (q->r == q->f) return 1;
    else return 0;
    }


int EnQueue(queue *q,int data){
    if (isFull(q)) printf("Queue is Full!\n");
    else{
        q->r++;
        q->arr[q->r] = data;
        printf("Element %d is Added in the Queue...\n",data);
        return data;
    }
}



int DeQueue(queue *q){
   int result  = -1;
   if (isEmpty(q)) printf("Queue is Empty!\n");
  else{
    q->f++;
    result = q->arr[q->f];
    printf("Element %d is Removed from the Queue!\n",result);
    return result;
  }
   
}

int main(){
queue *q = (queue*)malloc(sizeof(queue));
q->size = 100;
q->f = q->r = -1;
q->arr = (int *)malloc(q->size *sizeof(int));

EnQueue(q,11);
EnQueue(q,22);
EnQueue(q,33);
EnQueue(q,44);
EnQueue(q,55);
EnQueue(q,66);
EnQueue(q,77);
EnQueue(q,88);
EnQueue(q,99);
EnQueue(q,100);
DeQueue(q);
DeQueue(q);
DeQueue(q);
DeQueue(q);

return 0;
}