#include<iostream>
#include<stack>

using namespace std;

struct Queue{

    stack<int> s;

    void enqueue(int a){
        s.push(a);
    }

    int deQueue(){

        if(empty()){
            cout<<"Stack underflown!\n";
            return INT_MIN;
        }

        int a = s.top();
        s.pop();

        if(s.empty()){
            return a;
        }

        int toRet = deQueue();

        s.push(a);

        return toRet;

    }

    bool empty(){
        if(s.empty()){
            return 1;
        }

        return 0;
    }

   

};



int main(){

    Queue a;

    a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);
    a.enqueue(4);

    //I din't find a tutorial to implement peak using this method.
    cout<<a.deQueue()<<endl;
    cout<<a.deQueue()<<endl;
    cout<<a.deQueue()<<endl;

    // cout<<a.peak()<<endl;

    // a.deQueue();
    // a.deQueue();
    // a.deQueue();


    return 0;
}