/*
    this is a keyword in c++. It is a pointer that points to the object on which
    a member function was invoked. It lets you access the object properties,
    and resolve naming ambiguity.

    NOTE: Any member function that uses data members without this keyword
    can be considered using it implicitly (given there are no argument data member naming conflicts).
    Same goes for (non-static) member functions
*/

#include <iostream>
using namespace std;

class Demo
{
    int demoVar1;

public:
    /*
    In the function below, we want class member demoVar
    to be assigned the value of the argument demoVar,
    but due to scoping rules, demoVar is simply the argument passed,
    so the function body statement becomes trivial.

    Demo(int demoVar1)
    {
        demoVar1 = demoVar1;
    }
    */

    // To solve it, we use the this keyword.

    Demo(int demoVar1)
    {
        cout << "Constructor called!!" << endl;
        this->demoVar1 = demoVar1;
    }

    void getValueofthis()
    {
        cout << "Value of this keyword is: " << this << endl; 
    }
};

int main()
{
    Demo d1(12);
    d1.getValueofthis();
    cout << "Address of d1 object is: " << &d1 << endl;

    Demo d2(13);
    d2.getValueofthis();
    cout << "Address of d2 object is: " << &d2 << endl;

    // The output above proves that this keyword stores the address of the calling object
    
    return 0;
}
