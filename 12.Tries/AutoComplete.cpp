/*
Given n number of words and an incomplete word w. You need to auto-complete that word w.
That means, find and print all the possible words which can be formed using the incomplete word w.
Note : Order of words does not matter.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
    
    void autoComplete(TrieNode *node, string word) {
        if (node->isTerminal) {
            cout << word << endl;
        }
        
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                TrieNode *nextNode = node->children[i];
                string newWord = word + nextNode->data;
                autoComplete(nextNode, newWord);
            }
        }
        
        return;
    }
    
    TrieNode *search(TrieNode *root, string pattern) {
        // Base Case
        if (pattern.size() == 0) {
            return root;
        }
        
        // Computation
        int index = pattern[0] - 'a';
        TrieNode *child = root->children[index];
        if (child == nullptr) {
            return nullptr;
        }
        
        // Recursive Call
        return search(child, pattern.substr(1));
    }

    void autoComplete(vector<string> input, string pattern) {        
        for (string word : input) {
            insertWord(word);
        }
        
        if (pattern.size() == 0) {
            return;
        }
        
        TrieNode *node = search(root, pattern);
        if (node != nullptr) {
            autoComplete(node, pattern);
        }
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);
}