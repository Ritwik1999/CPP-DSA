/*
It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's.
But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?

Input Format :
The first line of input contains an integer, that denotes the value of N. 
Each of the following N lines contain N space separated integers.

Output Format :
Print the count of '1's in the biggest piece of '1's, according to the description in the task.

Constraints :
1 <= N <= 1000
*/

/*
Sample Input:
3
1 0 0
0 1 0
0 1 0

Sample Output:
2
*/

#include <iostream>
#include <vector>
using namespace std;

int getPieceSize(vector<vector<int>> &cake, bool **visited, int n, int i, int j)
{
    if (visited[i][j])
    {
        return 0;
    }

    visited[i][j] = true;
    int currentSize = 0;

    // left
    if (j > 0 && cake[i][j - 1] == 1)
    {
        currentSize += getPieceSize(cake, visited, n, i, j - 1);
    }

    // right
    if (j < n - 1 && cake[i][j + 1] == 1)
    {
        currentSize += getPieceSize(cake, visited, n, i, j + 1);
    }

    // up
    if (i > 0 && cake[i - 1][j] == 1)
    {
        currentSize += getPieceSize(cake, visited, n, i - 1, j);
    }

    // down
    if (i < n - 1 && cake[i + 1][j] == 1)
    {
        currentSize += getPieceSize(cake, visited, n, i + 1, j);
    }

    currentSize += 1;

    return currentSize;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{

    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            if (cake[i][j] == 1)
            {
                visited[i][j] = false;
            }
            else
            {
                visited[i][j] = true;
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cake[i][j] == 1 && !visited[i][j])
            {
                ans = max(ans, getPieceSize(cake, visited, n, i, j));
            }
        }
    }

    // free memory
    for (int i = 0; i < n; i++)
    {
        delete[] visited[i];
    }

    delete[] visited;

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n) << endl;
}