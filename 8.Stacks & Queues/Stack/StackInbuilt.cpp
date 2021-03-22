#include <iostream>
#include<stack>
using namespace std;

#include "StackReverse.cpp"

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

    stack<int> extra;
    reverseStack(s, extra);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

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

    return 0;
}
