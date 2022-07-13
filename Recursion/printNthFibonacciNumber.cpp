#include <iostream>

using namespace std;


int nThfiboncacci(int n)
{

    if (n == 0 || n == 1)
    {
        return n;
    }

    return nThfiboncacci(n - 1) + nThfiboncacci(n - 2);
}

int main()
{

    int a;

    cin >> a;

    cout << nThfiboncacci(a);

    return 0;
}