#include <string>
#include <iostream>
using namespace std;

class A
{
private:
    string _msg;

public:
    A(string x) : _msg(x) {}
    
    void test()
    {
        cout << "hello from A: " << _msg << "\n";
    }
};

// B,C inherit A virtually
class B : virtual public A
{
public:
    B(string x) : A("b") {}
};
class C : virtual public A
{
public:
    C(string x) : A("c") {}
};

// since B,C inherit A virtually, A must be constructed in each child
class D : public B, C
{
public:
    D(string x) : A("d_a"), B("d_b"), C("d_c") {}
};
class E : public D
{
public:
    E(string x) : A("e_a"), D("e_d") {}
};

// breaks without constructing A
// class D: public         B,C { public: D(string x):B(x),C(x){}  };

// breaks without constructing A
//class E: public         D   { public: E(string x):D(x){}  };

int main()
{
    D d("d");
    d.test(); // hello from A: d_a

    E e("e");
    e.test(); // hello from A: e_a
}