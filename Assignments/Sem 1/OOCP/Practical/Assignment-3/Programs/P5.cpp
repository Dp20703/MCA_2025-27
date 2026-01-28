// 5) Create a class student from which the classes test and sports are derived.
// The class student has the name and rollno of the student. The class test has
// the marks of the internal test and the sports class has the marks of the sports
// test. The class student contains a virtual function display() which are
// implemented in the classes test and sports. Write a program which will take
// relative information and display it using pointer of the base class.

#include <iostream>
#include <cstring>
using namespace std;

// ---------------- BASE CLASS ----------------
class Student
{
protected:
    char name[50];
    int rollno;

public:
    void getData()
    {
        cout << "\nEnter Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter Roll No: ";
        cin >> rollno;
    }

    // Virtual function to be overridden in derived classes
    virtual void display()
    {
        cout << "\n--- Student Information ---";
        cout << "\nName: " << name;
        cout << "\nRoll No: " << rollno;
    }

    // Virtual destructor (good practice)
    virtual ~Student() {}
};

// ---------------- DERIVED CLASS 1 ----------------
class Test : public Student
{
    float testMarks;

public:
    void getData()
    {
        Student::getData();
        cout << "Enter Internal Test Marks: ";
        cin >> testMarks;
    }

    void display() override
    {
        cout << "\n--- Test Details ---";
        cout << "\nName: " << name;
        cout << "\nRoll No: " << rollno;
        cout << "\nInternal Test Marks: " << testMarks;
    }
};

// ---------------- DERIVED CLASS 2 ----------------
class Sports : public Student
{
    float sportsMarks;

public:
    void getData()
    {
        Student::getData();
        cout << "Enter Sports Marks: ";
        cin >> sportsMarks;
    }

    void display() override
    {
        cout << "\n--- Sports Details ---";
        cout << "\nName: " << name;
        cout << "\nRoll No: " << rollno;
        cout << "\nSports Marks: " << sportsMarks;
    }
};

// ---------------- MAIN FUNCTION ----------------
int main()
{
    Student *ptr; // Base class pointer

    Test t;
    cout << "\nEnter Test Student Details:";
    t.getData();

    Sports s;
    cout << "\nEnter Sports Student Details:";
    s.getData();

    cout << "\n\n--- DISPLAYING DETAILS USING BASE CLASS POINTER ---";

    ptr = &t;       // Pointing to Test object
    ptr->display(); // Calls Test::display()

    ptr = &s;       // Pointing to Sports object
    ptr->display(); // Calls Sports::display()

    cout << "\n\nProgram ended successfully.\n";
    return 0;
}

// output:

// Enter Test Student Details:
// Enter Name: Darshna
// Enter Roll No: 101
// Enter Internal Test Marks: 88

// Enter Sports Student Details:
// Enter Name: dp
// Enter Roll No: 83
// Enter Sports Marks: 78

// --- DISPLAYING DETAILS USING BASE CLASS POINTER ---
// --- Test Details ---
// Name: arshna
// Roll No: 101
// Internal Test Marks: 88
// --- Sports Details ---
// Name: dp
// Roll No: 83
// Sports Marks: 78

// Program ended successfully.