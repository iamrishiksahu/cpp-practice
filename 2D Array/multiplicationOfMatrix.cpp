#include <iostream>

using namespace std;

int main()
{

    int n, m, l;

    cin >> n >> m >> l;


    int mat1[n][m], mat2[m][l];

    //taking input int mat1

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat1[i][j];
        }
    }

    //taking input int mat2

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < l; j++)
        {
            cin >> mat2[i][j];
        }
    }

    cout<<endl;

    int out[n][l];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < l; j++)
        {
            //initializing the elements of the new matrix hand-in-hand
            out[i][j] = 0;

            for (int k = 0; k < m; k++)
            {
                out[i][j] += mat1[i][k] * mat2[k][j];
            }
            
            //printing the elements of the resultant matrix hand-in-hand
            cout << out[i][j] << "\t";
        }

        cout << endl;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < l; j++)
    //     {

    //         out[i][j] = 0;
    //         for (int k = 0; k < m; k++)
    //         {

    //             out[i][j] += mat1[i][k] * mat2[k][j];
    //         }
    //     }
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < l; j++)
    //     {
    //         cout << out[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}