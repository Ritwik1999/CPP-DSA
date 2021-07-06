#include <iostream>
#include <unordered_map>

using namespace std;

void printIntersection(int arr1[], int arr2[], int n, int m)
{
    unordered_map<int, int> freq1;
    unordered_map<int, int> freq2;

    for (int i = 0; i < n; i++)
    {
        freq1[arr1[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        freq2[arr2[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (freq2.count(arr1[i]) > 0 && freq2[arr1[i]] > 0)
        {
            cout << arr1[i] << endl;
            freq1[arr1[i]]--;
            freq2[arr1[i]]--;
        }
    }

    return;
}

// Sample input:
// 4
// 2 6 1 2
// 5
// 1 2 3 4 2

int main()
{
    int n;
    cin >> n;

    int *arr1 = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int *arr2 = new int[m];

    for (int i = 0; i < m; ++i)
    {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}