#include <iostream>
using namespace std;

int main()
{

    int n; // size of the array

    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    const int N = 1e5;
    bool check[N];

    for (int i = 0; i < N; i++)
    {
        check[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            check[arr[i]] = true;
        }
    }

    int i = 1;
    while (check[i] != false)
    {
        i++;
    }

    cout << "asn: " << i;

    return 0;
}