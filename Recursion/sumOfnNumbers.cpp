#include<iostream>

using namespace std;

int sum(int n){

    if(n == 0){
        return 0;
    }
    int prevSum = sum(n-1);

    return prevSum + n;
}

int main(){

    int n;

    cin>>n;

    cout<<sum(n);

    return 0;
}