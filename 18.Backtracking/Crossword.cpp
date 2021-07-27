/*
You are provided with a crossword of 10*10 grid.
The grid contains '+' or '-' as its cell values.
You are also provided with a word list that needs to placed accurately in the grid.
Cells marked with '-' are to be filled with word list.
*/

/*
Sample Input:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV

Sample Output:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
*/

#include <iostream>
#include <vector>
#include <string>

#define n 10
using namespace std;

bool isValidVertical(char board[n][n], int x, int y, string word)
{
    for (int i = 0; i < word.size(); i++)
    {
        if ((x + i) >= n)
            return false;
        if (board[x + i][y] == '+')
            return false;
        if (board[x + i][y] != '-')
        {
            if (board[x + i][y] != word[i])
                return false;
        }
    }
    return true;
}

void setVertical(char board[n][n], int x, int y, string word, bool *tracker)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (board[x + i][y] == '-')
        {
            board[x + i][y] = word[i];
            tracker[i] = true;
        }
        else if (board[x + i][y] == word[i])
        {
            tracker[i] = false;
        }
    }
}

void unsetVertical(char board[n][n], int x, int y, bool *tracker, int l)
{
    for (int i = 0; i < l; i++)
    {
        if (tracker[i])
        {
            board[x + i][y] = '-';
        }
    }
}

void setHorizontal(char board[n][n], int x, int y, string word, bool *tracker)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (board[x][y + i] == '-')
        {
            board[x][y + i] = word[i];
            tracker[i] = true;
        }
        else if (board[x][y + i] == word[i])
        {
            tracker[i] = false;
        }
    }
}

void unsetHorizontal(char board[n][n], int x, int y, bool *tracker, int l)
{
    for (int i = 0; i < l; i++)
    {
        if (tracker[i])
        {
            board[x][y + i] = '-';
        }
    }
}

bool isValidHorizontal(char board[n][n], int x, int y, string word)
{
    for (int i = 0; i < word.size(); i++)
    {
        if ((y + i) >= n)
            return false;
        if (board[x][y + i] == '+')
            return false;
        if (board[x][y + i] != '-')
        {
            if (board[x][y + i] != word[i])
                return false;
        }
    }
    return true;
}

bool solveCrossword(char board[n][n], vector<string> words, int wordIndex)
{
    if (wordIndex == words.size())
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j];
            }
            cout << endl;
        }
        return true;
    }

    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            if (board[x][y] == '-' || board[x][y] == words[wordIndex][0])
            {
                if (isValidVertical(board, x, y, words[wordIndex]))
                {
                    int l = words[wordIndex].size();
                    bool tracker[l];
                    setVertical(board, x, y, words[wordIndex], tracker);
                    if (solveCrossword(board, words, wordIndex + 1))
                        return true;
                    unsetVertical(board, x, y, tracker, l);
                }

                if (isValidHorizontal(board, x, y, words[wordIndex]))
                {
                    int l = words[wordIndex].size();
                    bool tracker[l];
                    setHorizontal(board, x, y, words[wordIndex], tracker);
                    if (solveCrossword(board, words, wordIndex + 1))
                        return true;
                    unsetHorizontal(board, x, y, tracker, l);
                }
            }
        }
    }

    return false;
}

int main()
{
    char board[n][n];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            board[i][j] = s.at(j);
        }
    }

    string wordList;
    cin >> wordList;
    vector<string> words;

    while (wordList.size() != 0)
    {
        if (wordList.find(";") != string::npos)
        {
            words.push_back(wordList.substr(0, wordList.find(";")));
            wordList.erase(0, wordList.find(";") + 1);
        }
        else
        {
            words.push_back(wordList);
            wordList = "";
        }
    }

    solveCrossword(board, words, 0);

    return 0;
}