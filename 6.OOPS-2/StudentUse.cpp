#include <iostream>
#include <cstring>
using namespace std;

#include "Student.cpp"

int main()
{
    char name[] = "abcd";
    Student s1(20, name);
    s1.display();

    name[3] = 'e';
    Student s2(24, name);
    s2.display();

    // Try this code once with Shallow copy in Student.cpp, and once with Deep Copy
    s1.display();

    return 0;
}
