#include <iostream>

using namespace std;

// LINKED LISTS: Multiple blocks of memory linked with each other.

// Arrays: Single block of memory which is splitted into n parts.

/*
    This file include:
        1. Creation of linked list.
        2. Insertion at end.
        3. Insertion after any element.
        4. Insertion at head.
        5. Deletion of head.
        6. Deletion of any other element.
        7. Searching into the list.


*/

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAfterNode(node *head, int val)
{

    // node* temp = head;

    node *newElement = new node(val);

    newElement->next = head->next;

    head->next = newElement;
}

void insertAtHead(node *&head, int val)
{

    node *n = new node(val);

    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val)
{

    // we are using head by reference because if the intialized head in the
    // driving function is NULL then there will be no pointer stored in the head.
    // In that case, we will require the pointer of that NULL head.

    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
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

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return key;
        }
        temp = temp->next;
    }

    return false;
}

void deleteHead(node* &head){
    
    
    if(head == NULL){
        //linked list is empty;
        return;
    }
    
    node* temp = head;
    head = head->next;
    delete temp;
}

void deleteNode(node *&head, int val)
{

    if(head == NULL){
        //linked list is empty;
        return;
    }

    if(head->next == NULL || (head->data == val)){
        //there is only one element in the list
        //OR the element to be deleted is the first element.

        deleteHead(head);
        return;
    }

    node *temp = head;

    while (temp->next->data != val )
    {
        temp = temp->next;
    }

    node *toDelete = temp->next;

    temp->next = toDelete->next;

    delete toDelete;
}

int main()
{

    node *head = NULL;
    insertAtTail(head, 7);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 1);
    // insertAtHead(head, 5);
    // insertAfterNode(head,6);
    deleteNode(head, 7);

    // deleteHead(head);

    display(head);

    cout << endl
         << search(head, 3);

    return 0;
}