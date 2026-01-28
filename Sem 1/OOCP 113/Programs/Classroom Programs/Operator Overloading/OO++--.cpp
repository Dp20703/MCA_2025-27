// ++ , -- operator overloading..

#include <iostream>
#include <string>

using namespace std;

class Complex
{
    float Real;
    float Imag;

public:
    Complex(float TempReal = 0, float TempImag = 0)
    {
        Real = TempReal;
        Imag = TempImag;
    }
    Complex Add(Complex Comp2)
    {
        float TempReal;
        float TempImag;
        TempReal = Real + Comp2.Real;
        TempImag = Imag + Comp2.Imag;

        return Complex(TempReal, TempImag);
    }
    Complex operator+(Complex Comp2)
    {
        float TempReal;
        float TempImag;
        TempReal = Real + Comp2.Real;
        TempImag = Imag + Comp2.Imag;

        return Complex(TempReal, TempImag);
    }
    Complex operator++() // This is prefix
    {
        Real++;
        return Complex(Real, Imag);
    }
    Complex operator++(int dummy) // This is postfix
    {
        Imag++;
        return Complex(Real, Imag);
    }
    void Display()
    {
        cout << Real << "+ " << Imag << "i \n";
    }
};
int main()
{
    Complex Comp1(10, 20);
    Complex Comp2(20, 30);
    Complex CompResult1, CompResult2;

    CompResult1 = Comp1.Add(Comp2);
    CompResult1.Display();
    CompResult2 = Comp1 + Comp2;
    CompResult2.Display();

    cout << "Post fix.." << endl;
    Comp1++;
    Comp1.Display();
    cout << "Pre fix.." << endl;
    ++Comp2;
    Comp2.Display();
    return 0;
}