/*
    Inline functions can be used to improve the readability and performance
    of the program.

    During compile time, all places where the (inline) function is called, 
    the compiler replaces it with the function body.

    NOTE: Generally, replacement occurs only if the function is short
    (max 3 lines). If it is big, the compiler does not replace it.
*/

#include <iostream>
using namespace std;

inline int max(int a, int b)
{
    return (a>b) ? a : b;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int c = max(a, b);

    cout << c << endl;

    return 0;
}
