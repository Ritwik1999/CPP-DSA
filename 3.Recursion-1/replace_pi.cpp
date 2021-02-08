/*
    Given a string, compute recursively a new string where 
    all appearances of "pi" have been replaced by "3.14".
*/

#include <iostream>
#include <cstring>
using namespace std;

void replacePi(char input[])
{
    // Base case
    if (input[0] == '\0')
    {
        return;
    }

    // Computation & Recusrion
    if (input[0] == 'p' && input[1] == 'i')
    {
        int len = strlen(input);
        for (int i = len - 1; i >= 2; i--)
        {
            input[i + 2] = input[i];
        }
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';

        replacePi(input + 4);
    }

    else
    {
        replacePi(input + 1);
    }
}

int main()
{
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
    return 0;
}
