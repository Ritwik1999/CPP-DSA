/*
    Given an integer array (of length n),
    find and print all the subsets of input array.
*/

#include <iostream>
using namespace std;

void printSubsets(int input[], int input_size, int output[], int output_size)
{
    // Base Case and computation
    if (input_size == 0)
    {
        if (output_size == 0)
        {
            cout << "Subset with no elements" << endl;
            return;
        }

        else
        {
            for (int i = 0; i < output_size; i++)
            {
                cout << output[i] << " ";
            }
            cout << endl;
            return;
        }
    }

    // Recursion
    printSubsets(input + 1, input_size - 1, output, output_size);

    output[output_size++] = input[0];

    printSubsets(input + 1, input_size - 1, output, output_size);

    return;
}

void printSubsetsOfArray(int input[], int size)
{
    int *output = new int[size];
    int output_size = 0;

    printSubsets(input, size, output, output_size);

    delete[] output;

    return;
}

int main()
{
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    printSubsetsOfArray(input, length);
}
