// Vectors are inbuilt dynmic arrays, i.e., size need not be explicitly mentioned, expands automatically to accomodate newer elements

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // vector<int> *vp = new vector<int>();    // Dynamically allocated
    vector<int> v; // Statically allocated

    for (int i = 0; i < 100; i++)
    {
        cout << "Capacity: " << v.capacity() << "\tSize: " << v.size() << endl;
        v.push_back(i + 1);
    }

    cout << "----------------------" << endl;

    v.push_back(10);
    v.push_back(20); // 20 follows 10
    v.push_back(30); // 30 follows 20

    v[1] = 100;

    // Do not use [] for inserting elements
    v[3] = 1002;
    v[4] = 1234; // This won't increase the size, hence we use push_back.

    v.push_back(23);
    v.push_back(234);

    // Use [] only for get and updating a pushed_back element
    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;
    cout << v[4] << endl;

    cout << "----------------------" << endl;
    cout << "Size: " << v.size() << endl;

    // alter to get [], it also checks if index is less than size. Hence, at(index) is much safer to access elements
    cout << v.at(2) << endl;
    // cout << v.at(6) << endl;

    v.pop_back(); // removes the last element
    cout << "Size: " << v.size() << endl;

    return 0;
}