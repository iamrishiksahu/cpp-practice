#include <iostream>

using namespace std;

int main()
{

    int arr[3] = {1, 2, 3};

    int totalSum = 0, currentSum = 0;

    // if you want to understand this then simply do a dry run

    for (int i = 0; i < 10; i++)
    {

        currentSum = 0;

        for (int j = i; j < 3; j++)
        {
            currentSum += arr[j];
            totalSum += currentSum;
            cout << currentSum << " ";
        }
    }

    cout << endl
         << totalSum;

    return 0;
}