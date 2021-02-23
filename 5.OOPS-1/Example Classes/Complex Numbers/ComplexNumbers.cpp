class ComplexNumbers {
   
private:
    int real;
    int imaginary;
    
public:
    ComplexNumbers(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }
    
    void plus(ComplexNumbers const &c2)
    {
        real += c2.real;
        imaginary += c2.imaginary;
    }
    
    void multiply(ComplexNumbers const &c2)
    {
        
        int new_real = (real * c2.real) - (imaginary * c2.imaginary);
        int new_imaginary = (real * (c2.imaginary)) + (imaginary * (c2.real));
        
        real = new_real;
        imaginary = new_imaginary;
    }
    
    void print()
    {
        cout << real << " + i" << imaginary << endl;
    }    
};