// Run-time polymorphism
/*
Use Case:
Classes HR, Manager, Employee, Others derive from class Employee.
Employee has a virtual function calculateSalary that is overidden in each of the derived classes that calculates salary for the respective class of employees

Any of the above class objects can be stored in an array of type Employee, and whatever be the object at array[i], the corresponding version of calculateSalary will be invoked (as it is a virtual function)
*/

#include <iostream>
using namespace std;

class Vehicle
{
private:
    string color;

public:
    virtual void print()
    {
        cout << "Vehicle" << endl;
    }
};

class Car : public Vehicle
{
public:
    int numTyres;

    void print()
    {
        cout << "Car" << endl;
    }
};

int main()
{
    Vehicle v;
    Car c;

    v.print();
    c.print();

    Vehicle *v1 = new Vehicle;
    v1->print();

    Vehicle *v2 = new Car();
    v2->print();    // prints "Car" even though v2 is a pointer to type Vehicle, becuase print is a virtual funtion
    
    return 0;
}