#include <iostream>

using namespace std;

int main()
{

    int n, m;

    cin >> n >> m;

    int arr[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << endl
         << endl;

    // print the spiral matrix

    int rowStart = 0, rowEnd = n - 1, colStart = 0, colEnd = m - 1;

    while (rowStart <= rowEnd && colStart <= colEnd)
    {

        for (int col = colStart; col <= colEnd; col++)
        {
            cout << arr[rowStart][col];
        }


        rowStart++;

        for (int row = rowStart; row <= rowEnd; row++)
        {
            cout << arr[row][colEnd];
        }

        colEnd--;
        


        for (int col = colEnd; col >= colStart; col--)
        {
            cout << arr[rowEnd][col];
        }

        rowEnd--;


        for (int row = rowEnd; row >= rowStart; row--)
        {
            cout << arr[row][colStart];
        }
        colStart++;

    }

    // //searching in the matrix
    // for(int i=0; i<n; i++){
    //     for(int j=0;j<m;j++){
    //         if(5 == arr[i][j]){
    //             cout<<"Hurray! Element '"<<arr[i][j]<<"' found and it is present at ("<<i+1<<","<<j+1<<").";
    //         }

    //     }
    // }

    return 0;
}