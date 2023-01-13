#include<iostream>
#include<deque>

using namespace std;


int main(){

    deque<int> q;

    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_front(1);
    q.push_front(2);
    q.push_front(3);

    for(auto i:  q){
        cout<<i<<" ";
    }cout<<endl;

    q.pop_back();
    q.pop_front();

    for(auto i:  q){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<q.size();


    


    return 0;
}