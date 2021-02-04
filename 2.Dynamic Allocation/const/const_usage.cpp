/*
    The usage of const pointers and const references is that you can pass 
    values being sure of it that those cannot be changed, by passing a 
    "read-only" const to those functions.
*/

#include <iostream>
using namespace std;

void g (int const & a) {
    a++;
}

void f (int const * p) {
    (*p)++;
}

int main()
{
    int j = 10;
    int *p = &j;

    f(p);
    g(j);

    return 0;
}