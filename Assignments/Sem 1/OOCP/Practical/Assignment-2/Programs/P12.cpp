// 12) Write an object-oriented program to implement a generic Number Class that
// can accept either int or float data type and perform basic calculation like +,-,/
// and *.
#include <iostream>
using namespace std;

// Template class Number
template <typename T>
class Number
{
private:
    T value;

public:
    // Constructor
    Number(T v)
    {
        value = v;
    }

    // Addition
    Number operator+(const Number &other)
    {
        return Number(value + other.value);
    }

    // Subtraction
    Number operator-(const Number &other)
    {
        return Number(value - other.value);
    }

    // Multiplication
    Number operator*(const Number &other)
    {
        return Number(value * other.value);
    }

    // Division
    Number operator/(const Number &other)
    {
        if (other.value == 0)
        {
            cout << "Error: Division by zero!" << endl;
            return Number(0); // Or handle it differently
        }
        return Number(value / other.value);
    }

    // Display the value
    void display() const
    {
        cout << value << endl;
    }
};

int main()
{
    // Using with integers
    Number<int> n1(20);
    Number<int> n2(5);

    cout << "Integer calculations:" << endl;
    cout << "n1 + n2 = ";
    (n1 + n2).display();
    cout << "n1 - n2 = ";
    (n1 - n2).display();
    cout << "n1 * n2 = ";
    (n1 * n2).display();
    cout << "n1 / n2 = ";
    (n1 / n2).display();

    cout << endl;

    // Using with floats
    Number<float> f1(12.5);
    Number<float> f2(2.5);

    cout << "Float calculations:" << endl;
    cout << "f1 + f2 = ";
    (f1 + f2).display();
    cout << "f1 - f2 = ";
    (f1 - f2).display();
    cout << "f1 * f2 = ";
    (f1 * f2).display();
    cout << "f1 / f2 = ";
    (f1 / f2).display();

    return 0;
}

// output
// Integer calculations:
// n1 + n2 = 25
// n1 - n2 = 15
// n1 * n2 = 100
// n1 / n2 = 4

// Float calculations:
// f1 + f2 = 15
// f1 - f2 = 10
// f1 * f2 = 31.25
// f1 / f2 = 5