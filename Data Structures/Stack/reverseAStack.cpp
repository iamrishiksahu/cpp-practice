#include<iostream>
#include<stack>

using namespace std;

//reversing a stack recursively

void insertAtBottom(stack<int> &st, int el){

    if(st.empty()){
        st.push(el);
        return;
    }
    
    int topele = st.top();
    st.pop();
    insertAtBottom(st, el);
    st.push(topele);
    
}

void printStack (stack<int> &st){

    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }


}

void reverseStack(stack<int> &st){

    if(st.empty()){
        return;
    }

    int a = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, a);

    
}

int main(){

    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverseStack(st);

    printStack(st);

    return 0;
}