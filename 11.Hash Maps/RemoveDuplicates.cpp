// Given an array of integers, return a vector of integers that contains the elements of the array, but with duplicate occurences of elements ignored, in the same order as they appear in the array

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> removeDuplicates(int *a, int size)
{
    vector<int> output;
    unordered_map<int, bool> seen;

    for (int i = 0; i < size; i++) {
        if (seen.count(a[i]) == 0) {
            seen[a[i]] = true;
            output.push_back(a[i]);
        }
    }

    return output;
}

int main()
{
    int a[] = {1, 2, 3, 3, 2, 1, 4, 3, 6, 5, 5};
    vector<int> output = removeDuplicates(a, 11);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    cout << endl;
    
    return 0;
}
