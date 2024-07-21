#include<stdio.h>
#include<stdlib.h>
struct Node *f = NULL;
struct Node *r = NULL;

 struct Node{
    int data;
    struct Node *next;
};

void Traverse(struct Node *ptr){
    while (ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
}
struct Node *EnQueue(int data){
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode == NULL) printf("Queue is Overflow!\n");
else{
    newNode->data = data;
    newNode->next = NULL;
    if (f == NULL)
    {
        f = r = newNode;
    }else  {
        r->next  = newNode;
        r = newNode ;
        }
}
  
}

int DeQueue(){
    struct Node *p = f;
    int result =-1;
    if (f == NULL) printf("Underflow!\n");
    else{
       f = f->next;
       result  = p->data;
       free(p);
       printf("Element %d is Removed!\n",result);
       return result;
    }
    
}

int main(){
// struct Node *q;
EnQueue(12);
EnQueue(22);
EnQueue(33);
EnQueue(44);
EnQueue(55);
Traverse(f);

DeQueue();
DeQueue();
DeQueue();
DeQueue();
DeQueue();
EnQueue(122);
Traverse(f);
return 0;
}