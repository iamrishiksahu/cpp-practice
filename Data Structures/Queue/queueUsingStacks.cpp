#include<iostream>
#include<stack>

using namespace std;

class queue{

    stack<int> s1;
    stack<int> s2;

    public:

    void push(int a){
        s1.push(a);
    }

    void pop(){
        if(empty()){
            cout<<"Queue underflown!\n";
            return;
        }

        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s2.pop();
        
    }

    int peak(){
        if(empty()){
            cout<<"No element found!\n";
            return INT_MIN;
        }

        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        return s2.top();
    
    }

    bool empty(){
        if(s1.empty() && s2.empty()){
            return 1;
        }

        return 0;
    }


};
int main(){

    queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.peak()<<endl;

    q.pop();

    cout<<q.peak()<<endl;

    q.pop();
    q.pop();
    q.pop();
    q.pop();

    cout<<q.peak()<<endl; //this will return INT_MIN -2^32

    return 0;
}