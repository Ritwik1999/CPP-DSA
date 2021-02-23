class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void print() {
        cout << numerator << "/" << denominator << endl; 
    }

    void simplify()
    {
        int gcd = 1;
        for (int i = 1; i < min(numerator, denominator); i++)
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                gcd = i;
            }
        }

        numerator /= gcd;
        denominator /= gcd;
    }

    /*
        the argument Fraction f2 is effectively the following
            Fraction f2 = main.f2;
        i.e., copy constructor

        In order to avoid creating new memory, we can pass f2 by ref
        Again, if passed by ref, to avoid accidental modification to f2, 
        we may pass it as a ref to a const Fraction object (that was declared in main)
    */

    void add(Fraction const &f2)
    {
        int lcm = denominator * f2.denominator;
        int x = lcm/denominator;
        int y = lcm/f2.denominator;

        int num = x * numerator + (y * f2.numerator);

        numerator = num;
        denominator = lcm;

        simplify();
    }

    void multiply(Fraction const &f2)
    {
        numerator *= f2.numerator;
        denominator *= f2.denominator;

        simplify();
    }

};