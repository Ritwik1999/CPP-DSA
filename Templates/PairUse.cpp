#include <iostream>
using namespace std;

#include "Pair.cpp"

int main()
{
    Pair<Pair<int, int>, int> p2;

    Pair<int, int> p4;
    p4.setX(15);
    p4.setY(16);

    p2.setX(p4);
    p2.setY(10);

    cout << p2.getX().getX() << " " << p2.getX().getY() << " " << p2.getY() << endl;

    Pair<int, Pair<double, char>> p5;

    Pair<double, char> p6;
    p6.setX(100.23);
    p6.setY('r');

    p5.setX(10);
    p5.setY(p6);

    cout << p5.getX() << " " << p5.getY().getX() << " " << p5.getY().getY() << endl;

    /*
    Pair<int, double> p1;
    p1.setX(100.34);
    p1.setY(100.34);
    cout << p1.getX() << " " << p1.getY() << endl;

    Pair<int> p1;
    p1.setX(10);
    p1.setY(20);
    cout << p1.getX() << " " << p1.getY() << endl;

    Pair<double> p2;
    p2.setX(100.34);
    p2.setY(34.21);
    cout << p2.getX() << " " << p2.getY() << endl;

    Pair<char> p3;
    */

    return 0;
}