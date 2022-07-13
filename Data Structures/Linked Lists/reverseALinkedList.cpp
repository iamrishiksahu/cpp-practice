#include<iostream>

using namespace std;

//Question: Reverse a given linkedlist

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


node* reverseLinkedListWithRecursion(node* &head){

    node* currentptr = head;
    
    if(currentptr->next == NULL || head == NULL){

        //there is only 1 element or there is no element in the list

        return currentptr;
    }

    node* finalHead = reverseLinkedListWithRecursion(currentptr->next);


    currentptr->next->next = head;
    currentptr->next = NULL;
     

    return finalHead;
}
node* reverseLinkedList(node* &head){

    node* prevptr = NULL;
    node* currentptr = head;
    node* nextptr;

    while(currentptr != NULL){
        nextptr = currentptr->next;
        currentptr->next = prevptr;

        prevptr = currentptr;
        currentptr = nextptr;
    }

    //now the new head will be stored in the prev

    return prevptr;
}
int main(){


    node* head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);

    display(head);

    cout<<endl;

    // node* reverseHead = reverseLinkedList(head);
    node* reverseHead = reverseLinkedListWithRecursion(head);

    display(reverseHead);

    return 0; 
}