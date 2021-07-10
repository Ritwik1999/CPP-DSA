/*
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to be reduced to 1.
You can perform any one of the following 3 steps:

1) Subtract 1 from it (n = n - 1)
2) If n is divisible by 2, divide it by 2 (n = n / 2)
3) If n is divisible by 3, divide it by 3 (n = n / 3)

e.g., n = 10.
10 -> 5 -> 4 -> 2 -> 1 (steps = 4)
10 -> 9 -> 3 -> 1 (steps = 3) (correct solution) 
*/

#include <iostream>
using namespace std;

// Brute Force approach. Complexity: O(2^n) because on average, every value of n will make 2 calls. In very rare cases, complexity would be O(3^n) (for 3 calls for a given value of n)
int minSteps(int n)
{
    // Base Case
    if (n <= 1)
    {
        return 0;
    }

    int x = minSteps(n - 1);
    // Initialising them is necessary so as to avoid y, z having garbage values in case their conditionals are not executed.
    // Since the max steps to 1 for n is n itself
    int y = n;
    int z = n;
    if (n % 2 == 0)
        y = minSteps(n / 2);
    if (n % 3 == 0)
        z = minSteps(n / 3);

    int ans = min(x, min(y, z)) + 1;

    return ans;
}

// Memoization approach: Complexity: O(n) (See minStepsMemo.png)
int minStepsHelper(int n, int *ans)
{
    // Base Case
    if (n <= 1)
    {
        ans[n] = 0; // optional
        return 0;
    }

    // Check if output already exists
    if (ans[n] != -1)
    {
        return ans[n];
    }

    // Calculate output
    int x = minStepsHelper(n - 1, ans);
    int y = n, z = n;
    if (n % 2 == 0)
    {
        y = minStepsHelper(n / 2, ans);
    }
    if (n % 3 == 0)
    {
        z = minStepsHelper(n / 3, ans);
    }

    int output = min(x, min(y, z)) + 1;

    ans[n] = output;

    return output;
}

int minSteps_2(int n)
{
    int *ans = new int[n + 1];

    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }

    return minStepsHelper(n, ans);
}

// DP approach. Complexity: O(n)
int minStepsHelper_2(int n, int *arr) {
    int x, y, z;
    for (int i = 2; i <= n; i++) {
        x = y = z = n;
        x = arr[i-1] + 1;
        if (i % 2 == 0) {
            y = arr[i/2] + 1;
        }
        if (i % 3 == 0) {
            z = arr[i/3] + 1;
        }
        
        arr[i] = min(x, min(y,z));
    }
    
    return arr[n];
}

int minSteps_3(int n)
{
    int *arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 0;
    
    return minStepsHelper_2(n, arr);
}

int main()
{
    int n;
    cin >> n;
    cout << minSteps(n) << endl;

    return 0;
}