/*
Constructors are invoked first for the Base Class and then for the Derived class
Destructors are invoked in the opposite way

NOTE: A child class constructor can only invoke its immediate parent class constructor
*/

#include <iostream>
using namespace std;
#include "Vehicle.cpp"
#include "Car.cpp"
#include "Truck.cpp"
#include "Bus.cpp"
#include "HondaCity.cpp"

int main()
{
	/*
		Vehicle v;
		v.color = "Blue";
		// v.maxSpeed = 100;
		// v.numTyres = 4;

		Car c(50, 40);
		c.color = "Black";
		// c.numTyres = 4;
		c.numGears = 5;	

		HondaCity h;
		cout << "----------------------" << endl;
		HondaCity h1(100, 150);
	*/

	Bus b;	// Vehicle(), Car(), Vehicle(), Truck(), Bus()

	// b.print(); Confusion. print() of Truck or Car. To remove the ambiguity, define a print() function for Bus class, or use the scope resolution operator

	b.Car::print();
	b.Truck::print();
}
