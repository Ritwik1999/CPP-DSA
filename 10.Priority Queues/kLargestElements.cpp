// The best time complexity that can be achieved by the commonly used sorting algorithms is O(nlog(n))
// A k-sorted array tries to improve it further by placing a restriction on the array
// In a k-sorted array, any element is either k-1 left, or k-1 right positions away from its sorted place.

// Given an unsorted k-array, and the value of k, construct a (k-)sorted array from it
#include <iostream>
#include <queue>

using namespace std;

// We use a priority queue of size k; At every pass, pop an element (which will be the greatest in case of a max pq), put it at the ith position in the input array, and push the (i+1)th element of the array into the pq
void kSortedArray(int input[], int n, int k)
{
    // Complexity: klog(k) (size of pq = k)
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(input[i]);
    }

    // Complexity: (n-k)log(k) (n-k pop function calls)
    int j = 0;
    for (int i = k; i < n; i++)
    {
        // we don't have to worry about the jth element as it is already inserted in pq
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }

    // Last k elements are still in the pq => Last k elements in the array are not sorted
    // Complexity: klog(k) (k pop function calls)
    while (!pq.empty())
    {
        input[j] = pq.top();
        pq.pop();
        j++;
    }
}
// Overall complexity: (k+(n-k)+k)log(k) = (n+k)log(k)
// Assuming k << n, (n + k) becomes k
// If k is small, log(k) is even smaller
// Hence, the overall complexity becomes O(n)

int main()
{
    int input[] = {10, 12, 6, 7, 9};
    int k = 3;
    kSortedArray(input, 5, k);
    for (int i = 0; i < 5; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;

    return 0;
}