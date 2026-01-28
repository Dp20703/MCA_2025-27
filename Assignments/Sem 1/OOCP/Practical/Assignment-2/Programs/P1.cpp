// 1) WAP to use binary operator + add two object of class Numbers having num1
// and num2 as its data members and display result.
#include <iostream>
using namespace std;
class Numbers
{
    int data1;
    int data2;

public:
    Numbers(int d1, int d2) : data1(d1), data2(d2) {}
    Numbers operator+(Numbers &temp)
    {
        return Numbers(this->data1 + temp.data1, this->data2 + temp.data2);
    }
    void display()
    {
        cout << "Sum of numbers " << data1 << "+" << data2 << "=" << data1 + data2 << endl;
    }
};
int main()
{
    Numbers n1(5, 8), n2(5, 10);
    Numbers n3 = n1 + n2;
    n1.display();
    n2.display();
    n3.display();

    return 0;
}

// Output
// Sum of numbers 5+8=13
// Sum of numbers 5+10=15
// Sum of numbers 10+18=28