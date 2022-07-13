#include<iostream>

using namespace std;

class node{

    public:
        int data;
        node* next;

        node(int val){
            data = val;
            next = NULL;
        }

};

void insertAtHead(node* &head, int val){

    node* newElementPtr = new node(val);

    if(head == NULL){
        head = newElementPtr;
        return;
    }

    newElementPtr->next = head;
    head = newElementPtr;
}

void insertAtTail(node* &head, int val){

    node* temp = head;

    node* newElementPtr = new node(val);

    if(head == NULL){
        insertAtHead(head, val);
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newElementPtr;
}

void display(node* head){

    node* temp = head;


    while(temp != NULL){


        cout<<temp->data<<" ";
        temp = temp->next;
        
    }
}

void putEvenNodesAfterAllOddNodes( node* &head){

    node* odd = head;
    node* even = head->next;
    node* secondPointer = even;

    while(even->next != NULL && odd->next !=NULL){

        odd->next = even->next;

        even->next = odd->next;
        odd = odd->next;
        even = even->next;

    }

    odd->next = secondPointer;


    if(odd->next != NULL){
            even->next = NULL;
    }
   

    
}

int main(){

    node* head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 9);

    putEvenNodesAfterAllOddNodes(head);
    display(head);

return 0;
}