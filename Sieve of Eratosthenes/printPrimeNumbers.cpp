#include<iostream>

using namespace std;

void primeSieve( int n){
    int pr[100] =  {0};
    
    for(int i =2; i<=n; i++){

        if(pr[i] == 0){

            for(int j = i*i; j<=n; j+=i){
                pr[j] = 1;
            }
        }
    }

     for(int i =2; i<=n; i++){

        if(pr[i] == 0){
        cout<<i<<" ";

        }
    }

   
}

int main(){

    int n;
    cin>>n;

    primeSieve(n);


    return 0;
}