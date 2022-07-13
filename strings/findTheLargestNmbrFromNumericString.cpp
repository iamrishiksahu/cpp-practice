#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){


    string s = "989786565789";

    int maxm = INT_MIN;
    for(int i=0; i< s.length(); i++){
        int val = (int) s[i] - '0';
        if(maxm < val){
            maxm = val;
        }
        
    }



    cout<<maxm;

    return 0;
}