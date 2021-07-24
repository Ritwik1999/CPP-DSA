class Vehicle
{
private:
	int maxSpeed;

protected:
	int numTyres;

public:
	string color;

	/*
		If the default constructor below was not defined but a parameterized constructor was defined,
		then creating a child class object would not be possible as it's constructor would try and invoke
		the defult constuctor of Vehicle class, which does not exist.
	*/
	Vehicle() {
		cout << "Vehicle's default constructor" << endl;
	}

	Vehicle(int z) {
		maxSpeed = z;
		cout << "Vehicle's parameterized constructor" << endl;
	}

	~Vehicle() {
		cout << "Vehicle's destructor" << endl;
	}

	void print() {
		cout << "Vehicle" << endl;
	}
};
