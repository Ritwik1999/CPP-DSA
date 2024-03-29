/*
Write a program to find a solution to a sudoku puzzle.
The input will consist of puzzles with exactly one solution.

Input Format:
The input consists of one test case.
Each test case will consist of nine lines with nine digits on each line.
There will not be any blanks between the digits.
The digits '1' through '9' will represent a number and the digit '0' will represent a blank square.

Sample Input 1:
023456789
406789123
780123456
234067891
567801234
891230567
345678012
678912305
912345670

Sample Output 1:
123456789
456789123
789123456
234567891
567891234
891234567
345678912
678912345
912345678
*/

#include <iostream>
using namespace std;

bool isSafe(int **board, int x, int y, int num) {
    bool ans = true;

    // row
    for (int i = 0; i < 9; i++) {
        if (board[i][y] == num) {
            ans = false;
            break;
        }
    }

    // column
    for (int j = 0; j < 9; j++) {
        if (board[x][j] == num) {
            ans = false;
            break;
        }
    }

    // box
    int boxRow = x/3;
    int boxCol = y/3;
    for (int i = boxRow*3; i < (boxRow*3)+3; i++) {
        for (int j = boxCol*3; j < (boxCol*3)+3; j++) {
            if (board[i][j] == num) {
                ans = false;
                break;
            }
        }
    }

    return ans;
}

pair<int, int> findEmptyPosition(int **board)
{
    pair<int, int> pos;
    pos.first = -1;
    pos.second = -1;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                pos.first = i;
                pos.second = j;
                return pos;
            }
        }
    }

    return pos;
}

bool solveSudoku(int **board)
{
    pair<int, int> pos = findEmptyPosition(board);
    if (pos.first == -1 || pos.second == -1)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j];
            }
            cout << endl;
        }
        return true;
    }

    int x = pos.first, y = pos.second;
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(board, x, y, num))
        {
            board[x][y] = num;
            if (solveSudoku(board))
                return true;
            board[x][y] = 0;
        }
    }
    return false;
}

int main()
{
    int **board = new int *[9];
    for (int i = 0; i < 9; i++)
    {
        board[i] = new int[9];
    }

    for (int i = 0; i < 9; i++)
    {
        string row;
        cin >> row;

        for (int j = 0; j < 9; j++)
        {
            char c = row.at(j);
            board[i][j] = c - '0';
        }
    }

    solveSudoku(board);

    for (int i = 0; i < 9; i++)
    {
        delete[] board[i];
    }

    delete[] board;

    return 0;
}