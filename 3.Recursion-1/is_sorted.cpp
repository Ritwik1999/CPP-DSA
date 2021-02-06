/*
    Recursively check if an array is sorted:

    Algo:
    1. Check for base case (i.e., if size is 0 or 1, return true).
    2. Check if rest of the array is sorted (recursive calls).
    3. Compare the first two elements and return if they are sorted or not. (the computation part)
*/

#include <iostream>
using namespace std;

bool is_sorted(int a[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }

    bool isSmallerSorted = is_sorted(a+1, size-1);

    return isSmallerSorted && (a[0] < a[1]);
}

int main()
{
    int a1[6] = {1, 2, 3, 4, 5, 6};
    int a2[5] = {10, 23, 32, 8, 2};

    cout << is_sorted(a1, 6) << endl;
    cout << is_sorted(a2, 5) << endl;

    return 0;
}