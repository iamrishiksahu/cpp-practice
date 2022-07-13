#include<iostream>

using namespace std;

int main(){

    //Declaring normally (static memory allocation)
    int a= 10;
    int ar[5] = {0}; //this initializes all element of array
                        //with 0.

    //Declaring an Array using dynamic memory allocation
    int *p = new int[5]; //p is a pointer
    //where the address of the first variable of the
    //array is stroed

    *p = {5}; // *p is the actual array where the elements 
    //are being initialized.

    cout<<p[2]; //now we are taking out the adderss of the pointer

    return 0;
}