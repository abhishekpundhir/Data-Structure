#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int key){
        data = key;
        next = NULL;
    }


};
    Node* push(Node* head,int key){
        Node* newNode = new Node(key);
       if (newNode == NULL) cout<<"Stck Overload";
       else{
        newNode->data = key;
        newNode->next = head;
        head = newNode;
        cout<<"Element "<<key<<" Added in the Stack..."<<endl;
       }
        return head;
    }
    
    // Node* push(Node* head,int key){
    //     try{
    //     Node* newNode = new Node(key);
    //        newNode->next = head;
    //        head = newNode;
    //     cout<<"Element "<<key<<" Added in the Stack..."<<endl;
    //     return head;
    //     }catch (bad_alloc& e){
    //      cout << "Stack Overflow: Unable to allocate memory!" << endl;
    //      return head;
    //     }
    // }

    Node* pop(Node* head){
        if (head==NULL){
            cout<<"Stack Underflow!..\n";
            return NULL;
        }else{
            Node* temp = head;
            head = head->next;
            cout<<"Element "<<temp->data<<" Removed from the stack..."<<endl;
            delete temp;
            return head;
        }
        
    }

    void stackT( Node *ptr){
    printf("Element: %d\n",ptr->data);
    while (ptr != NULL){
    printf("Element: %d\n",ptr->data);
    ptr = ptr->next; 
    }                 
}

int main(){
Node* head = NULL;
head = push(head,130);
head = push(head,22);
head = push(head,44);
head = push(head,88);
head = push(head,160);
head = push(head,220);
cout<<endl;
// pop(head);
// pop(head);
// head = pop(head);
// pop(head);
// pop(head);
stackT(head);
}

