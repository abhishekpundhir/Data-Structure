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

Node* inOrderPredcessor(Node* root){
  root = root->left;
  while (root->right!=NULL){
    root = root->right;
  }
  return root;
 }


Node* delete(Node* root,int key){
    Node* iPre;
    if (root==NULL) return NULL;
    if (root->left==NULL && root->right==NULL){ 
        free(root);
        return NULL;
        }

    if (key<root->data) root->left=delete(root->left,key);

    else if(key>root->data){ root->right = delete(root->right,key);}
    
    else{
       iPre =  inOrderPredcessor(root);
       root->data = iPre->data;
       root->left = delete(root->left,iPre->data);
    }
    return root;
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
delete(root,30);
printf("\n");
inOrderT(root);

return 0;
}
