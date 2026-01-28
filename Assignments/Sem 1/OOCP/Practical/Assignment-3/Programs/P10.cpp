// 10) Consider a class student from which the classes test and sports are derived.
// The class student has the name and rollno of the student. The class test has
// the marks of the internal test and the sports class has the marks of the sports
// test. The class student contains a virtual function display() which are
// implemented in the classes test and sports. Write a program which will take
// relative information and display it using pointer of the base class.
#include <iostream>
#include <string>
using namespace std;

// Base class
class Student
{
protected:
    string name;
    int rollno;

public:
    void read()
    {
        cout << "Enter Student Name: ";
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollno;
        cin.ignore();
    }

    // Virtual function
    virtual void display()
    {
        cout << "Name: " << name << ", Roll No: " << rollno << endl;
    }

    virtual ~Student() {}
};

// Derived class: Test
class Test : public Student
{
    float testMarks;

public:
    void read()
    {
        cout << "\n--- Enter Test Details ---\n";
        Student::read();
        cout << "Enter Internal Test Marks: ";
        cin >> testMarks;
        cin.ignore();
    }

    void display() override
    {
        cout << "\n--- Test Result ---\n";
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollno << endl;
        cout << "Internal Test Marks: " << testMarks << endl;
    }
};

// Derived class: Sports
class Sports : public Student
{
    float sportsMarks;

public:
    void read()
    {
        cout << "\n--- Enter Sports Details ---\n";
        Student::read();
        cout << "Enter Sports Marks: ";
        cin >> sportsMarks;
        cin.ignore();
    }

    void display() override
    {
        cout << "\n--- Sports Result ---\n";
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollno << endl;
        cout << "Sports Marks: " << sportsMarks << endl;
    }
};

// Main function
int main()
{
    Student *ptr; // Base class pointer
    Test t;
    Sports s;

    cout << "Enter details for Test Student:\n";
    t.read();

    cout << "\nEnter details for Sports Student:\n";
    s.read();

    cout << "\n==============================\n";
    cout << "Displaying Details using Base Pointer\n";
    cout << "==============================\n";

    ptr = &t;
    ptr->display(); // Calls Test::display()

    ptr = &s;
    ptr->display(); // Calls Sports::display()

    return 0;
}

// output
// Enter details for Test Student:
// --- Enter Test Details ---
// Enter Student Name: Darshan
// Enter Roll Number: 101
// Enter Internal Test Marks: 88

// Enter details for Sports Student:
// --- Enter Sports Details ---
// Enter Student Name: Raj
// Enter Roll Number: 102
// Enter Sports Marks: 75

// ==============================
// Displaying Details using Base Pointer
// ==============================

// --- Test Result ---
// Name: Darshan
// Roll No: 101
// Internal Test Marks: 88

// --- Sports Result ---
// Name: Raj
// Roll No: 102
// Sports Marks: 75
