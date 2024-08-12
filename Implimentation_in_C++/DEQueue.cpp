#include<iostream>
using namespace std;
   struct Node* f  = NULL;
   struct Node* r  = NULL;
typedef struct Node{
    int key;
    struct Node* next;
}Node;


    void EnQueue(int key){
        Node* newNode = (Node*)malloc(sizeof(Node));
         if (newNode==NULL) cout<<"Queue is Full!\n";
         else{
            newNode->key = key;
            newNode->next = NULL;

            if (f == NULL) f = r = newNode;
            else{
            r->next = newNode;
            r = newNode;
            cout<<"Element "<<key<<" Added in the Queue..!\n";
            }
         }
    }

    void DeQueue(){
        int R = -1;
        Node* p = f;
         if (f == NULL) cout<<"Queue is NULL/Empty!\n";
        else{
            f = f->next;
            R = p->key;
            free(p);
            cout<<"Element "<<R<<" DeQueue From Memory..!\n";
        }
    }
int main(){

EnQueue(120);
EnQueue(33);
EnQueue(54);
EnQueue(234);

DeQueue();
DeQueue();
DeQueue();
DeQueue();
return 0;
}