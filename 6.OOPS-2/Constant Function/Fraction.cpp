/*
    const functions, are those that do not change the value of any data member of 
    the corresponding object, i.e., does not change the value of this->data_member
    in it's body.

    If a function (e.g., setDenominator) that changes any value (this->data_member)
    is declared as const, the compiler throws an error.

    Hence, it is a good C++ practice to declare all functions that qualify as
    const as such, so that even const objects can access them.
*/

class Fraction
{
private:
    int numerator;
    int denominator;

public:

    Fraction()
    {

    }
    
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    int getNumerator() const
    {
        return numerator;
    }

    int getDenominator() const
    {
        return denominator;
    }

    void setNumerator(int n)
    {
        numerator = n;
    }

    void setDenominator(int d)
    {
        denominator = d;
    }

    void print() const
    {
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
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

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