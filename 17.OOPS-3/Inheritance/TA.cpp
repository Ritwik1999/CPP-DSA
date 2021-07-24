class TA : public Teacher, public Student
{
public:
    string name;    

    void print()
    {
        cout << "TA" << endl;
    }
};