#include<iostream>

using namespace std;

//Question: Write a program to count the number of ones in a binary representation.

int main(){


    int a = 20;

    /*
        Approach: 
            n         = 5(101); 20(10100); 17(10001); 28(11100); 27(11011)
            n-1       = 4(100); 19(10011); 16(10000); 27(11011); 26(11010)
            n & (n-1) =  (100);   (10000);   (10000);   (11000);   (11010)

        here we can observe that if we do AND of n and n-1 then we see that the result
        has exactly the same bits as n has except the rightmost 'set bit' 
        "Set Bit" is a bit having 1.

        So, this means if we AND n with n-1, this sets off the rightmost set bit
        which means 1 set bit is decreased from the total numbers of bit.
        So if we do it repeatedly, there will be a time when all set bits will become zero
        and then the value of the number will become zero. So we will count the no. of times
        we needed to perfrom this repeatition.
    */

    int count = 0; //to count the nmbr of repeatition

    while(a){
        a = a & a-1; // decreases 1 bit and then stores the new number to the same variable
        count++;

    }

    cout<<count;



    return 0;
}