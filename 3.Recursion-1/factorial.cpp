#include <iostream>
using namespace std;

int factorial(int n)
{
    cout << n << endl;
    
    // Stopping condition
    if (n <= 0)
    {
        return 1;
    }
    int smallerOutput = factorial(n-1);
    return n * smallerOutput;
}

int main()
{
    int n;
    cin >> n;
    int answer = factorial(n);
    cout << answer << endl;
    return 0;
}