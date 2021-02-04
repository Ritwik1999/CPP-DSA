/*
    The #define is a preprocessor directive,
    meaning it's effect kicks in before the program is even compiled.

    We can use #define to "replace" a certain identifier with some value,
    just before compiling is started.

    This not only prevents accidental errors in the identifer's value, 
    but also saves us some memory.
*/

#include <iostream>
using namespace std;

#define PI 3.14

int main()
{
    double radius;
    cin >> radius;

    cout << PI * radius * radius << endl;

    return 0;
}

/*
    NOTE: Again, keep in mind that #define just replaces occurences of identifers
    with the value defined, there are no evaluations, of any kind, done.

    JUST REPLACED.
*/