#include <iostream>

using namespace std;

int main()
{

    int n, givenSum; // size of the array

    cin >> n >> givenSum;


    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int i = 0, j = 0, sum = 0;

    while (sum + arr[j] < givenSum)
    {
        sum += arr[j];
        j++;

        if (j == n - 1)
        {
            cout << "Not such subarray exists! 1 "<<sum<<" "<<j;
            return 0;
        }
 
    }
  
    sum += arr[j++];

    while (sum - arr[i] > givenSum)
    {
        sum -= arr[i];
        i++;
    }


    sum = sum - arr[i++];

    if (sum == givenSum)
    {
        cout << i+1 << " " << j;
    }else{
         cout << "Not such subarray exists! 2"<< sum<<" "<<i;
    }

    return 0;
}