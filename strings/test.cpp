#include <iostream>
#include <string>

using namespace std;

int main()
{

    string s = "1876879203";

    // sort the string in descending order

    // implementing bubble sort

    int a = s.length() - 1, b = 0;

    for (int i = 0; i < a+1; i++)
    {

        cout<<"ghus ";
        for (int j = 0; j < s.length() -i-1 ; i++)
        {
            cout<<"chala ";
            int left = s[j] - '0';
            int right = s[j + 1] - '0';
            if (left < right)
            {
                int temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    // while (b < a - 1)
    // {

    //     for (int i = a; i > b; i--)
    //     {
    //         int left = s[i] - '0';
    //         int right = s[i + 1] - '0';
    //         if (left < right)
    //         {
    //             int temp = s[i];
    //             s[i] = s[i + 1];
    //             s[i + 1] = temp;
    //         }
    //     }

    //     b++;
    // }

    cout << s;

    // print it
}