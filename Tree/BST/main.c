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
int isBST( Node* root){
    static Node* prev = NULL;
    if (root!=NULL){
        if (!isBST(root->left)) return 0;
        if (prev!=NULL && root->data <= prev->data) return 0;
        prev = root;
        return isBST(root->right);
    }
    else return 1;
    
    
}
int main(){
Node* root = createNode(5);
Node* child1 = createNode(3);
Node* child2 = createNode(6);
Node* subChild1 = createNode(1);
Node* subChild2 = createNode(4);


root->left = child1;
root->right = child2;

child1->left = subChild1;
child1->right = subChild2;

inOrderT(root);
printf("%d",isBST(root));
return 0;
}
