#include <bits/stdc++.h>

using namespace std;

void printMatrix(vector<vector<int>>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i][j])
            {

                cout << "Q" << j << "\t";
            }
            else
            {
                cout << " ."
                     << "\t";
            }
        }
        cout << endl;
    }
}

bool isSafePlace(const vector<vector<int>>& matrix, int row, int col)
{
    int i,j;

    // for check in col
    for (i = 0; i < col; i++)
    {
        if (matrix[row][i])
            return false;
    }

    // for check in upper diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (matrix[i][j])
            return false;
    }

    // for check in lower diagonal
    for (i = row, j = col; i < matrix.size() && j >= 0; i++, j--)
    {
        if (matrix[i][j])
            return false;
    }

    return true;
}

bool placeQueen(vector<vector<int>>& matrix, int col)
{
    if (col >= matrix[0].size())
    {
        return true;
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        if (isSafePlace(matrix, i, col))
        {
            matrix[i][col] = 1;
            printMatrix(matrix);
            cout<<"\n----------------------"<<endl;

            if (placeQueen(matrix, col + 1))
            {
                
                return true;
            }
            cout<<"\nBackTrack"<<endl;
            cout<<"\n----------------------"<<endl;

            matrix[i][col] = 0;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n;

    cout << "\nEnter the queen numbers : ";
    cin >> n;
    if (n <= 3)
    {
        cout << "\nQueen numbers should be greater than 3\n";
        return 0;
    }
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    if (!placeQueen(matrix, 0))
    {
        cout << "solution not exist" << endl;
        return 1;
    }
    printMatrix(matrix);
    cout << "\n";

    return 0;
}
