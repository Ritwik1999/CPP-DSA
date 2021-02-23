#include <iostream>
using namespace std; 
#include "Student.cpp"

int main()
{
    // Create object(s) statically
    Student s1;

    // s1.age = 24;
    s1.setAge(24);
    s1.rollNumber = 101;

    // cout << s1.age << endl;
    cout << "Age : " << s1.getAge() << " ";
    cout << "Roll Number : " << s1.rollNumber << " " << endl;

    // Create object(s) dynamically
    Student *s2 = new Student;

    // (*s2).age = 23;
    (*s2).setAge(23);
    (*s2).rollNumber = 104;

    // An equivalent notation for above assignments

    // s2->age = 23;
    s2->setAge(23);
    s2->rollNumber = 104;

    cout << "Age : " << s2->getAge() << " ";
    cout << "Roll Number : " << s2->rollNumber << endl;

    delete s2; 

    return 0;
}