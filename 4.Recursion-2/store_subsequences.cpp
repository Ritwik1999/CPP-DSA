/*
    Different subsequences of a string can be generated by dropping or retaining
    characters at different positions, without changing their relative order.

    e.g., subsequences of the string "abc" are "", "a", "b", "c", "ab", "bc", "ac", and "abc"

    Note: A string of length n can have (2^n) subsequences.
*/
#include <bits/stdc++.h>
using namespace std;

// Returns the size of output array
int subseq(string input, string output[])
{
    // Base Case
    if (input.size() == 0)
    {
        output[0] = "";
        return 1;
    }

    // Recursion
    int smallerOutputSize = subseq(input.substr(1), output);

    // Computation i.e., duplicate the contents of output so far, and add each of it back to output, but prefixed with input[0]
    for (int i = 0; i < smallerOutputSize; i++)
    {
        output[i+smallerOutputSize] = input[0] + output[i];
    }

    return 2 * smallerOutputSize;
}

int main()
{
    string s;
    cin >> s;

    int len = (int)(pow(2, s.size()) + 0.5);
    string *output = new string[len];

    len = subseq(s, output); // len is reassigned the same value, just to suit the function signature

    for (int i = 0; i < len; i++)
    {
        cout << output[i] << endl;
    }

    delete[] output;

    return 0;
}