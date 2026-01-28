#include <iostream>
using namespace std;

template <typename T>
class Box
{
    T value;

public:
    Box(T v) : value(v) {}
    T getValue()
    {
        return value;
    }
};

int main()
{
    Box<int> intBox(123);
    Box<string> strBox("Hello");

    cout << "Integer Box: " << intBox.getValue() << endl;
    cout << "String Box: " << strBox.getValue() << endl;

    return 0;
}
