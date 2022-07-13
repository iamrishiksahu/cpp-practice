#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){

    string str = "asdkjfbasdertqr";
    sort(str.begin(), str.end());

    cout<<str;

    return 0;
}