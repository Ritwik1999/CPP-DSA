#include <iostream>
using namespace std;

// Assume int is 4 bytes long; and char is a byte long.

int main()
{
    // Implicit typecasting
    int i = 65;
    char c = i;
    cout << c << endl;

    // Explicit typecasting; Implicit typecasting does not occur with pointers
    int *p = &i;
    char *pc = (char*)p;

    cout << p << endl;
    cout << pc << endl;

    // Occurs due to little endian
    // (we'd expect *(pc + 3) to print 'A', but due to little endianess, it prints null character)
    cout << *p << endl;
    cout << *pc << endl;
    cout << *(pc + 1) << endl;
    cout << *(pc + 2) << endl;
    cout << *(pc + 3) << endl;

    return 0;
}