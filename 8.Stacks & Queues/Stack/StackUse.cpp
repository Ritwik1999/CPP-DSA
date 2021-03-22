#include <iostream>
using namespace std;

#include "StackUsingArray.h"

int main()
{

    // User defined stack
    StackUsingArray<char> s;
    s.push(100); // Will be treated as ASCII because stack type is char, hence values accepted are 0 to 127
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);

    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.size() << endl;

    cout << s.isEmpty() << endl;

    return 0;
}