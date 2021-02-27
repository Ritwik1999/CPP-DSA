#include <iostream>
using namespace std;

#include "Fraction.cpp"

int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    f1.print();
    f2.print();

    Fraction f3 = f1 + f2;
    f3.print();

    Fraction f4 = f1 * f2;
    f4.print();

    Fraction f5(50, 10);

    if (f1 == f5)
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;

    if (f1 == f2)
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;

    cout << "----------Unary Operator Overloading----------" << endl;

    f1.setNumerator(10);
    f1.setDenominator(2);
    
    ++(++f1);
    f1.print();

    return 0;
}
