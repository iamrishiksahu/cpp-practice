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

void insertAtTail(node *&head, int val)
{

    node *temp = head;

    node *newElement = new node(val);

    if (head == NULL)
    {
        head = newElement;
        return;
    }

    while (temp->next != NULL)
    {
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

bool detectCycle(node *head)
{

    node *slow = head;
    node *fast = head;

    while (slow->next != NULL && fast->next->next != NULL)
    {

        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            return 1;
        }
    }

    return 0;
}

void createCycleInLinkedlist(node *&head, int pos)
{

    int count = 1;

    node *temp = head;
    node *startNode;

    while (temp->next != NULL)
    {

        if (count == pos)
        {
            startNode = temp;
        }

        temp = temp->next;
        count++;
    }

    temp->next = startNode;
}

void removeCycle(node *&head)
{

    // to remove a cycle, we first need to detect it.
    node *slow = head;
    node *fast = head;

    bool isCyclePresent = 0;

    while (slow->next != NULL && fast->next->next != NULL)
    {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            // now this is the node where they are
            // conciding, so we will get out of this loop
            isCyclePresent = 1;
            break;
        }
    }

    // now initializing fast with head
    if (isCyclePresent)
    {
        fast = head;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;

            ///moving only one step with both of them
        
        }

        //now when the loop breaks, that means we are the place where the next of both slow and fast pointers are pointing to the same node. this means we need to disconnect the slow->next node to NULL

        slow->next = NULL;
        //now the cycle has been broken.
    }
}

int main()
{

    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    createCycleInLinkedlist(head, 8);


    cout << endl
         << detectCycle(head);

         removeCycle(head);

         
    cout << endl
         << detectCycle(head)<<endl;

    display(head);


    return 0;
}