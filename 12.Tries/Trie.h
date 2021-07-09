#include <string>
#include "TrieNode.h"

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0'); // root stores \0 as data
    }

    bool insertWord(TrieNode *root, string word)
    {
        // Base Case
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // Computation
        int index = word[0] - 'a'; // Gives the index for any alphabet in the children array
        TrieNode *child;
        if (root->children[index] != nullptr)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
       insertWord(child, word.substr(1));
    }

    bool search(TrieNode *root, string word)
    {
        // Base Case
        if (word.size() == 0)
        {
            return root->isTerminal;
        }

        // Computation
        int index = word[0] - 'a';
        if (root->children[index] == nullptr)
        {
            return false;
        }

        // Recursive Call
        TrieNode *child = root->children[index];
        bool subSearchAns = search(child, word.substr(1));

        return subSearchAns;
    }

    void removeWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            root->isTerminal = false; // the word still exists, but when searched, would return false
            return;
        }

        // Computation
        int index = word[0] - 'a';
        if (root->children[index] == nullptr)
        {
            // word not found
            return;
        }

        // Recursive call
        TrieNode *child = root->children[index];
        removeWord(child, word.substr(1));

        // remove child node if it is useless - i.e. it is not a terminal node and has no children
        if (child->isTerminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != nullptr)
                {
                    return;
                }
            }
            delete child;
            root->children[index] = nullptr;
        }
    }

    // For user
    void insertWord(string word)
    {
        insertWord(root, word);
    }

    bool search(string word)
    {
        return search(root, word);
    }

    void removeWord(string word)
    {
        removeWord(root, word);
    }
};