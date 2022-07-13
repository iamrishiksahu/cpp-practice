#include <iostream>

using namespace std;

class node {

public:
    int data;
    node *next;

    node(int a)
    {
        data = a;
        next = NULL;
    }
};

class queue {

    node* front;
    node* back;

    public:
    queue(){
        front = NULL;
        back = NULL;
    }

    void push(int x){
        node* n = new node(x);

        if(front == NULL){
            back = n;
            front =n;
            return;
        }
        back->next = n;
        back = n;

    }

    void pop(){
        if(empty()){
            cout<<"Queue unuderflow!";

            return;
        }
        node* todelete = front;
        front = front -> next;
        delete todelete; 
    }

    int peak(){
        if(empty()){
            cout<<"No element found. Queue is empty!";
            return INT_MIN;
        }

        return front->data;
    }

    bool empty(){

        if(front == NULL){
            return 1;
        }
        return 0;
    }


};

int main()
{

    queue q;

    q.push(50);
    q.push(20);
    q.push(30);
    q.push(40);

    cout<<q.peak();

    q.pop();
    q.pop();
  
    cout<<q.peak();

    return 0;
}