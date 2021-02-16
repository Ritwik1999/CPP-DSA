/*
    Selection sort works by iteratively selecting the minimum element in the array
    and place it in the beginning
*/

#include <bits/stdc++.h>
using namespace std;

void SelSort(int input[], int n)
{
    int sorted_so_far = 0;

    for (int i = 0; i < n; i++)
    {
        int minele = INT_MAX, minele_pos = -1;
        for (int j = sorted_so_far; j < n; j++)
        {
            if (input[j] < minele)
            {
                minele = input[j];
                minele_pos = j;
            }
        }

        if (minele_pos != -1)
        {
            int temp = input[sorted_so_far];
            input[sorted_so_far] = input[minele_pos];
            input[minele_pos] = temp;
            sorted_so_far++; 
        }
    }

    return;
}

int main()
{
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    SelSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    delete [] arr;

    return 0;
}