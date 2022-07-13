#include<iostream>

using namespace std;

class node{

    public:
    int data;
    node* next;
    node* prev;

    node(int val){

        data = val;
        next = NULL;
        prev = NULL;
    }
    
};

void insertAtHead(node* &head, int val){

    node* newElementPtr = new node(val);

    newElementPtr->next = head;
    head = newElementPtr;

}

void insertAtTail(node* &head, int val){

    node* newElementPtr = new node(val);

    node* temp = head;

    if(head == NULL){
        //list is empty
        insertAtHead(head, val);
        return;
    }

    while(temp->next != NULL){

        temp = temp->next;
    }

    temp->next =newElementPtr;
    newElementPtr->prev = temp;
}

void display(node* head){

    node* temp = head;

    while(temp != NULL){

        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

node* insertLastKElemntsToHead(node* &head, int pos){

    node* temp = head;
    node* newTail;
    node* tail;
    node* newHead;

    int count = 0;

    while(temp->next !=NULL ){

        if(count == pos-1){
            newTail = temp;
            newHead = newTail->next;
        }

        temp = temp->next;

        count++;

    }

    tail = temp;

    head->prev = tail;

    tail->next = head;

    newTail->next = NULL;

    return newHead;

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

    display(head);

    cout<<endl;

    node* newHead = insertLastKElemntsToHead(head, 6);

    display(newHead);
    
    return 0;
}