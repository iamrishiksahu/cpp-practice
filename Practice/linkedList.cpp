#include<iostream>

using namespace std;

//Implementing linked lists

class A{

    public:

    int data; // datatype can be anything according to requirement
    A* next;

    A(int a){
        data = a;
        next = NULL;
    }
};

void printLinkedList(A* &head){

    A* temp = head;

    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void insertAtHead(A* &head, int val){

    // A* temp = head;

    A* newEl = new A(val);

    newEl->next = head;

    head = newEl;

}

void insertAtTail(A* &head, int val){

    //we are using head by reference because if the intialized head in the
    //driving function is NULL then there will be no pointer stored in the head.
    //In that case, we will require the pointer of that NULL head. 

    A* temp = head;

    A* newEl = new A(val);

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

void insertAtNode(A* node, int val){
    A* temp = node;

    A* newEl = new A(val);

    newEl->next = node->next;
    node->next = newEl;

}

A* search(A* head, int key){
    if(head == NULL){
        cout<<"Head cannot be null";
    }

    A* temp = head;

    while(temp != NULL){
        if(temp-> data == key){
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}


int main(){

    A* head =NULL;
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

    A* searchPointer = search(head, 6);

    cout<<endl<<endl;
    if(searchPointer != NULL){
        cout<<searchPointer->data;
    }else{
        cout<<"Element not found";
    }


    return 0;
}
