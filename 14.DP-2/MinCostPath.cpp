/*
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i, j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
The cost of a path is defined as the sum of each cell's values through which the route passes.
*/

/*
Sample Input 1:
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1:
13

Sample Input 2:
3 4
10 6 9 0
-23 8 9 90
-200 0 89 200
Sample Output 2:
76

Sample Input 3:
5 6
9 6 0 12 90 1
2 7 8 5 78 6
1 6 0 5 10 -4 
9 6 2 -10 7 4
10 -2 0 5 5 7
Sample Output 3:
18
*/

#include <iostream>
#include <climits>
using namespace std;

// Brute force approach. Complexity: O(3^t), where t = max(m, n)
int minCostPath(int **input, int m, int n, int i, int j)
{
    // Base Case
    if (i == m - 1 && j == n - 1)
    {
        return input[i][j];
    }

    // Out of range check
    if (i >= m || j >= n)
    {
        return INT_MAX;
    }

    // Recursive Calls
    int right = minCostPath(input, m, n, i, j + 1);
    int diagonal = minCostPath(input, m, n, i + 1, j + 1);
    int down = minCostPath(input, m, n, i + 1, j);

    // Computation
    int ans = min(right, min(diagonal, down)) + input[i][j];

    return ans;
}

int minCostPath(int **input, int m, int n)
{
    return minCostPath(input, m, n, 0, 0);
}

// Memoization approach. Complexity: O(m*n)
int minCostPath_Mem(int **input, int m, int n, int i, int j, int **output)
{
    // Base Case
    if (i == m - 1 && j == n - 1)
    {
        return input[i][j];
    }

    // Out of range check
    if (i >= m || j >= n)
    {
        return INT_MAX;
    }

    // Check if answer already exists
    if (output[i][j] != -1)
    {
        return output[i][j];
    }

    // Recursive Calls
    int right = minCostPath_Mem(input, m, n, i, j + 1, output);
    int diagonal = minCostPath_Mem(input, m, n, i + 1, j + 1, output);
    int down = minCostPath_Mem(input, m, n, i + 1, j, output);

    // Computation
    int cost = min(right, min(diagonal, down)) + input[i][j];

    // Save the answer for future use
    output[i][j] = cost;

    return cost;
}

int minCostPath_Mem(int **input, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            output[i][j] = -1;
        }
    }

    int minCost = minCostPath_Mem(input, m, n, 0, 0, output);

    for (int i = 0; i < m; i++)
    {
        delete[] output[i];
    }

    delete[] output;

    return minCost;
}

int minCostPath_DP(int **input, int m, int n)
{
    int **output = new int *[m];

    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
    }

    // Fill the destination cell as it has no dependency
    output[m - 1][n - 1] = input[m - 1][n - 1];

    // Now, fill the last row from right to left, as each of them has only one dependent, the cell on their right (other dependencies are out of range)
    for (int j = n - 2; j >= 0; j--)
    {
        output[m - 1][j] = output[m - 1][j + 1] + input[m - 1][j];
    }

    // Fill last column from bottom to top
    for (int i = m - 2; i >= 0; i--)
    {
        output[i][n - 1] = output[i + 1][n - 1] + input[i][n - 1];
    }

    // Fill remaining cells
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            output[i][j] = min(output[i+1][j], min(output[i+1][j+1], output[i][j+1])) + input[i][j];
        }
    }

    int ans = output[0][0];

    for (int i = 0; i < m; i++)
    {
        delete[] output[i];
    }

    delete[] output;

    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;
    int **input = new int *[m];
    for (int i = 0; i < m; i++)
    {
        input[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> input[i][j];
        }
    }

    cout << minCostPath(input, m, n) << endl;
    cout << minCostPath_Mem(input, m, n) << endl;
    cout << minCostPath_DP(input, m, n) << endl;

    for (int i = 0; i < m; i++)
    {
        delete[] input[i];
    }

    delete[] input;

    return 0;
}