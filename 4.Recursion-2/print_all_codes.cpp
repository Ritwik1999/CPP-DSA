/*
    Assume that the value of a = 1, b = 2, c = 3, ... , z = 26.
    You are given a numeric string S.
    Write a program to print the list of all possible codes that can be
    generated from the given string.
*/

#include <iostream>
using namespace std;

#include <string.h>
using namespace std;

int str2int(string s)
{
    int num = 0, j;
    for (int i = 0; i < s.size(); i++)
    {
        j = s[i] - '0';
        num = (num * 10) + j;
    }

    return num;
}

char int2alphabet(int n)
{
    return (char)(n + 96);
}

void doIt(string input, string output)
{
    // Base Case
    if (input.empty())
    {
        cout << output << endl;
        return;
    }

    // Computation and Recursion
    char subOutput1 = int2alphabet(str2int(input.substr(0, 1)));
    doIt(input.substr(1), output + subOutput1);

    if (input.size() > 1)
    {
        int subOutput2 = str2int(input.substr(0, 2));

        if (subOutput2 >= 10 && subOutput2 <= 26)
        {
            doIt(input.substr(2), output + int2alphabet(subOutput2));
        }
    }

    return;
}

void printAllPossibleCodes(string input)
{
    string output = "";
    doIt(input, output);

    return;
}

int main()
{
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}