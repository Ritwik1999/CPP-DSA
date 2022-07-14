#include <iostream>
using namespace std;

int main()
{
    int a[5] = {23, 34, 45, 31, 80};

    cout << a << endl;
    cout << &a[0] << endl; // i.e., a == &a[0]

    cout << *(a + 2) << endl;
    cout << a[2] << endl;

    cout << a[3] << endl;
    cout << 3 [a] << endl; // this is because a[i] and i[a] both expand to *(a+i)

    // Differences between an array and a pointer
    int *ptr = 0;
    cout << "Size of ptr: " << sizeof(ptr) << endl;
    cout << "Size of a: " << sizeof(a) << endl;

    int *p = &a[0];
    cout << p << endl;
    cout << &p << endl;
    cout << a << endl;
    cout << &a << endl; // i.e., a == &a[0] == &a (!!!)

    p = &a[2];
    /*
    Both of the below operations (and their variants) are not allowed
    a = a+1;
    a++;            
    */

    /*
        The main reason for all these diiferences is because
        when you declare a pointer, it gets stored at a physical location
        in the memory and is recorded in the symbol table,
        unlike when you declare an array, in which it's identifier,
        though similar to a pointer,
        is not allocated pointer-like dedicated storage,
        it is just written in the (immutable) symbol table. 
    */

    return 0;
}
