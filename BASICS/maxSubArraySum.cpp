#include<iostream>

using namespace std;

int main() {

    int n, s=0, e=0; //n is size; s & e are starting & ending index for the subarray.
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>> arr[i];
    }

    int maxSum = INT_MIN, currSum = 0;

    for(int i=0; i<n; i++){
        currSum = currSum + arr[i];
        int currMaxSum = maxSum;
        maxSum = max(maxSum, currSum);

        if(currMaxSum != maxSum){
            e = i;
        }

        if(currSum < 0){
            currSum = 0;
            s= i+1;
        }
    }

    cout<<endl<<maxSum;

    cout<<endl<<s<<" "<<e;
    return 0;
}