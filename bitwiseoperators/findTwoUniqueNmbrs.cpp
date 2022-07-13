#include<iostream>

using namespace std;

//Question: Write a program to find two unique numbers in an array  where all numbers
// exept two numbers, is repreated twice.

void printA(int arr[], int n){

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void findMultipleUniqueNumbers(int arr[], int n){

    for( int i = 0; i<n; i++){

        int a = arr[i];
        int b = arr[i+1];

        if((a^b) != 0){
            // XOR of the two adjecent numbers is not zero. So they are not same
            // we will print the arr[i] and will move ahead to check arr[i+1] with arr[i+2]
            cout<<arr[i];
        }else{

            // XOR of the two adjecent numbers is zero. So they are same
            // we will skip arr[i+1] and will jump to compare arr[i+2] with arr[i+3]
            // we do i++ here to jump to the next item 

            i++;
        }   
    }

}

void sort(int arr[], int n){

    //implementing bubble sort
    for( int i=0; i<n-1; i++){
        for(int j=0; j< n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

}

int main(){

    int arr[] = {1,2,3,3,2,7,5,7,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    /*
        Approach: Refer to finUniqueNmbrAllRepeatedTwice.cpp file to understand
        the basic logic.

        Additionally, if we have to find two or more unique numbers, then we can find it
        by sorting the array first and then checking if the arr[i] XOR arr[i+1] is 0 or not
        if == 0 => arr[i] and arr[i+1] both are not unique so we skip the i+1 in the next iteration
                   by doing i++ again inside the loop.
        if != 0 => arr[i] is a unique number, then we print arr[i] and now we move
                   only one step ahead, to check for the just next number.

    */

    sort(arr,sizeof(arr)/sizeof(arr[0]) );


    findMultipleUniqueNumbers(arr, sizeof(arr)/sizeof(arr[0]));
   
    return 0;
}