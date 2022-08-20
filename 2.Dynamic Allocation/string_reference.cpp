#include <bits/stdc++.h>
using namespace std;

int main() {
    // Debug this program
    string a = "abcd";
    string &b = a;

    b[0] = '1';

    cout << b << " " << a << endl;
    return 0;
}