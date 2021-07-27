#include <bits/stdc++.h>
using namespace std;

void NQueens(vector<vector<bool>> board, int n, int row)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j])
                {
                    cout << "1 ";
                }
                else
                {
                    cout << "0 ";
                }
            }
        }
        cout << endl;
        return;
    }

    // check if there is a possible position in the current row
    for (int k = 0; k < n; k++)
    {
        bool possiblePosition = true;
        // up
        for (int i = 0; i <= row; i++)
        {
            if (possiblePosition && board[i][k])
            {
                possiblePosition = false;
                break;
            }
        }

        // upper left
        for (int i = row, j = k; i >= 0 && j >= 0; i--, j--)
        {
            if (possiblePosition && board[i][j])
            {
                possiblePosition = false;
                break;
            }
        }

        // upper right
        for (int i = row, j = k; i >= 0 && j < n; i--, j++)
        {
            if (possiblePosition && board[i][j])
            {
                possiblePosition = false;
                break;
            }
        }

        if (possiblePosition)
        {
            board[row][k] = true;
            NQueens(board, n, row + 1);
        }

        board[row][k] = false;
    }

    return;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<bool>> board(n, vector<bool>(n, false));

    NQueens(board, n, 0);

    return 0;
}