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

void deleteAtHead(node* &head){

    node* temp = head;

    while(temp->next != head){
        temp = temp->next;
    }

    node* todelete = head;

    temp->next = head->next;
    head = head->next;

    delete todelete;

    //we have not deleted the head pointer. it is still intact with the 2nd element of the list. But the reference of the first element pointer is stored in the todelete pointer so if we delete the todelete pointer, the item containing the first element will be deleted but the second element will be intact and head will be pointing to the same.
}

void deleteNode(node* &head, int pos){

    node* temp =head;

    int count = 0;

    if(pos == 0){
        deleteAtHead(head);

        return;
    }

    while(count != pos-1){
        temp = temp->next;
        count++;
    }

    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;



}

void insertAtHead(node* &head, int val){

    node* newElementPtr = new node(val);

    if(head == NULL){
        newElementPtr->next = newElementPtr;
        head = newElementPtr;
        return;
    }

    node* temp = head;

    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = newElementPtr;
    newElementPtr->next = head;
    head = newElementPtr;

    
}

void display(node* head){

    node* temp = head;

    //this printing can only be done via a do while loop.

    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    
    while(temp != head);
}

void insertAtTail(node* &head, int val){

    node* temp = head;
    node* newElementPtr = new node(val);

    if(head == NULL){
        insertAtHead(head, val);
        return;
    }

    while(temp->next != head){

        temp = temp->next;
    }

    temp->next = newElementPtr;
    newElementPtr->next = head;

}

int main(){

    node* head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);

    deleteNode(head,3);

    display(head);


    return 0;
}