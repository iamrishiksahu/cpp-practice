#include <iostream>

using namespace std;

int main()
{

    int n, m, l;

    cin >> n >> m >> l;

    int mat1[n][m], mat2[m][l];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat1[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < l; j++)
        {
            cin >> mat1[i][j];
        }
    }

 
    return 0;
}