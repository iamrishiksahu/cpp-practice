#include<iostream>
#include<string>

using namespace std;

int main(){

    string str= "Rishik is the boss in the BMW!";
    //take input of a sentence
    // getline(cin, str);

    //tale input of a word

    // cin>>str;
    // cout<<str;


    string s1 = "rishik";
    string s2 =" ";
    string s3 = "sahu";

    cout<<s1+s2+s3<<endl;

    s1.append(s2);
    s1.append(s3);

    //or

    // s1 = s1 + s2; // this also appends

    // cout<<s1;

    // we can print the characters of strings by considering a str to be an array

    string a = "abc";
    cout<<a[2]; // this will print s

    a.clear();  //this will clear the string completely.

    string b = "abc";

    if(a.compare(b)){
        cout<<"Strings are equal "<<a.compare(b)<<endl;
    }



    return 0;
}