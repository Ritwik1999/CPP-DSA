/*
    On Constructors, they are special type of methods (class member functions), that
    have same name as the class, and have no return type.

    They are used so that whenever an object is declared (statically or dynamically),
    it's properties do not store garbage values.

    NOTE: Assuming Student is a user-defined class, this code...
        
        Student s1(a, b);

    internally resolves to this...

        s1.Student(a, b);

    Unless the user has not defined any type of constructor, the compiler automatically
    assigns a default constructor to each class.

    Once the user defines a constructor, the compiler constructor becomes unavilable,
    and creating an object for which a constructor cannot be identified (using arguments),
    will throw an error.
*/


#include <iostream>
using namespace std;

#include "Student.cpp"

int main()
{
    Student s1;
    s1.display();

    Student s2;

    Student* s3 = new Student;
    s3->display();

    cout << "Parameterized constructor demo" << endl;

    Student s4(101);

    s4.display();

    Student* s5 = new Student(102);

    s5->display();

    Student s6(20, 103);
    s6.display(); 

    return 0;
}