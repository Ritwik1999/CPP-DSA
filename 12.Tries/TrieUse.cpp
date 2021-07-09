#include <iostream>
using namespace std;
#include "Trie.h"

int main()
{
    Trie t; // or Trie t(); invokes the constructor
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");

    cout << t.search("and") << endl;
    t.removeWord("and");
    cout << t.search("and") << endl;

    return 0;
}