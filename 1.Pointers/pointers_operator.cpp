#include <iostream>
using namespace std;

int main()
{
    double d = 10.156;
    double *dp = &d;

    cout << dp << endl;
    // The two statements below may output different values
    cout << "Size of double variable on this systems compiler is: " << sizeof(d) << endl;
    cout << "Size of double pointer on this systems compiler is: " << sizeof(dp) << endl;
    
    dp = dp + 2; // skips 2*(sizeof(double)), ahead.
    cout << dp << endl;

    dp = dp - 2; // skips 2*(sizeof(double)), behind.
    cout << dp << endl;

    // You can even perform comparisons on pointers of similar type
    cout << (dp == dp) << endl;

    return 0;
}