#include<iostream>

using namespace std;


int factorial (int n){

    if(n == 1){
        return 1;
    }

    int prevFactorial = factorial(n-1);

    return n*prevFactorial;

    //------OR------
    // return n * factorial(n-1);
}

int main(){

    int a;
    cin>>a;

    cout<<factorial(a);

    return 0;
}