#include<iostream>

using namespace std;

 int main(){

     int n; // size of the array
     cout<<"Enter the number of elements: ";
     cin>>n;

     int arr[n];

     for(int i = 0; i<n; i++){
         cin>>arr[i];
     }

     //create a largest array and initialize all items with -1

     const int N = 1e5 + 2;

     int idx[N];

     for( int i = 0; i<N;i++){
         idx[i] = -1;
     }

     //creating a variable to contain the answer (the minimum index of the repeating numbers)

     int minindex = INT_MAX;

     for(int i=0;i<n;i++){

         if(idx[arr[i]] == -1){
            idx[arr[i]] = i;
         }else{
             minindex = min(minindex, idx[arr[i]]);
         }
     }

    if(minindex == INT_MAX){
     cout<<-1;

    }
    else{
    cout<<minindex;

    }



     return 0;
 }
