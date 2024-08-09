#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNoode(int key){
    Node* newNode = (Node* )malloc(sizeof(Node));
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrderT(Node* root){
    if (root!=NULL){
        inOrderT(root->left);
        printf(" %d ",root->data);
        inOrderT(root->right);
    }
    
}

  Node* Search(Node* root,int key){
    if (root==NULL) return NULL;
    if (key==root->data) return root;
    else if (key<root->data){ 
        printf("\nElement %d is Found At Left Side of Tree",key);
        return Search(root->left,key);
        }
    else{
        printf("\nElement %d is Found At Left Side of Tree",key);
        return Search(root->right,key);
        }
  }
int main(){
Node* root = createNoode(40);
Node* child1 = createNoode(30);
Node* child2 = createNoode(50);

Node* subchilof1A = createNoode(25);
Node* subchilof1B = createNoode(35);
Node* leftofchild2 = createNoode(45);
Node* rightofchild2 = createNoode(60);




root->left = child1;
root->right = child2;

child1->left = subchilof1A;
child1->right = subchilof1B;

child2->left = leftofchild2;
child2->right = rightofchild2;



inOrderT(root);
Node* s = Search(root,500);
// if (s!=NULL) printf("Element %d is Found",s->data);
// else printf("Element Not Found");

}