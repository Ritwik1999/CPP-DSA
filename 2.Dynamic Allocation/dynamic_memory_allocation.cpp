#include <iostream>
using namespace std;

/*
    Dynamic - Allocated (dynamically) on the heap, at runtime. (Huge capacity, random allocation)
    Static - Allocated (statically) on the stack, at compile time; (Less size, allocation on an LIFO structure, stack)

    Static allocation is quick whereas dynamic allocation is slow.

    For more information, visit - https://stackoverflow.com/questions/79923/what-and-where-are-the-stack-and-heap
*/

/* 
    To allocate memory dynamically, we use the keyword "new",
    which essentially returns an address that points to this space
    of specified size.

    The address returned can then be stored on a (statically allocated)
    pointer variable.
*/

/*
    Statically allocated arrays, though can have their size decided at runtime,
    it's value may cause Stack Overflow!. Hence, this is not a good practice

    int n;
    cin >> n;
    int arr[n];

    However, you can do this using dynamic memory allocation.
*/

/*
    Statically allocated memory is cleared as soon as the scope of current context
    (loop, function, etc..) is over.

    Dynamically allocated memory has to be manually cleared, or it will ultimately 
    crash the program.

    To free up dynamic memory, use the "delete" keyword, and "delete []" for array.
*/

int main()
{
    int i = 10; // Static allocation

    // Dynamic Allocation
    int* p = new int;
    *p = 10;
    cout << *p << endl;
    delete p;

    double* dp = new double;
    *dp = 10.23;
    cout << *dp << endl;
    delete dp;

    p = new int[20];
    delete [] p;

    // Small program using dynamic allocation
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int* pa = new int[n];

    cout << "Enter the elements of the array: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> *(pa + i);
    }

    int max = *pa;
    i = 1;

    while(i < n) {
        if (*(pa + i) > max)
            max = *(pa + i);
        
        i++;
    }

    cout << "The max element in the array is: " << max << endl;

    delete [] pa;

    return 0;
}