#include <sys/time.h>
#include <iostream>
using namespace std;

long getTimeinMicroSeconds()
{
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

void Merge2SortedArrays(int input[], int si, int ei)
{
    int size = ei - si + 1;
    int mid = (si + ei) / 2;

    int *temp_arr = new int[size];
    int i = si, j = mid + 1, k = 0;

    while (i <= mid && j <= ei)
    {
        if (input[i] < input[j])
        {
            temp_arr[k++] = input[i];
            i++;
        }

        else
        {
            temp_arr[k++] = input[j];
            j++;
        }
    }

    if (i <= mid)
    {
        while (i <= mid)
        {
            temp_arr[k++] = input[i];
            i++;
        }
    }

    else
    {
        while (j <= ei)
        {
            temp_arr[k++] = input[j];
            j++;
        }
    }

    for (i = si, k = 0; i <= ei; i++)
    {
        input[i] = temp_arr[k];
        k++;
    }

    delete[] temp_arr;

    return;
}

void mergesort(int input[], int si, int ei)
{
    // Base Case
    if (si >= ei)
    {
        return;
    }

    // Recursion
    int mid = (si + ei) / 2;
    mergesort(input, si, mid);
    mergesort(input, mid + 1, ei);

    // Computation
    Merge2SortedArrays(input, si, ei);

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
        mergesort(arr, 0, n-1);
        endtime = getTimeinMicroSeconds();

        cout << "Merge Sort n = " << n << " time = " << endtime - starttime << endl;
    }

    delete [] arr;
    return 0;
}

