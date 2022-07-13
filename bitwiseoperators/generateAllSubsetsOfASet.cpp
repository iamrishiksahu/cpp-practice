#include<iostream>

using namespace std;

//Question: Print all the possible subsets of an integer set.

int main(){

    int n =4;
    int arr[] = {1,2,3,4};

    /*
        Approach: We know that there are 2^n subsets in a set of size n;
        so will create a loop to run till 2^n which will print all the subsets.
        Now since there are n elements in a subset, and in each subset there
        will be some elements which will be included and there will be some elements
        which will not be included in the subset.

        So let's say 1 represents those which will be included and 0 will represent the other.

        so let's say arr = {1,2,3}
        000 - 1
        001 - 2
        010 - 3
        011 - 4
        100 - 5
        101 - 6
        110 - 7
        111 - 8

        So those positions which will have 1 as their bit, will be included so will will
        print those corresponding elements which has 1.

    */

   //iterate over all the 2^n elements
    for(int i =0; i< (1<<n); i++){

        //iterate over the binary digits of the current number
        for(int j =0; j<n; j++){

            //checking if the current bit is 1 or not
            if(i & 1<<j){

                //the bit is 1 => print the corresponding element
                cout<<arr[j]<<' ';
            }
        }cout<<endl;
    }


    return 0;
}