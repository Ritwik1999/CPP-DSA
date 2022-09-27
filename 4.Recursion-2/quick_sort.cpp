#include <bits/stdc++.h>
using namespace std;

void swap(vector<int>& input, int pos1, int pos2) {
    int temp = input[pos1];
    input[pos1] = input[pos2];
    input[pos2] = temp;

    return;
}

int partition(vector<int>& input, int start, int end) {
    // choose a pivot
    int pivot = input[end];

    // variable to track elements smaller than pivot
    int lt_pivot_index = start-1;

    // loop through the array segment
    for (int i = start; i <= end-1; i++) {
        // if the current element is greater than pivot
        // ignore it
        if (input[i] > pivot) {
            continue;
        }

        // input[i] is an element <= pivot
        lt_pivot_index++;
        
        // swap elements at indices lt_pivot_index and i
        swap(input, lt_pivot_index, i);
    }

    // the correct index of pivot is
    int pivot_index = lt_pivot_index + 1;

    // swap elements at lt_pivot_index and end
    swap(input, pivot_index, end);

    // return the pivot's index
    return pivot_index;
}

void quicksort(vector<int>& input, int start, int end) {
    if (start >= end) {
        return;
    }

    int partition_index = partition(input, start, end);

    quicksort(input, 0, partition_index-1);
    quicksort(input, partition_index+1, end);

    return;
}

void quicksort(vector<int>& input) {
    int size = input.size();
    quicksort(input, 0, size-1);

    return;
}

int main() {
    int n, ele;
    cin >> n;

    vector<int> input;

    for (int i = 0; i < n; i++) {
        cin >> ele;
        input.push_back(ele);
    }

    quicksort(input);

    for (int num : input) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}