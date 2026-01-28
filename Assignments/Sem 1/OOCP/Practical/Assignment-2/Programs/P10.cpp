// 10) Write a template function to make sum of two numbers.

#include <iostream>
using namespace std;

// Template function to add two numbers
template <typename T>
T sum(T a, T b)
{
    return a + b;
}

int main()
{
    // Sum of integers
    int x = 5, y = 10;
    cout << "Sum of integers: " << sum(x, y) << endl;

    // Sum of floats
    float p = 2.5f, q = 4.5f;
    cout << "Sum of floats: " << sum(p, q) << endl;

    // Sum of doubles
    double u = 3.14, v = 1.86;
    cout << "Sum of doubles: " << sum(u, v) << endl;

    return 0;
}
// output

// Sum of integers: 15
// Sum of floats: 7
// Sum of doubles: 5
