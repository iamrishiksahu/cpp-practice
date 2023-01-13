#include <bits/stdc++.h>

using namespace std;

int printFibonacci(int n)
{

    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    int ans = printFibonacci(n - 1) + printFibonacci(n - 2);
    cout<<ans<<" ";

    return ans;
}

int main()
{

    // print fibonacci series upto n terms using recursion.

    int n = 10;

    cout << printFibonacci(n);
}