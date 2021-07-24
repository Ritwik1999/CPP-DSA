#include <iostream>
using namespace std;
#include "Student.cpp"
#include "Teacher.cpp"
#include "TA.cpp"

int main()
{
    TA a;

    a.Student::print();
    a.Teacher::print();
    a.print();  // Since TA class also has a print function, this call isn't ambiguous

    // a.name = "Ritwik";  // Ambiguous as TA doesn't have the data member name
    a.Student::name = "Ritwik";
}