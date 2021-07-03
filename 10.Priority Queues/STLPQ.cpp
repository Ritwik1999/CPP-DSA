// inbuilt Priority Queue is included in the queue header file as part of c++ stl
// default is a max pq

#include <iostream>
#include <queue>

using namespace std;

int main() {
    // for a max pq
    priority_queue<int> pq;

    // for a min pq
    priority_queue<int, vector<int>, greater<int>> pq;

    // insert ---> push
    pq.push(16);
    pq.push(1);
    pq.push(167);
    pq.push(7);
    pq.push(45);
    pq.push(32);

    // getSize ---> size
    cout << "Size : " << pq.size() << endl;

    // getMax ---> top
    cout << "Top : " << pq.top() << endl;

    // isEmpty ---> empty
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << endl;
}