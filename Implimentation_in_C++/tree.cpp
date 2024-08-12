#include<iostream>
using namespace std;
class Node{
    public:
    int key;
    Node* left;
    Node* right;

    Node* createNode(int key){
        Node* newNode  = new Node();
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }


    Node* insert(Node* root,int key){
        Node* prev= NULL;
        while (root!=NULL){
            prev = root;
            if (key==root->key) cout<<" Duplicacy Error!..\n";
            else if(key<root->key) root = root->left;
            else root = root->right;
        }
        Node* newNode = createNode(key);
        if (key<prev->key) prev->left = newNode;
        else prev->right = newNode;
    }
    

    Node* Search(Node* root,int key){
        if (root!=NULL){
            if (root==NULL)  return NULL;
            if(key==root->key) return root;
            else if(key<root->key) return Search(root->left,key);
            else return Search(root->right,key);
        }
    }


    void inOrderT(Node* root){
        if (root!=NULL){
            inOrderT(root->left);
            cout<<" "<<root->key;
            inOrderT(root->right);
        }
    }



    // function to get Inorder precedator
    Node* inOrderPredecessor(Node* root){
       root = root->left;
       while (root->right!=NULL) root = root->right;
       return root;
    }


    // Deletion Function
    Node* deleteNode(Node* root,int key){
      Node* ipr;
     if (root==NULL) return NULL;
     // Case 1 if Root is Leaf root;
     if (root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
     }
    //  Case 2: if root is left or right child
    if (key<root->key) root->left = deleteNode(root->left,key);
    else if(key>root->key) root->right = deleteNode(root->right,key);
    else{
        // Case 3 when root is top Node.
       ipr = inOrderPredecessor(root);
       root->key = ipr->key;
       root->left = deleteNode(root->left,ipr->key);
      return root;
    }}
};
int main(){
Node* root = root->createNode(100);

Node* childA = root->createNode(90);
Node* childB = root->createNode(250);


Node* childA1 = root->createNode(80);
Node* childA2 = root->createNode(95);

Node* childB1 = root->createNode(200);
Node* childB2 = root->createNode(310);


root->left = childA;
root->right = childB;


childA->left = childA1;
childA->right = childA2;


childB->left = childB1;
childB->right = childB2;


root->deleteNode(root,200);
root->inOrderT(root);
return 0;
}