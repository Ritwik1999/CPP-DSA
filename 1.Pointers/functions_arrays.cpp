#include <iostream>
using namespace std;

// Alter the below line as int sum(int a[], int size){...}, to test (1)
int sum(int *a, int size)
{
    // cout << sizeof(a) << endl;
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans += a[i];
    }
    return ans;
}

int main()
{
    /*
        When you pass an array as an argument, it is effectively passed
        as a pointer. This can be proved by sizeof.         ...(1)
        This also has an interesting application in that you can also pass 
        a subset of the array.
    */

    int a[10] = {23, 12, 23, 5, 4, 3, 254, 76, 56, 87};
    cout << sizeof(a) << endl;

    cout << sum(a, 10) << endl;
    cout << sum(a+3, 7) << endl;
    cout << sum(a+5, 5) << endl;
    cout << sum(a+7, 3) << endl;
    return 0;
}