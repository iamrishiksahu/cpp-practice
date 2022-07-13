#include <iostream>

using namespace std;

// Question: To print the maximum sum of a subarray.
// Note - I found that this algorithm is only valid for positive numbers.

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void maxSum(int arr[], int n)
{

    int maxSum = 0;

    cout << "Sum of each subarrays: ";

    for (int i = 0; i < n; i++)
    {
        int currSum = 0;

        for (int j = i; j < n; j++)
        {
            currSum += arr[j];

            //below statement prints the sum of each subarray
            cout << currSum << " ";
        }

        if (currSum > maxSum)
        {
            maxSum = currSum;
        }
    }

    cout << endl
         << "The max sum is: " << maxSum;
}

int main()
{

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    printArray(arr, n);

    maxSum(arr, n);

    return 0;
}
