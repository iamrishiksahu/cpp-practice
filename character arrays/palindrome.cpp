#include<iostream>

using namespace std;

int main(){

//Question: To check if the input word is a palindrome.
//Hint: Palindrome us a word which is symmetrical & can be read the same from L to R or R to L


    int n;
    cin>>n;

    char arr[n+1]; // one extra elements needs to be there for null element

    cin>> arr;

    bool palindrome = 1;

    for(int i=0; i<n; i++){

        if(arr[i] != arr[n-i-1]){
            palindrome = 0;
        }
    }

    if(palindrome){
        cout<<arr<<" is a palindrome.";
    }else{
        cout<<arr<<" is not a palindrome.";

    }

    return 0;
}