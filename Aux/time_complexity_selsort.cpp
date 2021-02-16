/*
    Selection sort works by iteratively selecting the minimum element in the array
    and place it in the beginning
*/

#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

long getTimeinMicroSeconds()
{
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

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
    int* arr = 0;

    for (int n = 10; n <= 1000000; n *= 10)
    {
        arr = new int[n];
        long starttime, endtime;

        for (int i = 0; i < n; i++)
        {
            arr[i] = n - i;
        }

        starttime = getTimeinMicroSeconds();
        SelSort(arr, n);
        endtime = getTimeinMicroSeconds();

        cout << "Selection Sort n = " << n << " time = " << endtime - starttime << endl;
    }

    delete [] arr;
    return 0;
}