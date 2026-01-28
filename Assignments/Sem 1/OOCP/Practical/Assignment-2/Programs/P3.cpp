// 3) WAP to Overload the *, +,-, ==, ! = and = operators for the complex class.

#include <iostream>
using namespace std;

class complex
{
private:
    float real;
    float imag;

public:
    // Constructor
    complex(float r = 0, float i = 0)
    {
        real = r;
        imag = i;
    }

    // Overloading '+' operator
    complex operator+(const complex &obj)
    {
        return complex(real + obj.real, imag + obj.imag);
    }

    // Overloading '-' operator
    complex operator-(const complex &obj)
    {
        return complex(real - obj.real, imag - obj.imag);
    }

    // Overloading '*' operator
    complex operator*(const complex &obj)
    {
        float r = real * obj.real - imag * obj.imag;
        float i = real * obj.imag + imag * obj.real;
        return complex(r, i);
    }

    // Overloading '==' operator
    bool operator==(const complex &obj)
    {
        return (real == obj.real && imag == obj.imag);
    }

    // Overloading '!=' operator
    bool operator!=(const complex &obj)
    {
        return !(*this == obj);
    }

    // Overloading '=' operator
    complex &operator=(const complex &obj)
    {
        if (this != &obj)
        { // Avoid self-assignment
            real = obj.real;
            imag = obj.imag;
        }
        return *this;
    }

    // Function to display complex number
    void display()
    {
        cout << real;
        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";
        cout << endl;
    }
};

int main()
{
    complex c1(3, 4), c2(1, 2), c3;

    cout << "First complex number: ";
    c1.display();

    cout << "Second complex number: ";
    c2.display();

    // Addition
    c3 = c1 + c2;
    cout << "Addition result: ";
    c3.display();

    // Subtraction
    c3 = c1 - c2;
    cout << "Subtraction result: ";
    c3.display();

    // Multiplication
    c3 = c1 * c2;
    cout << "Multiplication result: ";
    c3.display();

    // Assignment
    c3 = c1;
    cout << "After assignment, c3 = ";
    c3.display();

    // Equality
    if (c1 == c3)
        cout << "c1 and c3 are equal." << endl;
    else
        cout << "c1 and c3 are not equal." << endl;

    // Inequality
    if (c1 != c2)
        cout << "c1 and c2 are not equal." << endl;
    else
        cout << "c1 and c2 are equal." << endl;

    return 0;
}


// output
// First complex number: 3 + 4i
// Second complex number: 1 + 2i
// Addition result: 4 + 6i
// Subtraction result: 2 + 2i
// Multiplication result: -5 + 10i
// After assignment, c3 = 3 + 4i
// c1 and c3 are equal.
// c1 and c2 are not equal.