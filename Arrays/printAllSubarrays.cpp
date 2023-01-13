#include<bits/stdc++.h>

using namespace std;

int dist = 0;

void printArray(int arr[], int s, int e){

    for(; s<=e ; s++){
        // cout<<arr[s];
    }
    dist++;
    // cout<<dist<<endl;
    // dist = 0;
}

int main(){

    int n = 5;
    int arr[] = {1,2,3,4,5};

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            //print aarays
            printArray(arr, i,j);
        }
        
    }

    cout<<dist<<endl;
    


    return 0;

}