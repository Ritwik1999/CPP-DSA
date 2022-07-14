#include <iostream>
using namespace std;

int main()
{
    int* p = 0;
    cout << p << endl;
    cout << *p << endl; // Segmentation fault (runtime error)
    return 0;
}