#include <iostream>

using namespace std;

#include "ourmap.h"

int main()
{
    ourmap<int> map;
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i; // Converts 5 to '5'
        string key = "abc";
        key = key + c;
        int value = i + 1;
        map.insert(key, value);
        cout << map.getLoadFactor() << endl;
    }

    cout << "Number of entries in the map: " << map.size() << endl;
    map.remove("abc2");
    map.remove("abc7");
    cout << "Number of entries in the map: " << map.size() << endl;

    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i; // Converts 5 to '5'
        string key = "abc";
        key = key + c;
        cout << key << ": " << map.getValue(key) << endl;
    }

    cout << "Number of entries in the map: " << map.size() << endl;
}