#include<iostream>

using namespace std;

/*
    Question: Count the numbers between 1 and n which are divisble by a and b;
*/



int findNumbersDivisiblBy(int n, int a, int b){

/*
    Approach: We will use incluse exclusion principle which is basically set theory
    that if we count the numbers which are divisble by a and b separately then there
    will be numbers which will be divisible by both a and b which will be counted twice 
    in the sum of the counts of both the cases. So we need to exclude numbers which are
    divisible by both a & b. That's it.
*/

    int x = n/a; // count of numbers divisible by a
    int y = n/b; // count of numbers divisible by b
    int z = n/(a*b); // count of numbers divisible by both a & b

    return x + y - z;
 
}

int main(){

    int a,b,c;

    cin>>a>>b>>c;
    cout<<findNumbersDivisiblBy(a,b,c);


    return 0;
}