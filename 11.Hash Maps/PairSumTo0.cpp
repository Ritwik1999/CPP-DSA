// Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
// Note: Array A can contain duplicate elements as well.

#include <iostream>
#include <unordered_map>

using namespace std;

int pairSum(int *arr, int n)
{
    unordered_map<int, int> freq;
    int pairs = 0;

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        int negativeEle = (-1) * arr[i];

        if (freq.count(negativeEle) > 0)
        {
            if (arr[i] != 0)
            {
                pairs += (freq[arr[i]] * freq[negativeEle]);
                freq.erase(arr[i]);
                freq.erase(negativeEle);
            }
            else
            {
                int zeroCount = freq[0];
                pairs += (zeroCount * (zeroCount - 1)) / 2;
                freq.erase(0);
            }
        }
    }

    return pairs;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}