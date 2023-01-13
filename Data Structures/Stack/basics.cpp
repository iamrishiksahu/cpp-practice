#include <iostream>

using namespace std;

#define n 100

template <typename T> class stack
{

    T *arr;
    T top;

    public:
        stack()
        {
            arr = new int[n];
            top = -1;
        }

        void push(T val){
            if(top < n){
                arr[++top] = val;
            }else{
                cout<<"Stack overflown!\n";
            }
        }

        void pop(){
            if(top>-1){
                top--;
            } else{
                cout<<"Stack underflown\n";
            }
        }

        bool empty(){
            
            return top == -1;
        }

        T Top(){
            if(top < 0){
                cout<<"There is no element in the stack!\n";
                return -1;
            }

            return arr[top];
        }
};

int main()
{

    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    

    return 0;
}