/*
Given two strings, return the minimum number of operations needed to convert one string
into the other.

The operations allowed are: 
1) Insert a character
2) Delete a character
3) Update/Replace a character

NOTE: Do not change the inpur strings at all, just return the count of operations.
*/

/*
Approach: Compare the first two characters of both the strings, if they are equal, cakk recursion.
If not, you have three options, call each of them one by one, compute the minimum, and return it after incrementing it by one
*/

#include <iostream>
using namespace std;

// Brute Force. Complexity: O(3^n), n = max(s.size(), t.size())
int editDistance(string s, string t)
{
    // Base Case
    if (s.size() == 0 || t.size() == 0)
    {
        return max(s.size(), t.size());
    }

    if (s[0] == t[0])
    {
        return editDistance(s.substr(1), t.substr(1));
    }
    else
    {
        // choose any one string to operate on, and suitably invoke recursion
        // Insert
        int x = editDistance(s.substr(1), t) + 1;
        // Delete
        int y = editDistance(s, t.substr(1)) + 1;
        // Replace
        int z = editDistance(s.substr(1), t.substr(1)) + 1;

        return min(x, min(y, z));
    }
}

// Time Complexity = Space Complexity = O(mn)
int editDistanceMem(string s, string t, int **output)
{

    int m = s.size();
    int n = t.size();

    // Base Case
    if (m == 0 || n == 0)
    {
        return max(s.size(), t.size());
    }

    // Check if answer is already present
    if (output[m][n] != -1)
    {
        return output[m][n];
    }

    int ans;
    if (s[0] == t[0])
    {
        ans = editDistanceMem(s.substr(1), t.substr(1), output);
    }
    else
    {
        // choose any one string to operate on, and suitably invoke recursion
        // Insert
        int x = editDistanceMem(s.substr(1), t, output) + 1;
        // Delete
        int y = editDistanceMem(s, t.substr(1), output) + 1;
        // Replace
        int z = editDistanceMem(s.substr(1), t.substr(1), output) + 1;

        ans = min(x, min(y, z));
    }

    // Save the answer
    output[m][n] = ans;

    return ans;
}

int editDistanceMem(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();

    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            output[i][j] = -1;
        }
    }

    return editDistanceMem(s1, s2, output);
}

int editDistanceDP(string s, string t)
{
    int m = s.size();
    int n = t.size();

    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
    }

    // Fill the first row as it's cells satisfy base case
    for (int j = 0; j <= n; j++)
    {
        output[0][j] = j;
    }

    // Fill the first column as it's cells satisfy base case
    for (int i = 0; i <= m; i++)
    {
        output[i][0] = i;
    }

    // Fill the remaining cells
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[m - i] == t[n - j])
            {
                output[i][j] = output[i - 1][j - 1];
            }
            else
            {
                int a = output[i - 1][j] + 1;
                int b = output[i][j - 1] + 1;
                int c = output[i - 1][j - 1] + 1;

                output[i][j] = min(a, min(b, c));
            }
        }
    }

    return output[m][n];
}

int main()
{
    string s = "abcdf";
    string t = "afd";

    cout << editDistance(s, t) << endl;
    cout << editDistanceMem(s, t) << endl;
    cout << editDistanceDP(s, t) << endl;

    return 0;
}
