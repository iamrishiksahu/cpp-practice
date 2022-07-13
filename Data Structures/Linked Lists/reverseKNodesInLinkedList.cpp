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

void insertAtTail(node* &head, int val){

    node* temp = head;

    node* newElement = new node(val);

    if(head == NULL){
        head = newElement;
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newElement;

}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


node* reverseK(node* &head, int k){

    node* prevptr = NULL;
    node* currentptr = head;
    node* nextptr;

    int count = 0;

    while(currentptr !=NULL && count<k){
        nextptr  = currentptr->next;
        currentptr->next = prevptr;
        prevptr = currentptr;
        currentptr = nextptr;

        count++;
    }

    if(nextptr != NULL){
        head->next = reverseK(nextptr, k);
    }

    return prevptr;
}

int main(){

    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    node* newhead = reverseK(head, 2);

    display(newhead);



    return 0;
}