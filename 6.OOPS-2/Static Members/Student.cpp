/*
    Static data members store values that aren't unique to an object
    like age and roll number, rather common for all objects of a given class.

    Such data members are called static data mermbers, and no matter how many
    objects exist for a class, there exists only one copy of static member(s).

    Static members belong to the class rather than individual objects

    Consequently, when objects are declared, memory for only
    the non static members is allocated.

    Extending the above point, static members are accessed like class_name::static_member,
    though the compiler wouldn't resist if it is done using the normal way

    Just like static data members, we have static member functions. They also
    belong to the class rather than an object.

    NOTE: Static member functions can only access (read/modify) static data members,
    and static functions do not have access to the this pointer (because this pointer exists for every object,
    not for the class).
*/

class Student
{
public:
    int rollNumber;
    int age;

    static int totalStudents; // total number of students present

    Student()
    {
        totalStudents++;
    }

    static int getTotalStudents()
    {
        return totalStudents;
    }
};

int Student::totalStudents = 0; // static members can only be initialised outside the class definition