#include <iostream>
using namespace std;

int main()
{
    char StringLiteral[] = "Ritzy 123";
    char *StringPointer = "Ritzy 123";

    /*
        Line 7 would raise a warning, discouraging it's use.
        This is because in line 6, we own the contents of the array,
        and hence we can modify it, but in Line 7, it is just a pointer to a 
        (constant) string literal, we do not own it.

        In other words, whenever we make a pointer,
        we point it to the address of something that actually exists in the memory,
        but in case of line 7, the string literal doesn't exist at all,
        we define it temporarily, and point towards it.
        This temporary memory may be overwritten anytime.
        
        Hence, line 7 code is dangerous, and unpredictable.
    */

    return 0;
}