class HondaCity : public Car
{
public:
    HondaCity() {
        cout << "Honda City default constructor" << endl;
    }

    HondaCity(int x, int y) : Car(x, y)
    {
        cout << "Honda City parameterized constructor" << endl;
    }

    ~HondaCity()
    {
        cout << "Honda City destructor" << endl;
    }
};