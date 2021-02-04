/*
    NOTE: An argument can have default values iff either it is the
    rightmost, or all arguments to its right have default values.
*/

#include <iostream>
using namespace std;

int sum(int a[], int size, int si = 0)// "si" has a default value, so it is a default argument
{
    int ans = 0;
    for (int i = si; i < size; i++)
    {
        ans += a[i];
    }
    return ans;
}

int sum2(int a, int b, int c = 0, int d = 0)
{
    return a + b + c + d;
}

int main()
{
    int arr[20];

    for (int i = 0; i < 20; i++)
    {
        arr[i] = i + 2;
    }

    cout << sum(arr, 20) << endl;       // Sum of all elements
    cout << sum(arr, 20, 3) << endl;    // Sum of all but first three elements

    cout << sum2(1, 2, 3, 4) << endl;
    cout << sum2(1, 2, 3) << endl;
    cout << sum2(1, 2) << endl;
    return 0;
}