#include <iostream>
using namespace std;

class Demo
{
public:
    // Constructor
    Demo()
    {
        cout << "Constructor called" << endl;
    }

    // Destructor
    ~Demo()
    {
        cout << "Destructor called" << endl;
    }
};

int main()
{
    cout << "Program started" << endl;
    Demo obj; // Constructor runs here
    cout << "Inside main function" << endl;
    return 0; // Destructor runs here (when obj is destroyed)
}

// ✅ So the flow is:
// Constructor → main() execution → Destructor