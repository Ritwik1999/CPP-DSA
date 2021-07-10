/*
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time.
Implement a method to count and return all possible ways in which the child can run-up to the stairs.
*/

#include <iostream>
using namespace std;

// Brute-force approach. Complexity: O(3^n)
long staircase(int n)
{
    if (n < 0)
    {
        return 0;
    }

    if (n <= 1)
    {
        return 1;
    }

    long oneStep = staircase(n - 1);
    long twoSteps = staircase(n - 2);
    long threeSteps = staircase(n - 3);

    return oneStep + twoSteps + threeSteps;
}

// Memoization. Complexity: O(n)
long staircaseHelper(int n, long *arr)
{
    // Base Cases
    if (n < 0)
    {
        return 0;
    }

    if (n <= 1)
    {
        arr[n] = 1;
        return 1;
    }

    // Check if the output exists
    if (arr[n] != -1)
    {
        return arr[n];
    }

    //Computation

    long oneStep = staircaseHelper(n - 1, arr);
    long twoSteps = staircaseHelper(n - 2, arr);
    long threeSteps = staircaseHelper(n - 3, arr);

    arr[n] = oneStep + twoSteps + threeSteps;

    return arr[n];
}

long staircase_2(int n)
{
    long *arr = new long[n + 1];

    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }

    return staircaseHelper(n, arr);
}

// DP Complexity: O(n)
long staircase_3(int n)
{
    long *arr = new long[n + 1];

    arr[0] = arr[1] = 1;
    arr[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }

    return arr[n];
}

int main()
{
    int n;
    cin >> n;
    cout << staircase(n);
    cout << staircase_2(n);
    cout << staircase_3(n);
}