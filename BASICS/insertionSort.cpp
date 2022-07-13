#include<iostream>

using namespace std;

int main(){


    // input the size of the array
    int n;
    cout<<"Enter the size of the array: "<<endl;
    cin>> n;


    int arr[n];

    // input the array elements
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }


    // now perform the insertion sort

    for(int i=1; i<n; i++){
        
        int curr = arr[i];
        int j = i-1;

        while(arr[j] > curr){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = curr;
        
    }

    //print the sorted array

    for( int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }



    return 0;
}