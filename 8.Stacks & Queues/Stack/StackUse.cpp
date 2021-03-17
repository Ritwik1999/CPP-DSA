#include <iostream>
using namespace std;

#include "StackUsingArray.h"

// Inbuilt Stack
#include<stack>

int main()
{
    // Inbuilt Stack
    // NOTE: Inbuilt stack pop function doesn't return the deleted element, and isEmpty is called empty

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.size() << endl;
    cout << s.empty() << endl;

    // User defined stack
    /*
    StackUsingArray<char> s;
    s.push(100);    // Will be treated as ASCII because stack type is char, hence values accepted are 0 to 127
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
    */

    return 0;
}
