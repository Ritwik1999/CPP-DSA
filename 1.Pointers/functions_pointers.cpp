#include <iostream>
using namespace std;

void print(int *p)
{
    cout << *p << endl;
}

void IncrementPointer(int *p)
{
    p = p + 1;
}

void Increment(int *p)
{
    (*p)++;
}

int main()
{
    int i = 10;
    int *p = &i;

    print(p);

    cout << p << endl;
    IncrementPointer(p);
    cout << p << endl;

    /*
        The output is same before and after invoking IncrementPointer because
        the pointer is passed by value.
    */

    cout << *p << endl;
    Increment(p);
    cout << *p << endl;

    /*
        In this case, the changes are reflected because we pass (by value),
        the address of a location, so any changes made, irrespective of the context,
        will affect the contents of that address.
    */

    return 0;
}