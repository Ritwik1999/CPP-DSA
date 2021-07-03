#include <iostream>

using namespace std;

// implement heap sort in O(1) space complexity. Sort in descending order
void heapSort(int arr[], int n)
{
    // convert array to heap
    int i = 1;

    while (i < n)
    {
        // up-heapify
        int childIndex = i, parentIndex;

        while (childIndex > 0)
        {
            parentIndex = (childIndex - 1) / 2;

            if (arr[childIndex] < arr[parentIndex])
            {
                int temp = arr[childIndex];
                arr[childIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
                childIndex = parentIndex;
            }
            else
            {
                break;
            }
        }

        i++;
    }

    // perform removeMin n times
    i = n - 1;

    while (i > 0)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;

        i--;

        // down-heapify
        int parentIndex = 0, leftChildIndex = (2 * parentIndex) + 1, rightChildIndex = leftChildIndex + 1, minIndex = parentIndex;

        while (leftChildIndex <= i)
        {
            if (arr[leftChildIndex] < arr[minIndex])
                minIndex = leftChildIndex;

            if (rightChildIndex <= i && (arr[rightChildIndex] < arr[minIndex]))
                minIndex = rightChildIndex;

            if (minIndex == parentIndex)
            {
                break;
            }

            int temp = arr[parentIndex];
            arr[parentIndex] = arr[minIndex];
            arr[minIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = (2 * parentIndex) + 1;
            rightChildIndex = leftChildIndex + 1;
        }
    }
}

int main()
{
    int size;
    cin >> size;
    int *input = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    heapSort(input, size);

    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;

    return 0;
}