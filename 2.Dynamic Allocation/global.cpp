/*
    WARNING: The use of global variables is discouraged. Do not use it
*/

#include <iostream>
using namespace std;

int a; // global variable, can be accessed from amnywhere in this file.

void g()
{
    a++;
    cout << a << endl;
}

void f()
{
    a++;
    cout << a << endl;
    g();
}

int main()
{
    a = 10;
    f();
    cout << a << endl;

    return 0;
}