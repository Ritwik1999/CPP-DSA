/*
    Given an integer n, using phone keypad find out all the
    possible strings that can be made using digits of input n.
    Return empty string for numbers 0 and 1.
*/

#include <iostream>
#include <string>
using namespace std;

int keypad(int num, string output[], string options[])
{
    // Base Case
    if (num == 0)
    {
        output[0] = "";
        return 1;
    }

    // Recursion
    int smallerOutputSize = keypad(num / 10, output, options);

    // Computation
    int onesDigit = num % 10;
    string digitString = options[onesDigit];
    int digitStringLength = digitString.size();
    int ans = digitStringLength * smallerOutputSize;
    string *tempStr = new string[ans];

    for (int i = 0; i < digitStringLength; i++)
    {
        for (int j = 0; j < smallerOutputSize; j++)
        {
            tempStr[j + i * smallerOutputSize] = output[j] + digitString[i];
        }
    }

    for (int k = 0; k < ans; k++)
    {
        output[k] = tempStr[k];
    }

    delete[] tempStr;

    return ans;
}

int main()
{
    int num;
    cin >> num;

    string output[10000];
    string keypadStrings[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    int count = keypad(num, output, keypadStrings);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
