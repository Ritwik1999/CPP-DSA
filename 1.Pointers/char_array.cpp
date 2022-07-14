#include <iostream>
using namespace std;

int main()
{
    int a[] = {1, 2, 3};
    char b[] = "abc";

    cout << a << endl;
    cout << b << endl;
    cout << b[1] << endl;
    cout << (void *) b << endl;

    // b = "Ritwik";    Not possible; vars of type char [] are constant literals

    char *p = &b[1];
    cout << p << endl;

    /*
        The inconsistent behaviour is because << is overloaded.
        It's behaviour changes around char*, in that it streams out
        until it encounters the null character, '\0'. 
    */

    char StringLiteral[] = "Ritzy 123";           // Auto-terminated with null character, safe.
    char CharArray[] = {'h', 'e', 'l', 'l', 'o'}; // Not auto-terminated, unsafe.

    char c1 = 'a';
    char *cp = &c1;

    cout << c1 << endl;
    cout << cp << endl; // Will print till it encounters a \0 character

    cout << &(CharArray[4]) << endl;    // Will print till it encounters a \0 character
    cout << &(StringLiteral[4]) << endl;

    char *cap = &CharArray[0];
    cout << cap << endl;    // Will print till it encounters a \0 character

    /*
        Again, the above behaviour is because of << operator.
        In case of a string literal, it is auto terminated by a '\0', and
        that does not happen with char.
        So, when you try to stream out a pointer to char,
        it prints until it encounters '\0'.
    */

    cout << sizeof(CharArray) << endl;
    cout << sizeof(StringLiteral) << endl;

    CharArray[1] = 'i';
    cout << CharArray << endl;  // Will print till it encounters a \0 character

    StringLiteral[1] = 'o';
    cout << StringLiteral << endl;

    return 0;
}