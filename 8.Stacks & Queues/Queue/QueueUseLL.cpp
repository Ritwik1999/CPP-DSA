#include <iostream>
using namespace std;

#include "QueueUsingLL.h"

int main()
{
    QueueUsingLL<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;

    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);

    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;

    return 0;
}