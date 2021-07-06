// You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
// If two or more elements contend for the maximum frequency, return the element which occurs in the array first.

#include <iostream>
#include <unordered_map>
using namespace std;

int highestFrequency(int arr[], int n)
{
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    int max_count = 0, ele;

    for (int i = 0; i < n; i++)
    {
        if (freq[arr[i]] > max_count)
        {
            max_count = freq[arr[i]];
            ele = arr[i];
        }
    }

    return ele;
}

// Sample input:
// 13
// 2 12 2 11 12 2 1 2 2 11 12 2 6

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}