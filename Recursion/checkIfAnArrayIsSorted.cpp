#include<iostream>

using namespace std;

bool isSorted(int arr[], int n){

    /*
        Sample Case: arr[5] = {1,2,3,4,5};

        Stack: 
        isSorted(arr, 1);  -> arr[1] = {5} This will return T without any comparision.
        isSorted(arr, 2);  -> arr[2] = {4,5} -> arr[0]<arr[1] & right array is T => T.
        isSorted(arr, 3);  -> arr[3] = {3,4,5} -> arr[0]<arr[1] & right array is T => T.
        isSorted(arr, 4);  -> arr[2] = {2,3,4,5} -> arr[0]<arr[1] & right array is T => T.
        isSorted(arr, 5);  -> arr[2] = {1,2,3,4,5} -> arr[0]<arr[1] & right array is T => T.
        main() -> this will print true .
    */

    if(n==1){

        //since there is only one element in array, then we cannot compare it with anyone
        //because no element is present for comparision. So we will undoubtedly return true.

        return true;
    }


    bool isRightArraySorted = isSorted(arr+1, n-1); 

    //if anywhere in between, the elements are not in correct order then
    //isRightArraySorted will become false and it will make the rest of the
    //recursive functions return false.
    //So our ultimate answer will be false.

    return (arr[0]<arr[1] && isRightArraySorted);
} 


int main(){


    int n;

    cin>>n;
    int arr[n];


    for(int i =0; i< n; i++){
        cin>>arr[i];
    }


    cout<<isSorted(arr, n);
    
    return 0;
}