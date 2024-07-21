#include<stdio.h>
#include<stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;

typedef struct Node{
    int data;
    struct Node *next;
}node;


void EnQueue(int data){
struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
if (newNode==NULL) printf("Out of Storage!\n");
else {
    newNode->data = data;
    newNode->next = NULL;
    if (f == NULL)
    {
       f = r = newNode;
    }else{
        r->next = newNode;
        r = newNode;
    }
}
}

void Traverse(node *ptr){
    while (ptr!=NULL)
    {
        printf("Elements %d\n",ptr->data);
        ptr = ptr->next;
    }
    
}



int DeQueue(){
    int result = -1;
    node *p = f;
    if (f==NULL) printf("Empty Queue!\n");
    else{
        f = f->next;
        result = p->data;
     free(p);
     printf("Element %d is Removed form Queue!\n",result);
     return result;
    }
    }


int main(){


EnQueue(12);
EnQueue(22);
EnQueue(34);
EnQueue(57);
EnQueue(74);
EnQueue(24);

Traverse(f);

DeQueue();
DeQueue();
DeQueue();
DeQueue();
DeQueue();
DeQueue();
return 0;
}