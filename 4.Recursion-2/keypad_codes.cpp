/*
    Given an integer n, using phone keypad find out all the
    possible strings that can be made using digits of input n.
    Return empty string for numbers 0 and 1.
*/

#include <iostream>
#include <string>
using namespace std;
    
string keypadStringOf(int digit)
{
    string res;
    switch (digit)
    {
    case 2:
        res = "abc";
        break;

    case 3:
        res = "def";
        break;

    case 4:
        res = "ghi";
        break;

    case 5:
        res = "jkl";
        break;

    case 6:
        res = "mno";
        break;

    case 7:
        res = "pqrs";
        break;

    case 8:
        res = "tuv";
        break;

    case 9:
        res = "wxyz";
        break;

    default:
        res = "";
        break;
    }

    return res;
}

int keypad(int num, string output[])
{
    // Base Case
    if (num == 0)
    {
        output[0] = "";
        return 1;
    }

    // Recursion
    int smallerOutputSize = keypad(num / 10, output);

    // Computation
    int onesDigit = num % 10;
    string digitString = keypadStringOf(onesDigit);
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
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
