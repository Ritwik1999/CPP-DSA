#include <iostream>
using namespace std;

bool checkNumber(int input[], int size, int x)
{
    if (size < 1)
    {
        return false;
    }

    if (input[0] == x)
    {
        return true;
    }

    bool foundInSmaller = checkNumber(input + 1, size - 1, x);

    return ((input[0] == x) || foundInSmaller);
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int x;

    cin >> x;

    if (checkNumber(input, n, x))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    
    return 0;
}