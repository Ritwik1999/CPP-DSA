#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    // unordered_map<typeof key, typeof value>
    unordered_map<string, int> ourMap;

    // insert
    pair<string, int> p("abc", 1);
    ourMap.insert(p);
    ourMap["def"] = 2;

    // size of the map
    cout << "Size: " << ourMap.size() << endl;

    // access
    cout << ourMap["abc"] << endl;
    cout << ourMap.at("abc") << endl;
    // cout << ourMap.at("ghi") << endl; // key not found error
    cout << ourMap["ghi"] << endl; // no error, rather inserts the key and value (default value based on the data type) and fetches the value

    cout << "Size: " << ourMap.size() << endl;

    // find if a key is present or not
    if (ourMap.count("ghi") > 0)
    {
        // count function returns either a zero or one, as one key occurs at most once in a map
        cout << "ghi is present" << endl;
    }
    else
    {
        cout << "ghi is not present" << endl;
    }

    // erase an element
    ourMap.erase("ghi");
    if (ourMap.count("ghi") > 0)
    {
        // count function returns either a zero or one, as one key occurs at most once in a map
        cout << "ghi is present" << endl;
    }
    else
    {
        cout << "ghi is not present" << endl;
    }

    cout << "Size: " << ourMap.size() << endl;

    return 0;
}