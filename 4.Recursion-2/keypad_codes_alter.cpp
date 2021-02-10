/*
    Constant Storage version of keypad_codes problem, useful only when the combos 
    are to be printed, and not stored.
*/

#include <iostream>
#include <string>
using namespace std;

void printKeypadCombos(int num, string output, string keyStrings[])
{
    // Base Case
    if (num == 0)
    {
        cout << output << endl;
        return;
    }
    
    // Computation
    int lastDigit = num%10;
    string digitString = keyStrings[lastDigit];
    int digitStringLength = digitString.size();
    
    // Recursion, i.e., for each char in the keypadString of lastDigit, recur with num/10.
    for (int i = 0; i < digitStringLength; i++)
    {
        printKeypadCombos(num/10, digitString[i] + output, keyStrings);
    }
    
    return;    
}

void printKeypad(int num){
    string keyStrings[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string output = "";
    printKeypadCombos(num, output, keyStrings);
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}

