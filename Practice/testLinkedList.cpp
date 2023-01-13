#include <iostream>

using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int a)
    {
        data = a;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val){

    node* newEl = new node(val);

    newEl->next = head;
    head = newEl;
}

void insertAtTail(node* &head, int val)
{

    node *temp = head;
    node *newEl = new node(val);

    if (head == NULL)
    {
        head = newEl;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newEl;
}

void insertAtNode(node* node, int val){


    node* newEl = new node(val);

    newEl->next = node->next;
    node->next = newEl;
    
}

void printLinkedList (node* &head){

    node* temp = head;

    while(temp != NULL){
        cout<< temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;

}

void searchLinkedList(node* head, int val){

    node* temp = head;
    int counter = 0;


    while(temp != NULL){

        if(temp->data == val){
            cout<<endl<<val<<" was found at index '"<<counter<<"'";
            return;
        }

        counter++;
        temp = temp->next;

    }

    if(temp == NULL){
        cout<<"Given value was not found in the linked list :(";
    }

}

int main()
{

    node* head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);

    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtHead(head, 6);


    printLinkedList(head);

    searchLinkedList(head, 1);

    return 0;
}
