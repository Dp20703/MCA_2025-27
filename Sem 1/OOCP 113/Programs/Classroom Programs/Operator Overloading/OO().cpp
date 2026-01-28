// OO().cpp
// Operator overloading of () 
#include <iostream>
using namespace std;
class Point
{
    int x;
    int y;

public:
    void operator()(int tempx, int tempy)
    {
        x = tempx;
        y = tempy;
    }
    friend ostream &operator<<(ostream &tempout, Point &pt);
};
ostream &operator<<(ostream &TempOut, Point &Pt)
{
    TempOut << "(" << Pt.x << "," << Pt.y << ")\n";
    return TempOut;
}

int main()
{
    Point p1;
    p1(2, 3);
    Point p2;
    p2(23, 33);
    cout << p1;
    cout << p2;

    return 0;
}