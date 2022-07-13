#include<iostream>
#include<string>

using namespace std;

void reverseString (string s){

    if(s.length() == 0){
        return;
    }

    string removedFirstCharacter = s.substr(1); // this makes binod to inod;
    reverseString(removedFirstCharacter);
    cout<<s[0];
}

int main(){

    string s = "binod";

    reverseString(s);

    return 0;
}