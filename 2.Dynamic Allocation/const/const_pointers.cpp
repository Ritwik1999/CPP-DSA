/*
    int const * p => pointer to const int
    int * const p => const pointer to int

    In the first case, (*p)++ is not possible.
    In the second case, reassigning p is not possible

    There is also...
    int const * const p => p is a const pointer to a const int
*/

#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    int j = 20;

    int const * p = &i;
    (*p)++;
    p = &j;

    int * const p2 = &i;
    (*p2)++;
    p2 = &j;

    int const * const p3 = &i;
    (*p3)++;
    p3 = &j;

    return 0;
}