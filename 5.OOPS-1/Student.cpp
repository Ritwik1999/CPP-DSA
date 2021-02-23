/*
    Public members (vars + fns) can be accessed outside the class, but
    Private members can only be accessed within the scope of the class.

    Any var or fn (including special ones) can be declared as public or private 

    Private variables can be accessed and modified through functions of the
    same class, generally called getter and setter functions.
*/
class Student
{
    int age;

public:
    int rollNumber;

    // Default Constructor
    Student()
    {
        cout << "constructor called" << endl;
    }

    // Parameterized constructor
    Student(int r)
    {
        cout << "constructor 2 called!" << endl;
        rollNumber = r;
    }

    Student(int a, int r)
    {
        cout << "constructor 3 called!" << endl;
        age = a;
        rollNumber = r;
    }

    void display()
    {
        cout << age << " " << rollNumber << endl;
    }

    // Getter
    int getAge()
    {
        return age;
    }

    // Setter
    void setAge(int a)
    {
        if (a < 0)
        {
            return;
        }

        age = a;
    }

    // Destructor
    ~Student()
    {
        cout << "Destructor called!!" << endl;
    }
};
