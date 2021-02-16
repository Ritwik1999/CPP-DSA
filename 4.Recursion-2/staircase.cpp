/*
    A child is running up a staircase with N steps,
    and can hop either 1 step, 2 steps or 3 steps at a time.
    Implement a method to count how many possible ways the child can run up
    the stairs. You need to return number of possible ways W.
*/

#include <iostream>
using namespace std;

int staircase(int n)
{
    // Base Case
    if (n < 0)
    {
        return 0;
    }

    else if (n == 0)
    {
        return 1;
    }

    // Recursion
    int x = staircase(n - 1);
    int y = staircase(n - 2);
    int z = staircase(n - 3);

    // Computation
    int ans = x + y + z;

    return ans;
}

int main()
{
    int n, output;
    cin >> n;
    output = staircase(n);
    cout << output << endl;
}
