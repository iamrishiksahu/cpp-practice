#include<iostream>

using namespace std;


string removeDup (string s){

    if(s.length() == 0){
        return "";
    }

    //storing the first character of the current string in a
    char a = s[0];

    //now here str is the string which has removed duplicates of the substring(1) of s
    string str = removeDup(s.substr(1));

    //since there is not duplicate in str, we just have to compare if the current character
    //which we stored from s is equal to the first character of str or not
    if(a == str[0]){
        //if it is equal, then we will discard a and will only return the str
        return(str);
    }else{

        //if not equal then a is a unique charcter wo so we will include a in str.
        return (a + str);
    }
}
int main(){

    string s = "aaaabbbbcccdddee";

    cout<<removeDup(s);

    return 0;
}