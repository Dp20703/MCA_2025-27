#include <iostream>
using namespace std;

// Define a class
class Student
{
private: // data members (hidden from outside)
    string name;
    int age;

public: // methods (accessible from outside)
    // Method to set values
    void setData(string n, int a)
    {
        name = n;
        age = a;
    }

    // Method to display values
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Main function
int main()
{
    Student s1;                // create object of class
    s1.setData("Darshan", 21); // set values
    s1.display();              // show values

    return 0;
}
