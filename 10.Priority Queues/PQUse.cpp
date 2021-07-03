// Heap Sort Complexities:
// Time: nlog(n) + nlog(n) => O(nlog(n))
// Space: To store the heap as an array => O(n)

#include <iostream>
using namespace std;

#include "MinPQ.h"
#include "MaxPQ.h"

int main()
{
    MinPriorityQueue p;

    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout << p.getSize() << endl;
    cout << p.getMin() << endl;

    // Heap Sort
    while (!p.isEmpty())
        cout << p.removeMin() << " ";

    cout << endl;
}