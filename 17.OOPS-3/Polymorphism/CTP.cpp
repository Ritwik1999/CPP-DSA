// Compile time polymorphism

#include <iostream>
using namespace std;
#include "Vehicle.cpp"
#include "Car.cpp"

int test(int a, int b)
{
    return a - b;
}

int test(int a)
{
    return a + 1;
}

int test()
{
    return 0;
}

// The compiler cannot differentiate solely on the basis of the return type
// void test() {

// }

int main()
{
    // Operator Overloading (multiple behaviours for the + operator)
    cout << 2 + 3 << endl;
    cout << 2.0 + 3.0 << endl;
    cout << 'a' + 'b' << endl;

    // Method Overriding
    Vehicle v;
    Car c;

    v.print(); // "Vehicle"; decided at compile time
    c.print(); // "Car"; decided at compile time

    Vehicle *v1 = new Vehicle();
    v1->print(); // "Vehicle"; decided at compile time

    // A base class pointer can point to a derived class object (vice-versa not possible), but this pointer can only access the members that belong to the base class
    Vehicle *v2 = &c;
    v2->print(); // "Vehicle"; decided at compile time

    return 0;
}