// 11) Write a program to generate templates function for swapping values of
// variables and show its use with integer, float and character type of data as
// input.

#include <iostream>
using namespace std;

// Template function to swap two values
template <typename T>
void swapValues(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    // Swapping integers
    int x = 5, y = 10;
    cout << "Before swapping integers: x = " << x << ", y = " << y << endl;
    swapValues(x, y);
    cout << "After swapping integers: x = " << x << ", y = " << y << endl;

    cout << endl;

    // Swapping floats
    float p = 2.5f, q = 4.5f;
    cout << "Before swapping floats: p = " << p << ", q = " << q << endl;
    swapValues(p, q);
    cout << "After swapping floats: p = " << p << ", q = " << q << endl;

    cout << endl;

    // Swapping characters
    char c1 = 'A', c2 = 'Z';
    cout << "Before swapping characters: c1 = " << c1 << ", c2 = " << c2 << endl;
    swapValues(c1, c2);
    cout << "After swapping characters: c1 = " << c1 << ", c2 = " << c2 << endl;

    return 0;
}

// output:
// Before swapping integers: x = 5, y = 10
// After swapping integers: x = 10, y = 5

// Before swapping floats: p = 2.5, q = 4.5
// After swapping floats: p = 4.5, q = 2.5

// Before swapping characters: c1 = A, c2 = Z
// After swapping characters: c1 = Z, c2 = A
