#include <iostream>
using namespace std;

int main()
{
    char StringLiteral[] = "Ritzy 123";     // (A)
    cout << StringLiteral << endl;
    cout << &StringLiteral[0] << endl;
    cout << StringLiteral[0] << endl;
    char *StringPointer = "Ritzy 123";      // (B)

    /*
        Line B would raise a warning, discouraging it's use.
        Whereas line A is fine. This is because in line A, we own the contents of the array,
        and hence we can modify it, but in line B, it is just a pointer to a 
        (constant) string literal, and we do not own it.

        In other words, whenever we make a pointer,
        we point it to the address of something that actually exists in the memory,
        but in case of line B, the string literal doesn't exist at all,
        we define it temporarily, and point to it.
        This temporary memory may be overwritten anytime.
        
        Hence, line B code is dangerous, and unpredictable.
    */

    return 0;
}