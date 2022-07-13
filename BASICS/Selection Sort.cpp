#include <iostream>
using namespace std;


void swap(int arr[], int i,int j){

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
} 

void printArray(int arr[], int n){

    for(int i=0; i<n; i++){
        cout<<" "<<arr[i];
    }

}

void selectionSort(int arr[], int n){


// reach out to each element from first element to last second.
// Here, only till last second is because the last element will automatically come
// under the second subarray which is being addressed by the second loop

    for(int i = 0; i< n-1; i++){

        for(int j=i+1; j<n; j++){
                
            if(arr[j] < arr[i]){
                swap(arr, i, j);
            }
        }
    }

     // Two loops are addressing two sub arrays.
    // the first loop will go from L to R and the left subarray will
    // eventually become a sorted subarray

    // the second lopp will go from the point next to the item where the
    // first subarray ends. this will go and scan for the an element 
    // smaller than the first element of the second subarray each time.    

    printArray(arr, n);
}


int main(){

    int n = 10;

    // cin>>n;

    int arr[n] = {5,3,7,2,8,0,2,3,6,-1};
    // for(int i = 0; i < n; i++){
    //     cin>> arr[i];
    // }

    selectionSort(arr, n);

    return 0;
}

