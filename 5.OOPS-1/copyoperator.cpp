/*
    This is an operator that is available in c++.

    Constructor is called only once per object, during it's creation.
    This means, to assign values of one object with another after their
    declaration, we'd have to explicitly mention each and every property.
    But, C++ has the = operator that will save you from all the hassle,
    and copy the values of the object on the RHS to the object in LHS.

    NOTE: This only works when either both the objects have already been declared,
    or the copy operator is used in conjunction with the copy constructor like this...

    Student s2 = s1;

    It is called the copy assignment operator
*/

#include <iostream>
using namespace std;

#include "Student.cpp"

int main()
{
    Student s1(10, 1001);
    Student s2(20, 2001);

    Student* s3 = new Student(30, 3001);

    // this is the copy operator
    s2 = s1;

    *s3 = s1;

    s2 = *s3;

    delete s3;

    return 0;
}