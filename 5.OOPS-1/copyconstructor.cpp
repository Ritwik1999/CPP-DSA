/*
    Copy constructor can be used to initialise tha value of
    one object with the same values as that of another object

    Copy constructor, like a default constructor is provided in C++,
    unless a copy constructor is created by the developer.
*/

#include <iostream>
using namespace std;

#include "Student.cpp"

int main()
{
    Student s1(10, 1001);
    cout << "S1 : ";
    s1.display();

    // Using copy constructor
    Student s2(s1);
    cout << "S2 : ";
    s2.display();

    Student* s3 = new Student(20, 2001);
    cout << "S3 : ";
    s3->display();

    Student s4(*s3);

    Student* s5 = new Student(*s3);
    Student* s6 = new Student(s1);

    delete s3, s5, s6;

    // NOTE: For optimal reasons, the copy constructor and copy operator can be combined like this
    Student s7 = s1;

    return 0;
}
