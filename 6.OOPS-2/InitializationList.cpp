/*
    we know that it is not possible to declare const vars, and refs
    without initializing them because const vars would become useless
    and ref vars would be an alias for unallocated memory.

    But what if we need const members inside class, or ref vars in class,
    initialising them statically doesnt make sense.

    And, we also cannot use constructor to do that because by the time
    we try initialise const members inside the constructor, the object memory
    would already have been allocated, and garbage values filled in the const member

    Enter initialization lists, these do the job while the constructor is allocating memory
    for the subject.

    So, it eventually becomes a const var declared and initialised.

    This can also be done with non const members

    NOTE: the compiler will not let you declare a const member if the class
    has no user defined constructor, because in that case, the const member would
    be useless after allocating memory at the object declaration step.

    Remember: A constructor allocates memory for an object before it's execution.
*/

#include <iostream>
using namespace std;

class Student
{
    int age;
    int const rollNumber;

public:
    Student(int age, int rollNumber) : rollNumber(rollNumber), age(age) {
        /*
            Here writing this is not important because it is understood
            that the var in arguments is in parenthesis in the list.

            One has to write this->member in case one member is a ref to another
            member and the constructor has the same name as the class member
        */
    }

    void display()
    {
        cout << rollNumber << " " << age << endl;
    }
};

int main()
{
    Student s(24, 101);
    s.display();

    return 0;
}
