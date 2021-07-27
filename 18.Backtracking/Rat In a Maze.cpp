/*
You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents a maze and a rat starts from the top left cell and has to reach to the bottom right cell of the maze. The rat can move in all the four directions: up, down, left and right.
In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used to move from source to destination cell.
You have to print all the paths, following which rat can move from the top left cell to the bottom right cell of the given binary matrix.
*/

/*
Sample Input:
3
1 0 1
1 1 1
1 1 1
*/

#include <bits/stdc++.h>
using namespace std;

void printPaths(int **maze, int **output, int n, int x, int y)
{
    output[x][y] = 1;

    if (x == n - 1 && y == n - 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << output[i][j] << " ";
            }
        }
        cout << endl;
    }

    // Up
    if (x > 0 && maze[x - 1][y] != 0 && output[x - 1][y] != 1)
    {
        printPaths(maze, output, n, x - 1, y);
    }

    // Down
    if (x < n - 1 && maze[x + 1][y] != 0 && output[x + 1][y] != 1)
    {
        printPaths(maze, output, n, x + 1, y);
    }

    // Left
    if (y > 0 && maze[x][y - 1] != 0 && output[x][y - 1] != 1)
    {
        printPaths(maze, output, n, x, y - 1);
    }

    // Right
    if (y < n - 1 && maze[x][y + 1] != 0 && output[x][y + 1] != 1)
    {
        printPaths(maze, output, n, x, y + 1);
    }

    output[x][y] = 0;

    return;
}

int main()
{
    int n;
    cin >> n;

    int **maze = new int *[n];
    int **output = new int *[n];
    for (int i = 0; i < n; i++)
    {
        maze[i] = new int[n];
        output[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            int value;
            cin >> value;
            maze[i][j] = value;
            output[i][j] = 0;
        }
    }

    printPaths(maze, output, n, 0, 0);

    for (int i = 0; i < n; i++)
    {
        delete[] maze[i];
        delete[] output[i];
    }

    delete[] maze;
    delete[] output;
    return 0;
}