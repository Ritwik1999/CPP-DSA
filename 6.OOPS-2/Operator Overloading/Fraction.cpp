/*
    Operator Overloading, is a way to define operations on used defined data types.

    e.g, adding two objects of type Fraction using the + operator
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
        for (int i = 1; i <= min(numerator, denominator); i++)
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                gcd = i;
            }
        }

        numerator /= gcd;
        denominator /= gcd;
    }

    // Below function overloads the + operator for the Fraction class (see the operator overloading pics for the this keyword and arguments)
    Fraction operator+(Fraction const &f2) const
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = x * numerator + (y * f2.numerator);

        Fraction fNew(num, lcm);
        fNew.simplify();

        return fNew;
    }

    Fraction operator*(Fraction const &f2) const
    {
        int n = numerator * f2.numerator;
        int d = denominator * f2.denominator;

        Fraction fNew(n, d);
        fNew.simplify();

        return fNew;
    }

    bool operator==(Fraction f2)
    {
        simplify();
        f2.simplify();    
        return (numerator == f2.numerator && denominator == f2.denominator);
    }

    /*
        Unary Operator Overloading (see the pic first)
        Pre increment, the return type and value allows us to perform something like Fraction fNew = ++f1;

        The return type being a ref allows us to chain multiple operators, if a ref is not returned,
        the return value would be copied to a buffer memory and it'd be passed to the calling place.
        That way, the chained operators would work on temp buffer memory, rather than the original memory.

        This is the case with any value returned in general, or even with something like int i = 5;
        In the latter case, 5 is stored in a buffer memory until the variable i is allocated memory, 
        after which 5 is copied on to i.
    */
    Fraction& operator++()
    {
        numerator += denominator;  // i.e. this->numerator += this->denominator
        simplify();                // i.e. this->simplify()

        return *this;              // See the pic to know what this holds
    }

    // Post increment operator, the signature is as below
    Fraction operator++(int)
    {
        Fraction fNew(numerator, denominator);
        numerator += denominator;
        simplify();
        fNew.simplify();
        return fNew;
    }

    // += operator
    Fraction& operator+=(Fraction const &f2)
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = x * numerator + (y * f2.numerator);

        numerator = num;
        denominator = lcm;
        simplify();

        return *this;
    }
};