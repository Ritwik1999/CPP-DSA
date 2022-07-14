#include <iostream>
using namespace std;

// Problem 1
int main()
{
    float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    float *ptr1 = &arr[0];
    float *ptr2 = ptr1 + 3;
    cout << *ptr2 << " ";
    cout << ptr2 - ptr1 << endl;
    return 0;
}

//Problem 2
int main()
{
    char st[] = "ABCD";
    for (int i = 0; st[i] != '\0'; i++)
    {
        cout << st[i] << *(st) + i << *(i + st) << i[st];
    }
    cout << endl;
    return 0;
}