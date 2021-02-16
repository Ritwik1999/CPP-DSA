/*
    The subsequences problem, if output is stored, the space required is
    of the order of 2^n. If these subsequences are just to be printed, then 
    it can be done using constant space.

    Algo:
    1. Base Case: If input is empty, print output and return
    2. Computation: We'd either include input[0] in the output, or not.
    3. Recursion: Recur twice, once excluding input[0] from output, and once including it.
*/

#include <iostream>
using namespace std;

void print_subseqs(string input, string output)
{
    // Base Case
    if (input.size() == 0)
    {
        cout << output << endl;
        return;
    }

    // Computation & Recursion
    print_subseqs(input.substr(1), output);
    print_subseqs(input.substr(1), output + input[0]);

    return;
}

int main()
{
    string s;
    cin >> s;

    cout << "Subsequences are as follows: " << endl;
    print_subseqs(s, "");
    
    return 0;
}