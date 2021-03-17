#include <iostream>
using namespace std;

#include <queue>

int main()
{
    // Inbuilt queue
    /*
        enqueue is called push, same return type
        front is called front, same return type
        dequeue is called pop, return type void
        getSize is called size, same return type
        isEmpty is called empty, same return type
    */

    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    cout << q.size() << endl;
    cout << q.empty() << endl;

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}