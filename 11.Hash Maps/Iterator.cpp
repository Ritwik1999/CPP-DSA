#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {

    // Iterators are essentially pointers for STL classes that are used to iterate over the elements in an STL class object

    unordered_map<string, int> ourmap;
    ourmap["abc"] = 1;
    ourmap["abc1"] = 2;
    ourmap["abc2"] = 3;
    ourmap["abc3"] = 4;
    ourmap["abc4"] = 5;
    ourmap["abc5"] = 6;

    // Iterator would iterate over the map elements in a random order as it is an unordered map
    // Declare an interator and make it point towards the beginning of the map
    unordered_map<string, int>::iterator it = ourmap.begin();

    while (it != ourmap.end()) {
        // maps uses pair to store key-value pairs, hence the -> is used
        cout << "Key: " << it->first <<" Value: " << it->second << endl;
        it++;   // Points to the next element, irrespective of the size of each map element
    }

    // find function also returns an iterator
    unordered_map<string, int>::iterator it1 = ourmap.find("abc");
    cout << "Find 1 result: " << it1->first << endl;

    // NOTE: it.end() does not point to the last element of the map, it points to after the last element of the map

    // Iterator over vectors
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int>::iterator it2 = v.begin();

    // Here, the iterator would iterate in the order elements were inserted in
    while (it2 != v.end()) {
        cout << *it2 << endl;
        it1++;
    }

    return 0;
}