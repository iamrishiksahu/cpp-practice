#include<iostream>

using namespace std;


void swap(int *a, int *b){
    int temp =*a;
    *a = *b;
    *b= temp;
}

int main(){


    int a =10;
    int arr[3] ={1,2,3};

    int *p = &a;
    int *i = arr;

    int **c = &p;
    int ***z = &c;


for(int i=0; i<3; i++){
    
    cout<<&arr[i]<<endl;

}

cout<<arr+1;


    int q = 10, b = 5;

    swap(&q,&b);

    // cout<<b;

    return 0;
}