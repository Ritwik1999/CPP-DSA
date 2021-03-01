class Polynomial {
public:
    int *degCoeff;      // Name of your array (Don't change this)
	int capacity;
    
    Polynomial()
    {
        degCoeff = new int[5];
        capacity = 5;
        
        for (int i = 0; i < capacity; i++)
        {
            degCoeff[i] = 0;
        }
    }
    
    Polynomial(Polynomial const &p)
    {
        this->degCoeff = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            this->degCoeff[i] = p.degCoeff[i];
        }
        
        this->capacity = p.capacity;
    }
    
    void setCoefficient(int index, int value)
    {
        if (index >= capacity)
        {
            int count = 1;
            while (capacity*count <= index)
            {
                count++;
            }
            
            int* newPolyArray = new int[count*capacity];
            for (int i = 0; i < count*capacity; i++)
            {
                if (i >= capacity)
                {
                    newPolyArray[i] = 0;
                }
                
                else
                {
                    newPolyArray[i] = degCoeff[i];
                }
            }
            
            delete [] degCoeff;
            degCoeff = newPolyArray;
            
            capacity *= count;
        }
        
        degCoeff[index] = value;
    }
    
	Polynomial operator+(Polynomial const &p)
    {
        int smallerCapacity = (this->capacity < p.capacity) ? this->capacity : p.capacity;
        int i, value;
        Polynomial const &higherDegreePoly = (this->capacity < p.capacity) ? p : *this;
        Polynomial sum;        
        
        for (i = 0; i < smallerCapacity; i++)
        {
            value = this->degCoeff[i] + p.degCoeff[i];
        	sum.setCoefficient(i, value);   
        }
        
        while(i < higherDegreePoly.capacity)
        {
            value = higherDegreePoly.degCoeff[i];
        	sum.setCoefficient(i, value);
            i++;
        }
        
        return sum;        
    }
    
    Polynomial operator-(Polynomial const &p)
    {
        int smallerCapacity = (this->capacity < p.capacity) ? this->capacity : p.capacity;
        int i, value;
        Polynomial const &higherDegreePoly = (this->capacity < p.capacity) ? p : *this;
        Polynomial diff;

        for (i = 0; i < smallerCapacity; i++)
        {
            value = this->degCoeff[i] - p.degCoeff[i];
            diff.setCoefficient(i, value);
        }

        while (i < higherDegreePoly.capacity)
        {
            value = (this->capacity < p.capacity) ? -1*(higherDegreePoly.degCoeff[i]) : higherDegreePoly.degCoeff[i];
            diff.setCoefficient(i, value);
            i++;
        }
        return diff;
    }
    
    Polynomial operator*(Polynomial const &p)
    {
        Polynomial product;
        int index, value;

        for (int i = 0; i < this->capacity; i++)
        {
            for (int j = 0; j < p.capacity; j++)
            {
                index = i + j;
                value = (index >= product.capacity) ? (this->degCoeff[i] * p.degCoeff[j]) : (product.degCoeff[index] + (this->degCoeff[i] * p.degCoeff[j]));
                product.setCoefficient(index, value);
            }
        }
        return product;
    }
    
    void operator=(Polynomial const &p)
    {
        delete [] degCoeff;
        degCoeff = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            degCoeff[i] = p.degCoeff[i];
        }
        capacity = p.capacity;
    }
    
    void print() const
    {
        if (degCoeff[0] != 0)
        {
            cout << degCoeff[0] << "x" << 0 << " ";
        }

        int i;

        for (i = 1; i < capacity-1; i++)
        {
            if (degCoeff[i] != 0)
            {
                cout << degCoeff[i] << "x" << i << " ";
            }
        }

        if (degCoeff[i] != 0)
        {
            cout << degCoeff[i] << "x" << i;
        }
        cout << endl;
    } 
};