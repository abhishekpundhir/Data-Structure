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


void preOrderT(Node* root){
    if (root!=NULL){
        printf("%d ",root->data);
        preOrderT(root->left);
        preOrderT(root->right);
    }
    
}


int main(){
Node* root = createNode(4);
Node* child1 = createNode(1);
Node* child2 = createNode(6);
Node* subChild1 = createNode(5);
Node* subChild2 = createNode(2);


root->left = child1;
root->right = child2;

child1->left = subChild1;
child1->right = subChild2;

preOrderT(root);
return 0;
}
