#include <iostream>
using namespace std;

void swap(int input[], int posA, int posB)
{
    int temp = input[posA];
    input[posA] = input[posB];
    input[posB] = temp;
}

int partition(int input[], int si, int ei)
{
    int pivot = input[si], correct_pivot_index = si - 1, initial_pivot_index = si;

    for (int i = si; i <= ei; i++)
    {
        if (input[i] <= pivot)
        {
            correct_pivot_index++;
        }
    }

    swap(input, initial_pivot_index, correct_pivot_index);

    // Bring all elements less than or equal to the pivot element to it's left.
    int i = si, j = ei;
    while (i < correct_pivot_index && j > correct_pivot_index)
    {
        if (input[i] <= pivot)
        {
            i++;
        }

        else if (input[j] > pivot)
        {
            j--;
        }

        else
        {
            swap(input, i, j);
            i++;
            j--;
        }
    }

    return correct_pivot_index;
}

void execQuickSort(int input[], int si, int ei)
{
    // Base Case
    if (si >= ei)
    {
        return;
    }

    // Computation i.e. Pivot element get it's correct pos.
    int pivot_pos = partition(input, si, ei);

    // Recursion
    execQuickSort(input, si, pivot_pos - 1);
    execQuickSort(input, pivot_pos + 1, ei);

    return;
}

void quickSort(int input[], int size)
{
    execQuickSort(input, 0, size - 1);
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    quickSort(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}
