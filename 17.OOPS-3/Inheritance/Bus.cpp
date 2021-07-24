class Bus : public Car, public Truck
{
public:
    /*
        Internally, the order of constructor invokation would be as per the class definition, first Car, then Truck
        Bus() : Car(), Truck() {
            cout << "Bus's default constructor" << endl;
        }
    */
    Bus()
    {
        cout << "Bus's default constructor" << endl;
    }

    ~Bus()
    {
        cout << "Bus's default destructor" << endl;
    }
};