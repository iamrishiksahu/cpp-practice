#include <iostream>

using namespace std;

bool isTravelPossible(int **arr, int i, int j, int n)
{

    // i is the row number
    // j is the col number
    // n is the size of tha matrix
    //**arr is the matrix pointer

    if (i < n && j < n && arr[i][j] == 1)
    {
        return true;
    }

    return false;
}

bool ratInMaze(int **arr, int i, int j, int n, int **sol)
{

    if (i == n - 1 && j == n - 1)
    {
        sol[i][j] = 1;
        return true;
    }

    if (isTravelPossible(arr, i, j, n))
    {

        sol[i][j] = 1;

        if (ratInMaze(arr, i + 1, j, n, sol))
        {
            return true;
        }

        if (ratInMaze(arr, i, j + 1, n, sol))
        {
            return true;
        }

        sol[i][j] = 0;

        return false;
    }

    return false;
}

// bool canRatGoToTheLastPoint (int **arr, int n, int, int sol[][]){

// }

int main()
{

    int rows, cols;

    cin >> rows;

    // allocating memory for rows
    int **mat = new int *[rows];

    // NOW WE NEED ANOTHER MATRIX WHERE WE CAN STORE
    // THE PATH IN THE FORM OF O AND 1.
    int **sol = new int *[rows];

    // we are building a square matrix so rows == columns
    cols = rows;
    // allocating memory for columns

    for (int i = 0; i < rows; i++)
    {
        mat[i] = new int[cols];
        sol[i] = new int[cols];
    }

    // taking user input row wise
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            cin >> mat[i][j];

            // also initializing the sol matrix.
            sol[i][j] = 0;
        }
    }

    bool isSolved = ratInMaze(mat, 0, 0, rows, sol);

    // Printing the solution matrix
    if (isSolved)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {

                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }else{
        cout<<"Oops! No way possible :(";
    }

    /*
     --> 1 0 1 0 1
         1 1 1 1 1
         0 1 0 1 0
         1 0 0 1 1
         1 1 1 0 1 <--

    */

    return 0;
}