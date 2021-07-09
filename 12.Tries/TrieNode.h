// Dictionary to store words with all lowercase english alphabets
class TrieNode
{
public:
    char data;  
    TrieNode **children;    // children is a pointer that holds the address of a location that stores values of type TrieNode* (i.e., pointers to instances of the TrieNode class)
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        isTerminal = false;

        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};