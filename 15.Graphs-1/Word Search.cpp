/*
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “SHAKESPEARE” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.

Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix. 
Each of the following N lines contain M characters. Please note that characters are not space separated.

Output Format :
Print 1 if there is a path which makes the sentence “SHAKESPEARE” else print 0.

Constraints :
1 <= N <= 1000
1 <= M <= 1000
*/

/*
Sample Input 1:
4 4
SEAE
OHRP
DAKS
JNOE

Sample Output 1:
1

Sample Input 2:
5 5
DANDE
ENINS
AHGKC
INJAA
SOPDI

Sample Output 2:
0
*/

#include <iostream>
#include <vector>
using namespace std;

bool DFS(vector<vector<char>> &board, vector<vector<bool>> &visited, int n, int m, char *letters, int s, int i, int j)
{
    if (s == 0)
    {
        return true;
    }

    if (board[i][j] != letters[0] || visited[i][j])
    {
        return false;
    }

    visited[i][j] = true;

    bool ans = false;

    // upper left
    if (i > 0 && j > 0)
    {
        ans = ans || DFS(board, visited, n, m, letters + 1, s - 1, i - 1, j - 1);
    }

    // up
    if (i > 0)
    {
        ans = ans || DFS(board, visited, n, m, letters + 1, s - 1, i - 1, j);
    }

    // upper right
    if (i > 0 && j < m - 1)
    {
        ans = ans || DFS(board, visited, n, m, letters + 1, s - 1, i - 1, j + 1);
    }

    // left
    if (j > 0)
    {
        ans = ans || DFS(board, visited, n, m, letters + 1, s - 1, i, j - 1);
    }

    // right
    if (j < m - 1)
    {
        ans = ans || DFS(board, visited, n, m, letters + 1, s - 1, i, j + 1);
    }

    // lower left
    if (i < n - 1 && j > 0)
    {
        ans = ans || DFS(board, visited, n, m, letters + 1, s - 1, i + 1, j - 1);
    }

    // down
    if (i < n - 1)
    {
        ans = ans || DFS(board, visited, n, m, letters + 1, s - 1, i + 1, j);
    }

    // lower right
    if (i < n - 1 && j < m - 1)
    {
        ans = ans || DFS(board, visited, n, m, letters + 1, s - 1, i + 1, j + 1);
    }

    if (ans == false)
    {
        visited[i][j] = false;
    }

    return ans;
}

bool hasPath(vector<vector<char>> &board, int n, int m)
{
    char letters[] = {'S', 'H', 'A', 'K', 'E', 'S', 'P', 'E', 'A', 'R', 'E'};

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    bool ans = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == letters[0])
            {
                ans = ans || DFS(board, visited, n, m, letters, 11, i, j);
            }
        }
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0) << endl;

    return 0;
}