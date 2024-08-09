#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int value){
    Node* node  = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}


void preOrderT(Node* root){
  if (root!=NULL) {
    printf(" %d ",root->data);
    preOrderT(root->left);
    preOrderT(root->right);
  }
}


int main(){
// Linking of Nodes
// rootNode->left = n1;
// rootNode->right = n2;


Node* root = createNode(4);
Node* n1 = createNode(1);
Node* n2 = createNode(6);
Node* n3 = createNode(5);
Node* n4 = createNode(2);

  root->left = n1;
  root->right = n2;
 
  n1->left = n3;
  n1->right = n4;

  preOrderT(root);
}