/*
    Destructor, just like a constructor is a special function provided in c++.
    It is used to clear the memory used by objects, once they go out of scope.

    Like a constructor, a destructor has the same name as the class, prefixed with a ~,
    and is called only once per object. It has no return type.

    Unlike a constructor, a destructor doesn't accept arguments.

    NOTE: Objects created dynamically have to be explicitly deleted to invoke their destructor

    Also, constructors and destructors have to be public member functions to be visible
    outside the class, though can be private members
*/

#include <iostream>
using namespace std;

#include "Student.cpp"

int main()
{
    Student s1(10, 1001);
    Student s2(20, 1002);

    Student* s3 = new Student(30, 2001);

    // If you comment the line below, the destructor will be called only for s1 and s2.
    delete s3;
    
    return 0;
}
