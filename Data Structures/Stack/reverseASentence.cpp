#include<iostream>
#include<stack>

using namespace std;


void reverseTheString(string s){

    stack<string> st;

    string word = "";
    for(int i=0; i<s.size(); i++){
        char c = s[i];
        if(c == ' ' || (i == s.size()-1)){
            st.push(word);
            word = "";
            continue;
        }else{
            word+=c;
        }

    }

   

    while (!st.empty()){

        cout<<st.top()<<" ";

        st.pop();
    }
    
}


int main(){

    stack<string> st;

    string s = "Hey, how are you doing?";

    reverseTheString(s);

}

