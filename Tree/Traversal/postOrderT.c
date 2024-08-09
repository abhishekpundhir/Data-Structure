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


void postOrder(Node* root){
    if (root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
    
}
int main(){
Node* root = createNode(4);
Node* child1 = createNode(1);
Node* child2 = createNode(6);
Node* subChild1 = createNode(5);
Node* subChild2 = createNode(2);

// Node* root = createNode(12);
// Node* child1 = createNode(22);
// Node* child2 = createNode(34);
// Node* subChild1 = createNode(44);
// Node* subChild2 = createNode(54);


root->left = child1;
root->right = child2;

child1->left = subChild1;
child1->right = subChild2;

postOrder(root);
return 0;
}
