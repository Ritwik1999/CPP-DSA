/*
    Given a string, check if it is a palindrome using recursion.
*/

#include <iostream>
#include <cstring>
using namespace std;

bool helper(char s[], int start, int end)
{
    if (start >= end)
    {
        return true;
    }

    if (s[start] != s[end])
    {
        return false;
    }

    return helper(s, start+1, end-1);
}

bool checkPalindrome(char input[])
{
    int len = strlen(input);
    // cout << input << endl;
    // cout << strlen(input) << endl;

    return helper(input, 0, len-1);
}

int main()
{
    char input[50];
    cin >> input;

    if (checkPalindrome(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}