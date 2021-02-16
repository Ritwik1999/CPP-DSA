/*
    Given an input string (STR),
    find and return all possible permutations of the input string.

    NOTE: The input string may contain the same characters,
    so there will also be the same permutations.

    The order of permutations doesn’t matter.
*/

#include <iostream>
#include <string>
using namespace std;

void printPerms(string input, string output)
{
    // Base Case
    if (input.size() == 0)
    {
        cout << output << endl;
        return;
    }

    // Computation and Recursion
    for (int i = 0; i < input.size(); i++)
    {
        printPerms(input.substr(0, i) + input.substr(i + 1), output + input[i]);
    }

    return;
}

void printPermutations(string input)
{
    printPerms(input, "");
    return;
}

int main()
{
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}
