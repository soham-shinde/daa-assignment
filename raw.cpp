#include <iostream>
#include <vector>
using namespace std;

void printMatrix(const vector<vector<int>>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j])
            {
                cout << "Q\t";
            }
            else
            {
                cout << ".\t";
            }
        }
        cout << endl;
    }
}

bool isSafePlace(const vector<vector<int>>& matrix, int row, int col)
{
    int i, j;

    // Check in the current column
    for (i = 0; i < col; i++)
    {
        if (matrix[row][i])
            return false;
    }

    // Check in the upper-left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (matrix[i][j])
            return false;
    }

    // Check in the lower-left diagonal
    for (i = row, j = col; i < matrix.size() && j >= 0; i++, j--)
    {
        if (matrix[i][j])
            return false;
    }

    return true;
}

bool placeQueen(vector<vector<int>>& matrix, int col)
{
    if (col >= matrix.size())
    {
        return true;
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        if (isSafePlace(matrix, i, col))
        {
            matrix[i][col] = 1;
            if (placeQueen(matrix, col + 1))
            {
                return true;
            }
            matrix[i][col] = 0;
        }
    }
    return false;
}

int main()
{
    int n;

    cout << "Enter the number of queens: ";
    cin >> n;
    if (n <= 3)
    {
        cout << "Number of queens should be greater than 3." << endl;
        return 0;
    }
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    if (!placeQueen(matrix, 0))
    {
        cout << "Solution does not exist" << endl;
        return 1;
    }
    printMatrix(matrix);
    cout << endl;

    return 0;
}
