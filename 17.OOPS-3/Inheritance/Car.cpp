class Car : public Vehicle
{
public:
	int numGears;

	/*
		Car c;
		This would invoke the constructor below, but internally, the call would be like
		Car() : Vehicle() {
			cout << "Car's default constructor" << endl;
		}
		The call would always be to invoke the default constructor of the parent class
		(Refer Initialization Lists)
	*/

	Car()
	{
		cout << "Car's default cosntructor" << endl;
	}

	Car(int x, int y) : Vehicle(x)
	{
		numGears = y;
		cout << "Car's paramterized cosntructor" << endl;
	}

	~Car()
	{
		cout << "Car's destructor" << endl;
	}
	
	void print()
	{
		cout << "Car" << endl;
	}
};
