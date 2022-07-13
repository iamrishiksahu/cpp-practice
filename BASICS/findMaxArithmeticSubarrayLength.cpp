#include<iostream>

using namespace std;

int main() {

    int n = 0; // size of the array
    cout<<"Please enter the size of the array: "<<endl;
    cin>> n;


    int arr[n];
    //taking input to the array elements

    cout<<"Enter the elements of the array"<<endl;

    for (int i =0; i<n; i++){
        cin>> arr[i];
    }

    int pCd= 0,fL =0, cCd=0, ans = 0;

    for(int i =0; i<n; i++){

        for(int j=i; j<n; j++){
            int cd = arr[j+1] - arr[j];
            if(cd == cCd){
                fL += 1;
            }else{
                pCd = cCd;
                cCd = cd;
                if(ans < fL){
                    ans = fL;
                    
                }
                fL = 2;
            }

        }
    }

    cout<<"maxLenght: "<< ans;
    return 0;
}