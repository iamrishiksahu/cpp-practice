#include<iostream>

using namespace std;

//Question: Write a program to find a unique number in an array  where all numbers
// exept one number, is repreated twice.

int findUniqueNumber(int arr[], int n){

    int xorsum =0;
    for( int i = 0; i<n; i++){
        xorsum = xorsum ^ arr[i];        
    }

    return xorsum;

}

int main(){


    int arr[] = {1,2,3,5,3,2,1};

    /*
        Approach: We wil use the XOR operator '^' This returns 1 when both bits are different
        and returns 0 when both bits are same.

        So if we XOR two same number i.e, 5 XOR 5 = 0 bcz numbers are same so this returns 0
        But if we XOR  0 with any number i.e. 5 XOR 0; this returns the number 5

        so if there are all elements present twice, so everytime it will xor with a repeating
        number, it will automatically neutralize it's addition. At the time when all the nnmbrs
        will be neutralized then the answer will automatically come when the situation will be
        0 XOR (non repeating number)

    */

   cout<<findUniqueNumber(arr, sizeof(arr)/sizeof(arr[0]));
   


    return 0;
}