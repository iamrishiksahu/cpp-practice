#include<iostream>

using namespace std;

int main( ) {

    int n; // total number of days

    cin>> n;

    int arr[n];

    for(int i=0; i<n; i++){

        cin>>arr[i];
    }

    int hV = -1, nOfDays = 0;

    for(int i=0; i<n; i++){

        if(arr[i] > hV){
            hV = arr[i];

            if((hV > arr[i+1]) || (i == n-1)){
                // this will print the no of visitors on rec breaking day
                cout<<"highest: "<<hV<<endl; 
                nOfDays ++;


            }

        }
    }

    // this will print the total number of rec breaking days
     cout<<endl<<"total number of record breaking days: "<< nOfDays;


    return 0;
}