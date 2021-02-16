/*
    Given an array A of size n and an integer K,
    return all subsets of A which sum to K.
*/

/***
    Save all the subsets in the given 2D output array.
    And return the number of subsets(i.e. number of rows filled in output)
    from the given function.

    In ith row of output array, 1st column contains length of the ith subset.
    And from 2nd column actual subset follows.
    For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
        {{2, 1, 4},	// Length of this subset is 2
        {2, 3, 2}}	// Length of this subset is 2

    Don’t print the subsets, just save them in output.
***/

// The program generates segmentation fault message at runtime. Check it out

#include <iostream>
using namespace std;

int subsetSumToK(int input[], int n, int output[][50], int k)
{
    // Base Case
    if (n == 0)
    {
        if (k == 0)
        {
            output[0][0] = 0;
            return 1;
        }

        else
        {
            return 0;
        }
    }

    int output01[10000][50], output02[10000][50];

    // Recursion
    int including = subsetSumToK(input + 1, n - 1, output01, k - input[0]);
    int excluding = subsetSumToK(input + 1, n - 1, output02, k);

    // Computation
    if (including > 0)
    {
        for (int i = 0; i < including; i++)
        {
            for (int j = (output01[i][0] + 1); j > 1; j--)
            {
                output01[i][j] = output01[i][j - 1];
            }
            output01[i][1] = input[0];
            output01[i][0] += 1;
        }
    }

    for (int i = 0; i < including; i++)
    {
        for (int j = 0; j <= output01[i][0]; j++)
        {
            output[i][j] = output01[i][j];
        }
    }

    for (int i = 0; i < excluding; i++)
    {
        for (int j = 0; j <= output02[i][0]; j++)
        {
            output[including + i][j] = output02[i][j];
        }
    }

    return (including + excluding);
}

int main()
{
    int input[20], length, output[10000][50], k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    cin >> k;

    int size = subsetSumToK(input, length, output, k);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}