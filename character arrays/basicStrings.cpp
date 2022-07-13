#include<iostream>

using namespace std;

int main(){


    //Oberservation: if we cout arr directly then here it returns the complete character array
                //   upto the null value (automatically stored at the end of the sentence)
                // BUT, if we cout arr1 directly then it returns some bullshit. not the array

    char arr[1000] = "Rishik";

    int arr1[2] = {1,2};

    cout<<arr;
    cout<<endl<<arr1;

    return 0;
}