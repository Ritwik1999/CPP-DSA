/*
    Two problems.

    1. The inbuilt copy constructor uses Shallow Copy to initialise one object with values of other objects.
    Hence, if any array is involved (which decays into a pointer when passed as arguments), a change in one
    object would also reflect in the other.

    2. If we define our own copy constructor, and use pass by value, the argument, e.g., Student s, would
    itself invoke the copy constructor, and the copy constructor's argument would again to do so, resulting in an
    infinite loop.

    Hence, it is always plausible to define your own copy constructor, and use deep copy (if need be), 
    and initialise its argument as a const ref.
*/

class Student
{
    int age;

public:
    char *name;

    Student(int age, char* name)
    {
        this->age = age;
        // Shallow Copy
        // this->name = name;

        // Deep Copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    Student(Student const &s)
    {
        this->age = s.age;
        // this->name = name;   Shallow copy, don't use it

        // Deep copy, recommended
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }

    void display()
    {
        cout << name << " " << age << endl;
    }
};
