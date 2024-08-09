#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
  int data;
  struct Node* left;
  struct Node* right;
}Node;

Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right= NULL;
    return newNode;
}

 void insert(Node* root,int key){
    Node* prev = NULL;
    while (root!=NULL)
    {
        prev = root;
        if (key==root->data){
             printf("Can't insert %d Already Exist!..\n",key);
             return;
             }
         else if(key<root->data) root = root->left;
         else root = root->right;
    }
    
    Node* newNode  = createNoode(key); 
    if (key<prev->data) prev->left = newNode;
    else prev->right = newNode;
}

void inOrderT(Node* root){
    if (root!=NULL){
        inOrderT(root->left);
        printf("%d ",root->data);
        inOrderT(root->right);
    }
    
}

int main(){
Node* root = createNode(50);
Node* child1 = createNode(30);
Node* child2 = createNode(60);
Node* subChild1 = createNode(20);
Node* subChild2 = createNode(45);
Node* subChildA = createNode(55);
Node* subChildB = createNode(70);


root->left = child1;
root->right = child2;

child1->left = subChild1;
child1->right = subChild2;

child2->left = subChildA;
child2->right = subChildB;

inOrderT(root);


return 0;
}
