#include<iostream>

using namespace std;

//Question: Search the target in a matrix where the elements are sorted 
// in L - R order & T to B order.

int main(){

    int n,m, target;

    cin>>n>>m>>target;

    int arr[n][m];

    for(int i=0;i<n;i++){
        for(int j=-0; j<m;j++){
            cin>> arr[i][j];
        }
    }

    //search the target in the sorted 

    //Logic: elements at the right most position & bottom most will be greatest.
    //So we will start checking from right top of the matrix
    // if the target is greater than that element then we will move leftwards.
    // if the target is smaller than that element then we will move downwards.
    // we will repeat this above two steps to find out the exact match.



    int i = 0, j =m-1;
    while((target != arr[i][j]) && i <n && j >=0){

        if(arr[0][m-1] > target){
            // move leftwards
            j--;
        }else{
            // move downwards
            i++;
        }

    }

    if(target == arr[i][j]){
        cout<<"found target"<<" "<<i+1<<" "<<j+1;
    }else{
        cout<<"Oops! couldn't find the target!";
    }



    return 0;
}