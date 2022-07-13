#include<iostream>

using namespace std;

int calcPower(int a, int n){

    if(n == 0){
        return 1;
    }

    int prevPower = calcPower(a, n-1);

    return a * prevPower;
}

int main(){


    int a,n;

    cin>>a>>n;
    cout<<calcPower(a, n);

    return 0;
}