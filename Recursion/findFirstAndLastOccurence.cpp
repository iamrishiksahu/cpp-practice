#include<iostream>

using namespace std;

//Question: Find the first and last occurenece of a number n in an array.

int firstOccurence(int arr[], int n, int i, int key){
    //here arr is the array, n is the size, i will tell from  where to start, key is the nmbr;

    if( i == n){
        return -1;
    }
    if(arr[i] == key){
        return i;
    }

    return firstOccurence(arr, n, i+1, key);
}

int lastOccurence (int arr[], int n, int i, int key){

     if(i == n){
        return -1;
    }

    int a = lastOccurence(arr, n, i+1, key);

    if(a != -1){
       return a; 
    }

    if(arr[i] == key){
        return i;
    }
    return -1;
}
int main(){
    int arr[6] = {1,4,2,2,2,4};

    cout<<firstOccurence(arr, 6, 0, 2)<<endl;
    cout<<lastOccurence(arr, 6, 0, 2);

    return 0;
}