// a+bi : Program to add two complex numbers using operator overloading

#include <iostream>
using namespace std;

// Complex class to represent a complex number
class Complex
{
private:
    int real; // Real part
    int img;  // Imaginary part

public:
    // Constructor to initialize real and imaginary parts
    Complex(int real, int img) : real(real), img(img) {};

    // Overload + operator to add two complex numbers
    Complex operator+(const Complex &obj)
    {
        // Add real and imaginary parts separately
        return Complex(this->real + obj.real, this->img + obj.img);
    }

    // Display the complex number
    void display()
    {
        cout << "Real : " << real << endl;
        cout << "Imaginary : " << img << endl;
    }
};

int main()
{
    // Create two complex numbers
    Complex c1(10, 2), c2(12, 4);

    // Add the two complex numbers using overloaded + operator
    Complex c3 = c1 + c2;

    // Display the result
    c3.display();

    return 0;
}