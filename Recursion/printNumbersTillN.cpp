#include<iostream>

using namespace std;

void printInDecreasingOrder(int n){

    if(n == 1){
        cout<<n<<" ";
        return;
    }

    cout<<n<<" ";
    printInDecreasingOrder(n-1);
    return;
}

void printInIncreasingOrder(int n){

    if(n == 1){
        cout<<n<<" ";
        return;
    }
    printInIncreasingOrder(n-1);
    cout<<n<<" ";
    return;

}

int main(){
    int n;
    cin>>n;

    printInDecreasingOrder(n);

    cout<<endl;

    printInIncreasingOrder(n);


    return 0;
}