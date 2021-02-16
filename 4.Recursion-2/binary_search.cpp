/*
    Given an integer sorted array (sorted in increasing order)
    and an element x, find the x in given array using binary search.
    Return the index of x.

    Return -1 if x is not present in the given array.
*/

#include <iostream>
using namespace std;

int execBinarySearch(int input[], int si, int ei, int x)
{
    // Base Case
    if (si > ei)
    {
        return -1;
    }
    
    // Computation
    int mid = (si+ei)/2;
    
    if (input[mid] == x)
    {
        return mid;
    }
    
    // Recursion
    if (input[mid] > x)
    {
        return execBinarySearch(input, si, mid-1, x);
    }
    
    else
    {
        return execBinarySearch(input, mid+1, ei, x);
    }
}

// input - input array
// size - length of input array
// element - value to be searched
int binarySearch(int input[], int size, int element) {

    return execBinarySearch(input, 0, size-1, element);
}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}