#include<iostream>

using namespace std;

class node{

    public:

    int data;
    node* next;

    node(int a){
        data = a;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val){

    node* newElementPtr = new node(val);

    newElementPtr->next = head;
    head = newElementPtr;

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
}


int lengthOfLinkedList(node* head){

    node* temp = head;
    int length = 0;

    while(temp != NULL){
        temp = temp->next;
        length++;
    }

    return length;

}

void makeItIntersect(node* &head1, node* &head2, int index){
    //assuming head 1 is the larger list and head2 is smaller.
    //code to intersect pos(th) element of head1 at the last element of head2

    node* temp1 = head1;
    int count = 0;;

    while(count != index && temp1->next != NULL ){
        temp1 = temp1->next;
        count++;
    }

    node* temp2 = head2;
    while(temp2->next != NULL){
        temp2 = temp2->next;
    }

    temp2->next = temp1;

}

int detectIntersectionPoint(node* head1, node* head2){

    int l1 = lengthOfLinkedList(head1);
    int l2 = lengthOfLinkedList(head2);

    int d = 0;

    node* ptr1; //pointing the linked list having higher length.
    node* ptr2; //pointing the linked list having lower length.

    if(l1>l2){
        d = l1 -l2;

        ptr1 = head1;
        ptr2 = head2;
    }else{
        d = l2 -l1;

        ptr1 = head2;
        ptr2 = head1;
    }

    while(d != 0){
        ptr1 = ptr1->next;
        if(ptr1 == NULL){
            return -1;
        }
        d--;
    }

    while(ptr1 != NULL && ptr2 != NULL){

        if(ptr1 == ptr2){
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;

}


void display(node* head){

    node* temp = head;

    while(temp != NULL){

        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){

    node* head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 1);
    insertAtTail(head, 8);
    insertAtTail(head, 9);

    node* head2 = NULL;

    insertAtTail(head2, 1);
    insertAtTail(head2, 4);
    insertAtTail(head2, 9);
    insertAtTail(head2, 8);
    insertAtTail(head2, 7);

    makeItIntersect(head, head2, 5);

    display(head);

    // cout<<endl<<lengthOfLinkedList(head);

    cout<<endl<<endl<<detectIntersectionPoint(head, head2);

    return 0;
}