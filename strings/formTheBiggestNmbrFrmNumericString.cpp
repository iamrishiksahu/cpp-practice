#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


int main() {

    string s = "22345236";

    sort(s.begin(), s.end());

    reverse(s.begin(), s.end());

    cout<<s<<endl;

    //--------OR-----------

    // this function sorts in descending order
    sort(s.begin(), s.end(), greater<int>());

    cout<<endl<<s;
    
    return 0;
}