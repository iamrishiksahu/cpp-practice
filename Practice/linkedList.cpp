#include<iostream>

using namespace std;

//Implementing linked lists

class node{

    public:

    int data; // datatype can be anything according to requirement
    node* next;

    node(int a){
        data = a;
        next = NULL;
    }
};

void printLinkedList(node* &head){

    node* temp = head;

    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void insertAtHead(node* &head, int val){

    // A* temp = head;

    node* newEl = new node(val);

    newEl->next = head;

    head = newEl;

}

void insertAtTail(node* &head, int val){

    //we are using head by reference because if the intialized head in the
    //driving function is NULL then there will be no pointer stored in the head.
    //In that case, we will require the pointer of that NULL head. 

    node* temp = head;

    node* newEl = new node(val);

    if(head == NULL){
        head = newEl;
        return;
    }

    //we are doing temp->next != NULL because we have head as pointer of pointer here
    //if we had head as just a pointer then it wouldn't be necessary to do it like this.
    //instead we could simply say: run till => temp != NULL
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next= newEl;
}

void insertAtNode(node* node, int val){
    node* temp = node;

    node* newEl = new node(val);

    newEl->next = node->next;
    node->next = newEl;

}

node* search(node* head, int key){
    if(head == NULL){
        cout<<"Head cannot be null";
    }

    node* temp = head;

    while(temp != NULL){
        if(temp-> data == key){
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}


int main(){

    node* head =NULL;
    // A* head = new A(5);
    // A* secondElementPointer = new A(200);
    // A* pointerToLastElement = new A(500);

    // A* temp = head;
    // temp->next = secondElementPointer;

    // A* temp2 = secondElementPointer;
    // temp2 ->next = pointerToLastElement;

    insertAtTail(head, 6);
    // insertAtTail(head, 6);
    // insertAtTail(head, 6);
    // insertAtTail(head, 6);
    // insertAtTail(head, 6);
    // insertAtTail(head, 6);
    insertAtTail(head, 9);

    insertAtNode(head, 10);

    insertAtHead(head, 5);





    printLinkedList(head);

    node* searchPointer = search(head, 6);

    cout<<endl<<endl;
    if(searchPointer != NULL){
        cout<<searchPointer->data;
    }else{
        cout<<"Element not found";
    }


    return 0;
}
