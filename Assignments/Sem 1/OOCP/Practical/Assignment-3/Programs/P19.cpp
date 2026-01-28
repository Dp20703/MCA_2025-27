// Console I/O, Manipulators, Namespace and STL:
// 19) Design a manipulator to provide the following output specifications for
// printing float values
// (i) 5 column width
// (ii) Right justified
// (iii) 2 digits precision
// (iv) Filling unused spaces with +

#include <iostream>
#include <iomanip>
using namespace std;

ostream &myformat(ostream &out)
{
    out << fixed << setprecision(2) << setw(5) << setfill('+') << right;
    return out;
}

int main()
{
    float a = 12.3456, b = 3.1, c = 89.999;

    cout << myformat << a << endl;
    cout << myformat << b << endl;
    cout << myformat << c << endl;

    return 0;
}
// Output:
// 12.35
// +3.10
// 90.00