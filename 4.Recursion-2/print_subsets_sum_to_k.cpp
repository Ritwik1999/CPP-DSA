/*
    Given an array A and an integer K, print all subsets of A which sum to K.
*/

#include <iostream>
using namespace std;

void printIt(int input[], int n, int k, int buffer[], int bufferSize)
{
    // Base Case
    if (n == 0 || k == 0)
    {
        if (k == 0)
        {
            for (int i = 0; i < bufferSize; i++)
            {
                cout << buffer[i] << " ";
            }
            cout << endl;

            return;
        }

        return;
    }

    // Computation
    buffer[bufferSize] = input[0];

    // Recursion
    printIt(input + 1, n - 1, k - input[0], buffer, bufferSize + 1);
    printIt(input + 1, n - 1, k, buffer, bufferSize);

    return;
}

void printSubsetSumToK(int input[], int size, int k)
{
    int *bufferStore = new int[size];
    printIt(input, size, k, bufferStore, 0);

    delete[] bufferStore;

    return;
}

int main()
{
    int input[1000], length, k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    cin >> k;
    printSubsetSumToK(input, length, k);
}
