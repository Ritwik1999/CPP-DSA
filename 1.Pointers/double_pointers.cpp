#include <iostream>
using namespace std;

//Will not alter main() copy
void increment1(int** p)
{
    p = p + 1;
}

//Will alter main() copy
void increment2(int** p)
{
    *p = *p + 1;
}

//Will alter main() copy
void increment3(int** p)
{
    **p = **p + 1;
}

int main()
{
    int i = 10;
    int *p = &i;
    int **p2 = &p;

    cout << p2 << endl;
    cout << &p << endl;

    cout << p << endl;
    cout << *p2 << endl;
    cout << &i << endl;

    cout << **p2 << endl;
    cout << *p << endl;
    cout << i << endl;

    return 0;
}