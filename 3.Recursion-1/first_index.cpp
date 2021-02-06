/*
    Given an integer array, its size, and another integer, 
    return the first index where the element is present, 
    or return -1 if the element is not present in the array.

    Algo:
    1. Base case: If the size becomes zero, return -1.
    2a. Optimization: If array[0] has the element, return 0 (to avoid unnecessary recursion)
    2b. Recursion: Check if the subsequent array contains the element.
    3. Computation: If recursion returns -1, return -1, else return 
        recursive answer + 1, to adjust index. 
*/

#include <iostream>
using namespace std;

int firstIndex(int input[], int size, int x)
{
    if (size == 0)
    {
        return -1;
    }

    if (input[0] == x)
    {
        return 0;
    }

    int smallerFound = firstIndex(input + 1, size - 1, x);

    if (smallerFound == -1)
    {
        return -1;
    }
    else
    {
        return (smallerFound + 1);
    }
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

    cout << firstIndex(input, n, x) << endl;
}