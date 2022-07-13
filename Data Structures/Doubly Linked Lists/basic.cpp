#include<iostream>

using namespace std;

class node{


    public:

    int data;
    node* next;
    node* prev;

    node(int a){
        data = a;
        prev=NULL;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val){

    node* newElement = new node(val);

    newElement->next = head;
    head = newElement;

}

void insertAtTail(node* &head,int a){

    node* newElement = new node(a);
    node* temp = head;

    if(head == NULL){
        insertAtHead(head, a);
        return;
    }

    while(temp->next != NULL){

        temp = temp->next;
    }

    temp->next = newElement;
    newElement->prev = temp;
}

node* deleteAtHeadAndChangeHeadPointer(node* &head){

    node* todelete = head;

    node* newHead = todelete->next;

    todelete->next->prev = NULL;

    delete todelete;

    return newHead;
}

void deleteAtHeadWithoutChangingHeadPointer(node* &head){

    node* todelete = head;

    head = head->next;

    //now the head has changed its pointer from the first element
    //to the second element

    head->prev = NULL;
    //in this line, we are assigning the value of the previous pointer of the second element to null. because head is now pointing to 2nd element.

    delete todelete;


}

void deleteValue(node* &head, int val){

    node* temp = head;

    if(head == NULL){
        //there is no element in the list.
        return;
    }

    if(head->next == NULL || (head->data == val)){
        //there is only one element in the list.
        //OR the head element matches the data to be deleted
        deleteAtHeadWithoutChangingHeadPointer(head);
    //or

        // deleteAtHeadAndChangeHeadPointer(head);
        return;
    }

    while(temp->next != NULL){

        if(temp->next->data == val){
            break;
        }

        temp = temp->next;

    }

    node* todelete = temp->next;

    if(todelete->next != NULL){

        todelete->next->prev = temp;
        temp->next = todelete->next;


    }else{
        temp->next = NULL;
    }


    delete todelete;

}

void display(node* head){

    node* temp = head;

    while(temp != NULL){

        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void displayInReverseOrder(node* head){

    if(head == NULL){
        return;
    }

    displayInReverseOrder(head->next);
    cout<<head->data<<" ";
}

int main(){

    node* head = NULL;

    

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);  

    insertAtHead(head, 5);
    insertAtHead(head, 7);

    display(head);

    // deleteValue(head, 7);

    cout<<endl;

    // display(head);

    node* newHead = deleteAtHeadAndChangeHeadPointer(head);

    deleteValue(newHead, 4);

    display(newHead);


    // displayInReverseOrder(head);


    return 0;
}