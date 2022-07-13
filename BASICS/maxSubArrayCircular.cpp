#include<iostream>

using namespace std;

// Question: Find the maximum sum of the subarray including the circular subarray

// Approach: Solve this in 2 parts, the first part will solve for the maximum sum in the
// non circular subarray. Then the second part will solve for the maximum sum in the circular
// part. The logic of the second part will be: first we will negate all the elements in the
// array and then will take out the maximum sum. This maximum sum will be the sum of the 
// elements which will not be used in the actual maximum sum in the circular subarray bcz
// the maximum circular subarray sum will be formed by the elemets which are not in the max
// subarray of the negated subarray.


int kaden(int arr[], int n){


    int maxSum = INT_MIN, currSum = 0;


    for( int i=0; i<n; i++){
        currSum = currSum + arr[i];
        maxSum = max( maxSum, currSum);



        if(currSum < 0){
            currSum = 0;
        }
        
    }

    return maxSum;
}

int main(){

    int n;

    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int nonWrapSum = kaden(arr, n);
    int totalSum = 0;

    for( int i =0; i<n; i++){
        totalSum = totalSum + arr[i];
        arr[i] = - arr[i];
    }

    int negatedSum = kaden (arr, n);
    int wrapMaxSum = totalSum + negatedSum;

    cout<<endl<<max(wrapMaxSum, nonWrapSum);


    return 0;
}