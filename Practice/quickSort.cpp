#include <iostream>

using namespace std;

//both of the swapping functions work properly

// void swap(int arr[], int a, int b)
// {

//     int temp = arr[a];
//     arr[a] = arr[b];
//     arr[b] = temp;
// }

void swap (int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int start, int end){

    int pivot = end;
    int i = start -1; //pointer to denote the last smaller element than the pivot element.

    for(int j=start; j<end; j++){
        if(arr[j] < arr[pivot]){
            i++;
            swap(arr, i,j);
        }
    }
    swap(arr, i+1, pivot);
    return i+1;
}


void quickSort(int arr[], int start, int end){

    if(start<end){

        int pi = partition(arr, start, end);

        quickSort(arr, start, pi-1);
        quickSort(arr, pi+1, end);
    }
}


int main()
{

    int n = 4;
    int arr[4] = {3, 2, 5, 1};


    //we always pass the array, starting sorting index & ending sorting index
    quickSort(arr, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}