/*
    Find last index of an element or -1.

    This, like first index can be done in two ways. 
    One, by traversing left to right.
    Second, by traversing right to left.
    
    For last index, following second method is easier, hence let's do the first method
*/

#include <iostream>
using namespace std;

int lastIndex(int input[], int size, int x)
{
    if (size == 0)
    {
        return -1;
    }

    int smallerOutput = lastIndex(input + 1, size - 1, x);

    if (smallerOutput == -1)
    {
        if (input[0] == x)
        {
            return 0;
        }

        return -1;
    }

    return smallerOutput + 1;
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

    cout << lastIndex(input, n, x) << endl;

    return 0;
}