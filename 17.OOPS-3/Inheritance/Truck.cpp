class Truck : public Vehicle
{
public:
    Truck()
    {
        cout << "Truck's default constructor" << endl;
    }

    ~Truck()
    {
        cout << "Truck's default destructor" << endl;
    }
};