#include <iostream>

using namespace std;

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

node *mergeRecursively(node *&head1, node *head2)
{

    if(head1 == NULL){
        return head2;
    }

    if(head2 == NULL){
        return head1;
    }

    node *result;

    if(head1->data > head2->data){
        result = head2;
        result->next = mergeRecursively(head1, head2->next);
    }else{
         result = head1;
        result->next = mergeRecursively(head1->next, head2);
    }

    return result;
}

node *mergeSortedLinkedLists(node *&head1, node *&head2)
{

    node *t1 = head1;
    node *t2 = head2;

    node *dummy = new node(-100);
    // we have to preserve the dummy node because next pointer of the dummy node will tell us that from where the new list is starting. so we will not use dummy for traversal , we will create anothe node ptr for traversal which will be initialized from dummu!
    node *ptr = dummy;

    while (t1->next != NULL && t2->next != NULL)
    {
        if (t1->data > t2->data)
        {
            ptr->next = t2;
            t2 = t2->next;
        }
        else
        {

            ptr->next = t1;
            t1 = t1->next;
        }

        ptr = ptr->next;
    }

    while (t1 != NULL)
    {

        ptr->next = t1;
        t1 = t1->next;
        ptr = ptr->next;
    }

    while (t2 != NULL)
    {

        ptr->next = t2;
        t2 = t2->next;

        ptr = ptr->next;
    }

    return dummy->next;
}

int main()
{

    node *head1 = NULL;
    node *head2 = NULL;

    insertAtTail(head1, 1);
    insertAtTail(head1, 4);
    insertAtTail(head1, 7);
    insertAtTail(head1, 9);
    insertAtTail(head1, 10);

    insertAtTail(head2, 2);
    insertAtTail(head2, 3);
    insertAtTail(head2, 8);
    insertAtTail(head2, 11);

    display(head1);
    cout << endl;
    display(head2);
    cout << endl;

    node *mergedNode = mergeRecursively(head1, head2);
    display(mergedNode);

    return 0;
}