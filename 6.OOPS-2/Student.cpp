/*
    Shallow Copy - when an array is passed as an argument, to avoid unecessary 
    space usage, only it's base address is passed, this is called a Shallow Copy

    The problem with it is that it just creates another way to access some memory
    defined elsewhere, thereby making it vulnerable to some unknown change.

    Hence, the best way to deal with these is deep copy, or making an entire copy
    of the array.

    See the pics as well.
*/

class Student
{
    int age;
    char *name;

public:
    Student(int age, char* name)
    {
        this->age = age;
        // Shallow Copy
        // this->name = name;

        // Deep Copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void display()
    {
        cout << name << " " << age << endl;
    }
};