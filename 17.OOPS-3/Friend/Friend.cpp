/*
    A function that is a friend to a class can access all of it's data members, and member functions

    NOTE:
    As friend functions are not a part of the class, "this" pointer has no meaning within their body
    Access modifiers do not affect the accessibility of friend functions, they can be declared anywhere in the class
*/

#include <iostream>
using namespace std;

class Bus
{
public:
    void print();   // friend functions have to be defined outside the class
};

void test();

class Truck
{
private:
    int x;

protected:
    int y;

public:
    int z;

    friend void Bus::print();   // if the Bus class was not defined above this class, compiler would have thrown an error

    friend void test();

    /*
        friend class Bus;

        The line above would enable all the member functions of class Bus to access all members of class Truck.
        
        NOTE: This relationship is not two-way. Truck's member functions cannot access private/protected members of Bus unless Bus makes Truck it's friend too.
    */
};

void Bus::print() {
    Truck t;
    t.x = 10;
    t.y = 20;
    cout << t.x << " " << t.y << endl;
}

void test() {
    // Access truck's private members
    Truck t;
    t.x = 11;
    t.y = 21;
    cout << t.x << " " << t.y << endl;
}

int main()
{
    Bus b;
    b.print();
    test();

    return 0;
}