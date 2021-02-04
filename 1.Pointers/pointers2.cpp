#include <iostream>
using namespace std;

int main()
{
    int i;
    cout << i << endl;

    i++;
    cout << i << endl;

    int *p;
    cout << p << endl;

    // Dangerous
    cout << *p << endl;

    //Even more dangerous
    (*p)++;
    cout << *p << endl;

    //Safe way; never leave pointers unintialised
    int *p2 = 0; // means int * p = 0x0;

    *p2 = 10;
    cout << *p2 << endl; // You cannot modify, in any way, pointers initialiased as int * p = 0;

    return 0;
}
