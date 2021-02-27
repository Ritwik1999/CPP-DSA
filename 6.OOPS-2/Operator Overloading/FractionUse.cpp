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

    cout << "Pre increment" << endl;

    f1.setNumerator(10);
    f1.setDenominator(2);

    ++(++f1);
    f1.print();

    Fraction f6 = ++(++f1);
    f1.print();
    f6.print();

    cout << "Post increment" << endl;

    // NOTE: Post increment operator cannot be chained

    f1.setNumerator(10);
    f1.setDenominator(2);

    Fraction f7 = f1++;
    f1.print();
    f7.print();

    cout << "+= operator" << endl;

    f1.setNumerator(10);
    f1.setDenominator(3);

    f2.setNumerator(5);
    f2.setDenominator(2);

    (f1 += f2) += f2;
    f1.print();
    f2.print();

    return 0;
}
