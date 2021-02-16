/*
    Given a string S, find and return all the possible permutations
    of the input string.

    Note 1 : The order of permutations is not important.
    Note 2 : If original string contains duplicate characters,
    permutations will also be duplicates.
*/

#include <iostream>
#include <string>
using namespace std;

#include <string>
using namespace std;

int returnPermutations(string input, string output[])
{
    // Base Case
    if (input.size() == 1)
    {
        output[0] = input[0];
        return 1;
    }

    // Recursion
    int smallerOutput = returnPermutations(input.substr(1), output);

    // Computation
    char newChar = input[0];
    int slen = input.size();

    for (int i = smallerOutput - 1; i > 0; i--)
    {
        output[i * slen] = output[i];
    }

    for (int i = 0; i < smallerOutput; i++)
    {
        string s = output[i * slen];
        for (int j = 0; j < slen; j++)
        {
            output[i * slen + j] = s.substr(0, j) + newChar + s.substr(j);
        }
    }

    return smallerOutput * (slen);
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
