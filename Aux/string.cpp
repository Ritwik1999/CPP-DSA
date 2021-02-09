// Compare string functions and behaviour with char[]

#include <iostream>
using namespace std;

int main()
{

    string *sp = new string;
    *sp = "def";
    cout << sp << endl; // char[] behaves differently
    cout << *sp << endl;

    string s = "abc"; // Not possible with char[]
    getline(cin, s);
    cout << s << endl;

    s = "defdef"; // Type string can be treated just like a char array
    cout << s[0] << endl;
    s[0] = 'a';
    string s1;
    s1 = "def";

    string s2 = s + s1; // Concat; not possible with char[]
    cout << s2 << endl;

    s += s1;

    cout << s1 << endl;
    cout << s << endl;

    cout << s.size() << endl; // Helper fns...
    cout << s.substr(3) << endl;
    cout << s.substr(3, 3) << endl;

    cout << s.find("def") << endl;
}