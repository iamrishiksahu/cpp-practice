#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    int size;
    cout << "Enter the size of the array: " << endl;

    cin >> size;

    int array[size];

    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    cout << endl<< endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)

        {
            if (array[j] > array[j + 1])
            {
                swap(array, j, j + 1);
            }
        }
    }

    cout << endl
         << endl;

    printArray(array, size);

    return 0;
}