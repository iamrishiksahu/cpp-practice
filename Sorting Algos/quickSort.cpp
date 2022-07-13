#include<iostream>

using namespace std;

void swap(int arr[] , int a, int b){

    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;

}

int partition(int arr[], int start, int end){

    //we are implementing the type of quick sort where pivot element is always the last element.

    int pivot = arr[end];

    int i = start - 1; //i will start pointing from an element previous than the starting element
    // the it will ultimately point to the last element in the array which is smaller that te
    //pivot element. Then we will swap the pivot element with i+1 so that pivot element comes
    // at the right place.
 
    for(int j = start; j<end; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr, i, j);
        }
    }

    //finally, correcting the position of the pivot element by swappig the i+1 with pivot element.
    swap(arr, i+1, end);

    //return the index of the current place of the pivot element.
    return i+1;

}

void quickSort(int arr[], int start, int end){

    if(start<end){ //this is the base condition

        int pi = partition(arr, start, end); //this returns the index of the pivot element after 
        //placing it to the correct position.

        //this will sort the left side of the array from pivot elmnt.
        quickSort( arr, start, pi-1);
        //this will sort the right side of the array from pivot element.
        quickSort( arr, pi + 1, end);
    }
}

void printArray(int arr[], int n){

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    int s;
    cin>>s;

    int arr[s];

    for(int i=0; i<s; i++){
        cin>>arr[i];
    }

    quickSort(arr, 0, s -1);

    printArray(arr, s);

     
    return 0;
}