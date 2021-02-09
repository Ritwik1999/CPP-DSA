/*
    Merge Sort:
    Keep dividing the array into two halves and call the merge sort function upon them.
    Finally, merge both of them.
*/


#include <iostream>
using namespace std;

void Merge2SortedArrays(int input[], int si, int ei)
{
    int size = ei-si+1;
    int mid = (si+ei)/2;
    
    int* temp_arr = new int[size];
    int i = si, j = mid+1, k = 0;
    
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
    
    delete [] temp_arr;
    
    return;
}

void execMergeSort(int input[], int si, int ei)
{
    // Base Case
    if (si >= ei)
    {
        return;
    }
    
    // Recursion
    int mid = (si+ei)/2;
    execMergeSort(input, si, mid);
    execMergeSort(input, mid+1, ei);
    
    // Computation
    Merge2SortedArrays(input, si, ei);
    
    return;
}

void mergeSort(int input[], int size){    
    execMergeSort(input, 0, size-1);
}

int main()
{
    int length;
    cin >> length;
    int *input = new int[length];
    for (int i = 0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }

    cout << endl;
    return 0;
}