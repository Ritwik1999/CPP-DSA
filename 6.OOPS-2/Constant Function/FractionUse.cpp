/*
    const objects are those that once initialised, cannot alter their data members

    Class objects that are declared const can only call functions that are also const qualified.
    This is to ensure that the called function doesn't change the value of any data member.
*/

#include <iostream>
using namespace std;

#include "Fraction.cpp"

int main()
{
    Fraction const f3(12, 13);

    cout << f3.getNumerator() << " " << f3.getDenominator() << endl;

    f3.print();

    return 0;
}
