#include <iostream>
using namespace std;

#include "Student.cpp"

int main()
{
    Student s1, s2;

    cout << s1.rollNumber << " " << s1.age << endl;
    cout << Student::totalStudents << endl;

    // Below lines are allowed, but not recommended
    cout << s1.totalStudents << endl;
    s1.totalStudents = 20;
    cout << s1.totalStudents << " " << s2.totalStudents << endl;

    Student s3, s4, s5, s6;

    cout << Student::totalStudents << endl;

    // If a static member is private, use a getter function
    cout << Student::getTotalStudents() << endl;

    return 0;
}
