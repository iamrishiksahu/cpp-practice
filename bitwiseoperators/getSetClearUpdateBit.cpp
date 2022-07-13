#include<iostream>

using namespace std;

int getBit(int n, int i){

    //Question: Find out whether the bit at a given position 'i' is 1 or 0.

    //Let's say that we have an integer 5 and we want to know that in this number 5
    //in the binary form, what is the value of the bit at i =2 (3rd position);

    
    //Approach: we will use bitwise operators to find the answer.
    //We will say that if there is a number 1 then it is written as 1 in binary as well
    //now we shift the bit of this 1 towards left by 'i' position using left shift operator
    // 1<< i  means the bit of this expression becaom 100 from 1 (shifted 2 positions leftwars)
    //And we know that 0101 is the binary form of our number '5'.
    //now we will use a bitwise operator  '&' wihich will do AND to 0100 and 0101.
    //if the final output is 0000, this means at the 3rd positon, there was a 0
    //otherwise, the output will be 0100 this means at the 3rd position there was 1.

    return ((((1<<i) & n)) != 0);

    //this above function will return true {1} or false {0}
}

int setBit(int n, int i, int val){

      /*
        Question: Set the bit 1 at a given position in a variable.
        eg: let's say we have 5 in a variable (0101) now we want to set 1 in the 2nd postition
        so finally the answer will be (0111). which is 7 in integer.

    */

   
    /*
        Approach: We will shift the bit of 1 to the place where we want to set the bit. 
        Then we will use the bitwise operator '|'. This will make OR of the bit so that
        if the bit is '0' at present at the given position in the variable then it becomes '1'
        after doing OR with shifted bit of 1.

    */

   return (n | (val<<i));




}

int clearBit(int n, int i){

    /*
        Quesiton: Clear the bit at a given position 'i' from the variable in binary format.
    */

   /*
        Approach: We will left shift the bit of 1 to the position where we want to clear
        now will take the one's complement (or negate) the formed bit of the shifted n
        let's say we need to do it on 3rd position so we will do 1<<2 -> 100 
        not taking one's complement ~100 = 011 now will take AND with the variable so the
        bit at the given position will be 0 due to the effect of AND and rest will be 
        completely unaffected.
    */

   return (~(1<<i) & n );

   
}

int updateBit(int n, int i, int val){

    /*
        Question: Update the bit with 1 at i = 1 in 5
    */  

   /*
        Approach: We will first clear the bit and then we will set the bit.
        Update Bit is basically clearing the bit and then setting the bit.
   */

    int a = clearBit(n,i);
    return (setBit(a, i, val));

}

int main(){

    int a =5;
    int i = 1; //position

    cout<<getBit(a, i)<<endl;
    cout<<setBit(a, i, 1)<<endl;

    i=2; 
    
    //i want to delete at 3rd position from 0101
    //answer should be 0001 = 1 in integer.


    cout<<clearBit(a, i)<<endl;

    //here the value of a has change from 5 to 1 because we have cleared the bit at i =2

    cout<<updateBit(a, i, 1)<<endl;

    return 0; 
}