/*
    Given a (numeric) string, convert it, recursively, into its int equivalent.

    NOTE: The string can begin with leading zeros.

    Algo:
    1. Drop all the leading zeros
    2. Take the leading digit at each step, convert and compute its value
    3. Recur for further digits.
*/

#include <iostream>
using namespace std;
#include<cstring>

int pow(int base, int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }
    
    int ans = 1;
    for (int i = 1; i <= exponent; i++)
    {
        ans *= base;
    }
    return ans;
}

int strToNum(char input[])
{
    if (input[0] == '\0')
    {
        return 0;
    }
    
    int smallerOutput = strToNum(input+1);
    
    int len = strlen(input);
    int placeValue = pow(10, len-1);
    int faceValue = ((int)input[0]) - 48;
    int value = faceValue * placeValue;
    
    return (value + smallerOutput);  
}

int stringToNumber(char input[]) {
    int i = 0;
    while(input[0] != '\0' && input[i] == '0')
    {
        i++;
    }
    
    int answer = strToNum(input+i);
    return answer;
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
