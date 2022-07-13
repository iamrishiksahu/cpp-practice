#include<iostream>

using namespace std;

bool checkPowerOf2(int n){

    /*

        Approach: If a number is power of 2 let's say 8 

        n   = 8 (1000); 16(10000); 64(1000000)
        n-1 = 7 (0111); 15(01111); 63(0111111)

        here we can notice some pattern. if we do n & n-1 then if we get 0 
        this clearly means that the number is a power of 2
        

    */

    // we could do only !(n &(n-1)) BUT
    // if n =0 then this would return 1 but we want 0 in that case

    return (n && !(n & (n-1)));
    
}

int countNumberOfSetBits (int a){
    

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

    return count;

}

int main(){

    int n;

    cin>>n;

    cout<<endl<<checkPowerOf2(n);

    //Alternative, we can count the number of bits in binary form.
    //We know that there is only 1 bit which has its value =1 in binary form 
    // of a number which is a power of 2.

    cout<< endl<< (countNumberOfSetBits(n) == 1);

    return 0;
}