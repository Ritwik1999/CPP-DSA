/*
    Suppose you have a string, S, made up of only 'a's and 'b's.
    Write a recursive function that checks if the string was
    generated using the following rules:

    a. The string begins with an 'a'
    b. Each 'a' is followed by nothing or an 'a' or "bb"
    c. Each "bb" is followed by nothing or an 'a'

    If all the rules are followed by the given string,
    return true otherwise return false.
*/

#include <iostream>
using namespace std;

bool verifyRules(char input[])
{
    // Base Case
    if (input[0] == '\0')
    {
        return true;
    }
    
    // Computation and Recursion
    if (input[0] == 'a')
    {
        return verifyRules(input+1);
    }
    
    else
    {
        if (input[1] == 'b' && input[2] != 'b')
        {
            return verifyRules(input+2);
        }
        
        return false;
    }
    
}

bool checkAB(char input[]) {
	// Rule 1 check
	if (input[0] != 'a')
    {
        return false;
    }
    
    return verifyRules(input+1);
}

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
    
    return 0;
}
