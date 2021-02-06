/*
    Given an int array (input), it's size, another integer, and another array(output),
    fill the output array with indices of the integer's occurences in the input array,
    and return it's size.

    e.g.,
    Input:  
    5
    9 8 10 8 8
    8

    Output:
    1 3 4
*/

/*
    Two methods:
    1. Split after the first element in the input array (M1.png)
    2. Split after the second element in the input array (M2.png)
*/

// Code for method 1.

#include <iostream>
using namespace std;

int allIndexes(int input[], int size, int x, int output[])
{
    if (size == 0)
    {
        return 0;
    }

    int smallerOutput = allIndexes(input + 1, size - 1, x, output);

    for (int i = 0; i < smallerOutput; i++)
    {
        output[i]++;
    }

    if (input[0] == x)
    {
        smallerOutput++;
        for (int i = smallerOutput; i > 0; i--)
        {
            output[i] = output[i - 1];
        }
        output[0] = 0;
    }

    return smallerOutput;
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int x;

    cin >> x;

    int *output = new int[n];

    int size = allIndexes(input, n, x, output);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }

    delete[] input;

    delete[] output;

    return 0;
}