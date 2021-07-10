#include <iostream>
using namespace std;

// Complexity: O(2^n); Brute-force approach
int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }

    int a = fib(n - 1);
    int b = fib(n - 2);

    return a + b;
}

// Complexity: O(n+1) i.e. O(n). Because we only do n+1 unique calculations, and save them all for future reference
// The process below is called Memoization, a top-down approach, because to calculate nth ans, we calculate (n-1)th answer, and so on, i.e., start from the top, and move down
int fib_helper(int n, int *ans)
{
    // Base Case
    if (n <= 1)
    {
        return n;
    }

    // Check if the output has already been calculated
    if (ans[n] != -1)
    {
        return ans[n];
    }

    // If not, calculate the answer
    int a = fib_helper(n - 1, ans);
    int b = fib_helper(n - 2, ans);

    // Save the answer for future use
    ans[n] = a + b;

    return ans[n];
}

// Complexity: O(n+1) i.e. O(n). Because we only do n+1 unique calculations, and save them all for future reference
// The process below is called Dynamic Programming, a bottom-up approach, because to calculate nth ans, we start building our array from the bottom, towards the top
int fib3 (int n) {
    int *ans = new int[n+1];

    ans[0] = 0;
    ans[1] = 1;

    for (int i = 2; i <= n; i++) {
        ans[i] = ans[i-1] + ans[i-2];
    }

    return ans[n];
}

int fib2(int n)
{   
    // Size is n+1 (from 0 to n) as ans[i] would store ith Fibonacci number
    int *ans = new int[n + 1];

    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }

    return fib_helper(n, ans);
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;

    return 0;
}