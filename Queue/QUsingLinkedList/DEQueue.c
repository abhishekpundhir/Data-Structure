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


int EnQueueFront(queue *q,int data){
    if (isFull(q)) printf("Queue is Full!\n");
    else{
        q->f--;
        q->arr[q->f] = data;
        printf("Element %d is Added in the Queue...\n",data);
        return data;
    }
}

// int EnQueueRear(queue *q,int data){
//     if (isFull(q)) printf("Queue is Full!\n");
//     else{
//         q->r++;
//         q->arr[q->r] = data;
//         printf("Element %d is Added in the Queue...\n",data);
//         return data;
//     }
// }


// int DeQueueFront(queue *q){
//    int result  = -1;
//    if (isEmpty(q)) printf("Queue is Empty!\n");
//   else{
//     q->f++;
//     result = q->arr[q->f];
//     printf("Element %d is Removed from the Queue!\n",result);
//     return result;
//   }
   
// }

int DeQueueRear(queue *q){
   int result;
   if (isEmpty(q)) printf("Queue is Empty!\n");
  else{
    q->r--;
    result = q->arr[q->r];
    printf("Element %d is Removed from the Queue Rear!\n",result);
    return result;
  }
}

int main(){
queue *q = (queue*)malloc(sizeof(queue));
q->size = 100;
q->f = q->r = -1;
q->arr = (int *)malloc(q->size *sizeof(int));

EnQueueFront(q,11);
EnQueueFront(q,22);
EnQueueFront(q,33);
EnQueueFront(q,44);
EnQueueFront(q,55);
EnQueueFront(q,66);
EnQueueFront(q,77);
EnQueueFront(q,88);
EnQueueFront(q,99);
EnQueueFront(q,100);

DeQueueRear(q);
DeQueueRear(q);
DeQueueRear(q);
DeQueueRear(q);

return 0;
}