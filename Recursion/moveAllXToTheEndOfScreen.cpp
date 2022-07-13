#include<iostream>

using namespace std;

string moveAllXToTheEnd (string s, char x){

    if(s.length() == 0){
        return "";
    }

    char a = s[0];
    string str = moveAllXToTheEnd(s.substr(1), x);

    if(a == x){
        return str + x;
    }else{
        return a + str;
    }
    
}

int main (){

    string s = "ascxinswxojxijoxioj";

    cout<<moveAllXToTheEnd(s, 'x');

    return 0;
}