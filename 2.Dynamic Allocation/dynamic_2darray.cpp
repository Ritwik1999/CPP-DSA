/*

    Dynamic 2D arrays cannot be made with new int[n][m].
    However, we can dynamically make several 1D arrays at random locations
    on the heap, then make another 1D array of int* type that stores the starting
    address of each of these int arrays.

    This has the advantage that the 2D array need not be rectangular,
    it can have variable dimension for different indices.
*/

#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int **p = new int *[m];
    for (int i = 0; i < m; i++)
    {
        p[i] = new int[i + 1];
        for (int j = 0; j < n; j++)
        {
            cin >> p[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        delete[] p[i];
    }
    delete[] p;

    return 0;
}