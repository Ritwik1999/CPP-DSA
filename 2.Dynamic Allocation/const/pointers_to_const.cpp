/*
    Pointers declared in the usual way that point to a const qualified data
    do not work. 
    (because then we'd have a path that is not "read-only" to "const" data)

    Pointers, when qualify as const can point to const data.

    You can, however, assign a const pointer to normal data
*/

#include <iostream>
using namespace std;

int main()
{
    int const i = 10;
    // int* p = &i; // cannot allow modifying the value of i
    // int * const p = &i;  // cannot allow modifying the value of i
    int const *p = &i;

    int j = 25;
    int const *p2 = &j;
    // (*p2)++;    // p2 has read only access
    cout << *p2 << endl;
    j++;
    cout << *p2 << endl;

    return 0;
}