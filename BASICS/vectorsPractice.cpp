#include<iostream>
#include<vector>
using namespace std;


int main(){

    //initializes 10 elments with 4 directly.
    vector<int> v  (10, 4);


    //adds the elements at the end of the vector
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    //we can create an iterator which will iterate through
    //the entire vector as a pointer.

    vector<int>::iterator i;

    for(i = v.begin() ; i< v.end(); i++){

        cout<<*i<<" ";

    }


    


    // for(int element: v){

    //     cout<<element<< " ";
    // }
}