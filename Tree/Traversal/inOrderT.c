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



void inOrderT(Node* root){
    if (root!=NULL){
        inOrderT(root->left);
        printf("%d ",root->data);
        inOrderT(root->right);
    }
    
}
int main(){
Node* root = createNode(12);
Node* child1 = createNode(22);
Node* child2 = createNode(34);
Node* subChild1 = createNode(44);
Node* subChild2 = createNode(54);


root->left = child1;
root->right = child2;

child1->left = subChild1;
child1->right = subChild2;

inOrderT(root);
return 0;
}
