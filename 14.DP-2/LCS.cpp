/*
Given two strings, return the length of the Longest Common Subsequence of characters.
LCS is any sequence that is common to both strings, not necessarily continuous, but occurs in both the strings in the same order
*/

/*
Appraoch: Compare the first characters of both the strings, If they match, we are sure that these will be included in the LCS.
In that case, call recursion, increment its answer by 1, and return

If the first character is not matching, then either the first character of the first string is part of the LCS,
or the first character of the second string is in the LCS, or both are not.
Call recursion for all the three cases, and return the maximum answer amongst the three

NOTE: Even if you omit the last call, it will work fine because removing the first characters in both strings is the same as removing first in either, then removing first in the other one (in the former's recursive call)
*/

#include <iostream>
using namespace std;

// Brute Force. Complexity: O(3^n)
int lcs(string s, string t)
{
    // Base Case
    if (s.size() == 0 || t.size() == 0)
    {
        return 0;
    }

    // Recursive Calls
    if (s[0] == t[0])
    {
        return 1 + lcs(s.substr(1), t.substr(1));
    }
    else
    {

        int sFirstExcluded = lcs(s.substr(1), t);
        int tFirstExcluded = lcs(s, t.substr(1));
        int stFirstExcluded = lcs(s.substr(1), t.substr(1));

        return max(sFirstExcluded, max(tFirstExcluded, stFirstExcluded));
    }
}

// Memoization Time Complexity = Space Complexity = O(m*n)
int lcs_mem(string s, string t, int **output)
{
    int m = s.size();
    int n = t.size();

    // Base Case
    if (m == 0 || n == 0)
    {
        return 0;
    }

    // Check if answer already exists
    if (output[m][n] != -1)
    {
        return output[m][n];
    }

    // Recursive Calls
    int ans;
    if (s[0] == t[0])
    {
        ans = 1 + lcs_mem(s.substr(1), t.substr(1), output);
    }
    else
    {
        int sFirstExcluded = lcs_mem(s.substr(1), t, output);
        int tFirstExcluded = lcs_mem(s, t.substr(1), output);
        int stFirstExcluded = lcs_mem(s.substr(1), t.substr(1), output);

        ans = max(sFirstExcluded, max(tFirstExcluded, stFirstExcluded));
    }

    // Save your calculation
    output[m][n] = ans;

    return ans;
}

int lcs_mem(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **output = new int *[m + 1];

    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            output[i][j] = -1;
        }
    }

    // output[i][j] stores lcs of s(length = i) & t(length = j). Thus, the answer will be stored at output[m][n]
    return lcs_mem(s, t, output);
}

// DP Time Complexity = Space Complexity = O(m*n) 
int lcs_dp(string s, string t)
{
    int m = s.size();
    int n = t.size();

    int **output = new int *[m];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
    }

    // Fill the first row as it's cells satisy the base case
    for (int j = 0; j <= n; j++)
    {
        output[0][j] = 0;
    }

    // Fill the first column as it's cells satisy the base case
    for (int i = 0; i <= m; i++)
    {
        output[i][0] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // Remember: i is length of s, and j is length of t
            // Check if first character matches, and remember we remove characters from first, and not last
            if (s[m - i] == t[n - j])
            {
                output[i][j] = 1 + output[i - 1][j - 1];
            }
            else
            {
                int a = output[i - 1][j];
                int b = output[i][j - 1];
                int c = output[i - 1][j - 1];

                output[i][j] = max(a, max(b, c));
            }
        }
    }

    return output[m][n];
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << lcs(s, t) << endl;
    cout << lcs_mem(s, t) << endl;
    cout << lcs_dp(s, t) << endl;

    return 0;
}