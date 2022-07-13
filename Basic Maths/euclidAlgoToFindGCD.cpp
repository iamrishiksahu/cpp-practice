#include <iostream>

using namespace std;

// Question: Find the GCD of a and b. GCD = HCF

int findGCD(int a, int b)
{

    /*
        Approach: Euclid algorithm states that if you subtract the numbers a and b
        then the resulting number and b will also have the same GCD as was in a and b.
        and if you continue this subtraction till the result becomes zero, the number just
        before the zero is the hcf.

        eg: 42 and 24
        42 - 24 = 18
        24 - 18 = 6
        18 -  6 = 12
        12 -  6 = 6
        6  -  6 = 0  => 6 is the HCF!

        OR

        42%24 = 18
        24%18 = 6
        18%6 = 0
    */

    int store = 0;

    //make sure that a is the greater number
    if(a<b){
        int temp = a;
        a = b;
        b = temp;
    }


    //using the remainder to check if it is zero.
    while (b != 0)
    {
        int rem = a%b;
        a = b;
        b =rem;
        store = a;
       
    }

    return store;
}

int main()
{

    int x, y;

    cin >> x >> y;

    cout << findGCD(x, y);

    return 0;
}