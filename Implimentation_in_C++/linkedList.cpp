#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    // Node() : data(0),next(NULL){} //Default Concstructor coz we init head in LL class
    Node(int value){
        data = value;
        next = NULL;
    }
};

  void insertionAtTail(Node* &head,int data){
    Node* newNode = new Node(data);
    if (head==NULL) {head = newNode; return;}
   
    
    Node* temp = head;
   while (temp->next!=NULL){
    temp = temp->next;
   }
   temp->next = newNode;
  }

  Node* insertAtIndex(Node* &head,int data,int index){
    Node* newNode = new Node(data);
    Node* ptr = head;

    for (int i = 0; i < index-1; i++){
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    return head;
  }


  Node* insertionAtStart(Node* &head,int data){
    Node* newNode = new Node(data);
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
  }

  Node* insertionAfter(Node* &head,Node* prev,int data){
    Node* newNode = new Node(data);
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
  }


Node* deleteFirst(Node* head){
    if (head == NULL) {
        cout << "The list is already empty." << endl;
        return NULL;
    }

    Node* ptr = head;
    head = head->next;
    delete ptr;
    return head;
}


Node* deleteLastNode(Node* head){
    Node* current = head;
    Node* nxt = head->next;
    if (head == NULL) {
        cout << "The list is already empty." << endl;
        return NULL;
    }

    while (nxt->next!=NULL){
       current = current->next;
       nxt = current->next;
    }
    current->next = NULL;
    delete nxt;
    return head;
}

Node* deleteAtGivenValue(Node* head,int key){
    Node* current = head;
    while (current->next->data != key)
    {
       current = current->next;
    }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    return head;
}

Node* deleteAtIndex(Node* head,int index){
    Node* current = head;
    for (int i = 1; i < index-1; i++){
        current = current->next;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
    return head;
}

  void Print(Node* head){
    cout<<endl<<" Element: ";
    while (head!=NULL){
       cout<<head->data<<" ";
       head = head->next;
    }
  }



int main(){

Node* head = NULL;



insertionAtTail(head,12);
insertionAtTail(head,22);
insertionAtTail(head,33);
insertionAtTail(head,44);
insertionAtTail(head,55);
insertionAtTail(head,66);
insertionAtTail(head,400);
Print(head);
head = deleteAtIndex(head,5);
Print(head);
return 0;
}