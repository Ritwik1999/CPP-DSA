/*
    Header files (*.h) are just like cpp files except that they cannot have a main function
*/

/*
    Strictly speaking, variables, arrays, and linked lists are the only concrete 
    ways to store data. Other than these, we use Abstract data types (that internally
    use either arrays or linked lists) to store data.

    They are called Abstract data types because unlike the random, and complete access
    that we have using arrays and ll, we want the user to be able to do only specific 
    actions with our data types, and give limited control. Hence, abstract (hidden internal structure).

    NOTE: Study Templates before this
*/

// #include <climits>   For INT_MIN

template <typename T>
class StackUsingArray
{
    T *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray()
    {
        nextIndex = 0;
        capacity = 4;
        data = new T[capacity];        
    }

    // return the number of elements present in the stack
    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return (nextIndex == 0);
    }

    // insert element
    void push(T element)
    {
        if (nextIndex == capacity)
        {
            T *newData = new T[capacity*2];

            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }

            delete [] data;
            data = newData;
            capacity *= 2;
            /*
            cout << "Stack full" << endl;
            return;
            */
        }

        data[nextIndex++] = element;
    }

    // delete element
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;   // Because 0 is valid across all data types, including pointers
        }
        return data[--nextIndex];
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return data[nextIndex-1];
    }
};