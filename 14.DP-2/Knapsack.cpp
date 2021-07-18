/*
A thief robbing a store can carry a maximal weight of W into his knapsack.
There are N items, and i-th item weigh 'Wi' and the value being 'Vi.'
What would be the maximum value V, that the thief can steal?
*/

/*
Input format:
N
Weights array
Values array
maximal weight
*/

#include <iostream>
using namespace std;

int knapsack(int *weights, int *values, int n, int maxWeight)
{
    // Base Case
    if (n == 0 || maxWeight == 0) {
        return 0;
    }

    if (weights[0] > maxWeight) {
        return knapsack(weights+1, values+1, n-1, maxWeight);
    }

    // Recursive call
    int including = knapsack(weights+1, values+1, n-1, maxWeight - weights[0]) + values[0];
    int excluding = knapsack(weights+1, values+1, n-1, maxWeight);

    return max(including, excluding);

}

/*
Sample Input:
5
5 1 8 9 2
4 10 2 3 1
15
*/
int main()
{
    int n;
    cin >> n;

    int *weights = new int[n];
    int *values = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    int maxWeight;
    cin >> maxWeight;

    cout << knapsack(weights, values, n, maxWeight) << endl;

    delete[] weights;
    delete[] values;
}