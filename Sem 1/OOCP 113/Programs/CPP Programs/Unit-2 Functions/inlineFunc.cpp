#include <iostream>
using namespace std;

inline int squre(int x)
{
    return x * x;
}

int main()
{
    int x;
    cout << "Enter a number: ";
    cin >> x;
    cout << "Squre of " << x << " is " << squre(x) << endl;
    return 0;
}