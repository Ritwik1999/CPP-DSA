#include <iostream>
using namespace std;

int main()
{
    double d = 10.156;
    double *dp = &d;

    cout << dp << endl;
    
    dp = dp + 2; // skips 2*(sizeof(double)), ahead.
    cout << dp << endl;

    dp = dp - 2;
    cout << dp << endl;

    // You can even perform comparisons on pointers of similar type

    return 0;
}