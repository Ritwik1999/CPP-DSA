/*
Given an integer h, find the possible number of balanced binary trees of height h.
You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
*/

// NOTE: Complexity wise, this problem is identical to the Fibonacci problem

/*
Sol: From the definition of a balanced BT, for a tree of height h to be balanced, the possible heights of
(left subtree, right subtree) could either be (h-1, h-1) or (h-2, h-1) or (h-1, h-2).

Calculate these values using recursion, and the answer is number of possible combinations
*/

#include <iostream>
#include <cmath>
using namespace std;

//Brute Force approach
int balancedBTs(int h)
{
    // Base Case
    if (h <= 1)
    {
        return 1;
    }

    // Recursion
    long h1 = balancedBTs(h - 1);
    long h2 = balancedBTs(h - 2);

    // Computation
    int count = ((h1 * h1) + 2 * (h1 * h2)) % 1000000007;

    return count;
}

// Memoization approach
int balancedBTsHelper(int h, int *arr)
{
    // Base Case
    if (h <= 1)
    {
        arr[h] = 1;
        return 1;
    }

    // Check if the output has already been computed
    if (arr[h] != -1)
    {
        return arr[h];
    }

    // Recursive Call
    long x = balancedBTsHelper(h - 1, arr);
    long y = balancedBTsHelper(h - 2, arr);

    // Calculate
    int count = ((x * x) + (2 * x * y)) % 1000000007;

    arr[h] = count;

    return count;
}

int balancedBTs_2(int h)
{
    int *arr = new int[h + 1];

    for (int i = 0; i <= h; i++)
    {
        arr[i] = -1;
    }

    return balancedBTsHelper(h, arr);
}

// DP approach
int balancedBTs_3(int h)
{
    int *arr = new int[h + 1];

    arr[0] = arr[1] = 1;

    for (int i = 2; i <= h; i++)
    {
        long x = arr[i - 1];
        long y = arr[i - 2];

        int count = ((x * x) + (2 * x * y)) % 1000000007;

        arr[i] = count;
    }

    return arr[h];
}

int main()
{
    int h;
    cin >> h;
    cout << balancedBTs(h) << endl;
    cout << balancedBTs_2(h) << endl;
    cout << balancedBTs_3(h) << endl;

    return 0;
}