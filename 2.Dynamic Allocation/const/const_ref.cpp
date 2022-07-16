/*
    The following code will generate error(s)

    i = 10;

    const int j;
    j = 10;

    i.e., constant vars need to be initialised alongside their declaration

    NOTE: When something is declared as const, only the path to it becomes
    constant, not the storage.
*/

#include <iostream>
using namespace std;

int main()
{
    // constant int
    const int i1 = 10;
    int const i2 = 12;      // Both are one and the same

    // constant reference to non constant variable => value can be changed
    int j = 12;
    const int& k = j;

    j++;
    k++;

    cout << j << endl;
    cout << k << endl;

    // constant reference to constant variable => value cannot be changed
    const int j2 = 123;
    const int& k2 = j2;

    // reference to a constant int => value cannot be changed
    const int j3 = 123;
    int& k3 = j3;    // Not possible; trying to obtain higher level access from lower access value
    k3++;

    return 0;
}