#include <iostream>
using namespace std;

void increment_no_ref(int n)
{
    n++;
}

void increment_ref(int &n)
{
    n++;
}

// Bad practice
int &ret_ref()
{
    int a = 10;
    return a;
}

//Bad practice
int *ret_ptr()
{
    int a = 10;
    return &a;
}

int main()
{
    // Variables i1 and j1 are stored in different locations; they are independent of each other
    int i1 = 10;
    int j1 = i1;

    i1++;
    cout << j1 << endl;

    // Variables i and j point to the same location, i.e., they are aliases for the same location
    int i = 10;
    int &j = i;

    i++;
    cout << j << endl;
    j++;
    cout << i << endl;

    int k = 100;
    j = k; // Only while declaration j remains an alias, i.e., it is not an alias for k.
    cout << i << endl;

    // A reference variable has to be initialised

    // One use of refernce vars is "pass by reference"
    i = 10;
    increment_no_ref(i);
    cout << i << endl;

    int t = 15;
    increment_ref(t);
    cout << t << endl;

    /*
        About the bad practice functions...
        Both ret_ref and ret_ptr use a local variable 'a', and
        return either its alias or address.

        It should be avoided because once these functions return,
        the memory used by 'a' is free, and thus its value can be replaced.

        If that happens, we'd get access to a memory which we cannot control.
        (because the scope of 'a' is only inside ret_ref and ret_ptr)
    */

    int& ref_var = ret_ref();
    int* ptr_var = ret_ptr();

    cout << ref_var << endl;
    cout << *ptr_var << endl;

    return 0;
}