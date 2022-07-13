#include<iostream>
#include<string>

using namespace std;


void replaceWithPi (string s){

    if(s.length() == 0){
        return;
    }

    if(s[0] == 'p' && s[1] == 'i'){
        cout<<"3.14";
        replaceWithPi(s.substr(2));
    }else{
        cout<<s[0];
        replaceWithPi(s.substr(1));
    }

    return;
}

int main(){

    string s = "thisissomepiwithpistrings";

    replaceWithPi(s);

    return 0;
}