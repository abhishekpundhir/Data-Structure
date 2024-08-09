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

        // printf("Element %d is Present in Tree",key);
Node* iSearch(Node* root,int key){
    while (root!=NULL){
    if (key==root->data) return root;
    else if (key<root->data)  root = root->left;
    else root= root->right;
    }
    return NULL;
    
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


Node* n = iSearch(root,60);
if (n!=NULL){
printf("\nElement %d is Found ",n->data);
}else printf("\nElement Not Found!");

return 0;
}
