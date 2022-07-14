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

// TIP: Debug the program for better understanding
int main()
{
    int m, n;
    cin >> m >> n;
    int **p = new int *[m];     // p would just store a single address, which would be the base address of an array of integer pointers
    for (int i = 0; i < m; i++)
    {
        p[i] = new int[i + 1];  // p[i] or *(p+i) would contain the base address of an array of integers.
        for (int j = 0; j < n; j++)
        {
            cin >> p[i][j];
        }
    }

    // output the 2d array
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < m; i++)
    {
        delete[] p[i];
    }
    delete[] p;

    return 0;
}