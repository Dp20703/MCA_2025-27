#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int age;

public:
    // Default Constructor
    Student()
    {
        name = "Unknown";
        age = 0;
        cout << "Default Constructor called" << endl;
    }

    // Parameterized Constructor
    Student(string n, int a)
    {
        name = n;
        age = a;
        cout << "Parameterized Constructor called" << endl;
    }

    // Display method
    void display()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main()
{
    Student s1;                // Default constructor is called
    Student s2("Darshan", 22); // Parameterized constructor is called

    s1.display();
    s2.display();

    return 0;
}
